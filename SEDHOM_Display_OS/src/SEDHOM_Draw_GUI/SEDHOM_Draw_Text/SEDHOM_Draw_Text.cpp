//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
#include "SEDHOM_Draw_Text.h"
//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
// private functions definitions
void SEDHOM_Draw_Text::Char(Coordinate_t coordinate,const SEDHOM_GFXfont* font,Color_t color,char c)
{
    Draw_Char(coordinate.x, coordinate.y, font, color, c);
}
void SEDHOM_Draw_Text::Text(Coordinate_t coordinate,const SEDHOM_GFXfont* font,Color_t color,char* txt)
{
    Draw_String(coordinate.x, coordinate.y, font, color, txt);
}
// public functions definitions

const SEDHOM_Text_Style SEDHOM_Draw_Text::Default_Style = SEDHOM_Text_Style().font(Font()).color(Color_Blue);
void SEDHOM_Draw_Text::Text(Coordinate_t coordinate,const char* txt,SEDHOM_Text_Style style)
{
    Text(coordinate,style.getFont().return_font(),style.getColor(),txt);
}
void SEDHOM_Draw_Text::Text(Coordinate_t coordinate,Dynamic val,int float_precision,SEDHOM_Text_Style style)
{
    Text(coordinate,style.getFont().return_font(),style.getColor(),val.to_String(float_precision));
}
void SEDHOM_Draw_Text::Text_OverFlow(Coordinate_t coordinate,char* txt,SEDHOM_Text_Style style,int number_overFlow,char* overFlow_chars)
{
    // number_overFlow -= strlen(overFlow_chars);
    char buffer[100]; 
    int txt_len = strlen(txt);
    int overflow_len = strlen(overFlow_chars);
    if(txt_len <= number_overFlow)
    {
        Text(coordinate,txt,style);
        return;
    }
    int copy_len = number_overFlow - overflow_len;
    if(copy_len < 0) copy_len = 0;
    strncpy(buffer, txt, copy_len);
    buffer[copy_len] = '\0';
    strcat(buffer, overFlow_chars);
    Text(coordinate,buffer,style);
}
//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
