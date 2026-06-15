# include "Draw_SDHM_LANG.h"
/////////////////////////////////////////////////////////////////
Color_t SEDHOM_Draw_SDHM_Lang::GetColor(String token)
{
    uint16_t count = sizeof(Language)/sizeof(Language[0]);

    for(uint16_t i=0;i<count;i++)
    {
        if(token == Language[i].Text)
            return Language[i].Color;
    }

    bool isNumber = true;

    for(uint16_t i=0;i<token.length();i++)
    {
        if(!isDigit(token[i]))
        {
            isNumber = false;
            break;
        }
    }

    if(isNumber)
        return Color_Magenta;

    return Color_Yellow;
}
void SEDHOM_Draw_SDHM_Lang::DrawToken(int &x,int y,String token)
{
    Text.Text(
        {x,y},
        token.c_str(),
        Text_Style.color(GetColor(token))
    );

    x += token.length() * 18;
}
void SEDHOM_Draw_SDHM_Lang::DrawCommand(Coordinate_t point,String line)
{
    _start = point;
    // Comment Style 1
    if(line.startsWith("???"))
    {
        Text.Text(
            point,
            line.c_str(),
            Text_Style.color(GetColor("???"))
        );
        return;
    }

    // Comment Style 2
    if(line.startsWith("Comment!"))
    {
        Text.Text(
            point,
            line.c_str(),
            Text_Style.color(GetColor("Comment"))
        );
        return;
    }

    String token = "";

    for(uint16_t i=0;i<line.length();i++)
    {
        char c = line[i];

        if(c=='!' || c==':' || c=='$'|| c=='%')
        {
            if(token.length())
            {
                DrawToken(point.x,point.y,token);
                token="";
            }

            String symbol = String(c);

            DrawToken(point.x,point.y,symbol);

            continue;
        }

        token += c;
    }

    if(token.length())
    {
        DrawToken(point.x,point.y,token);
    }
}
void SEDHOM_Draw_SDHM_Lang::init(Coordinate_t start)
{
    _start = start;

}
void SEDHOM_Draw_SDHM_Lang::DrawCommand(String line)
{
    _start.y += _skip_step_y;
    DrawCommand(_start,line);
}