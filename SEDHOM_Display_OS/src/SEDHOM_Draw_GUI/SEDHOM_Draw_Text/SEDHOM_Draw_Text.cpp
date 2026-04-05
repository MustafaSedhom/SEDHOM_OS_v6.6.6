//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
#include "SEDHOM_Draw_Text.h"
//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
void SEDHOM_Draw_Text::Char(Coordinate_t coordinate,const SEDHOM_GFXfont* font,Color_t color,char c)
{
    Draw_Char(coordinate.x, coordinate.y, font, color, c);
}
void SEDHOM_Draw_Text::Text(Coordinate_t coordinate,const SEDHOM_GFXfont* font,Color_t color,char* txt)
{
    Draw_String(coordinate.x, coordinate.y, font, color, txt);
}
void SEDHOM_Draw_Text::Text(Coordinate_t coordinate,const char* txt,SEDHOM_Text_Style style)
{
    // Draw_String(coordinate.x, coordinate.y, style.getFont().return_font(), style.getColor(), txt);
    Text(coordinate,style.getFont().return_font(),style.getColor(),txt);
}
void SEDHOM_Draw_Text::Text(Coordinate_t coordinate,const SEDHOM_GFXfont* font,Color_t color,Dynamic val,int float_precision)
{
  Text(coordinate, font, color, val.to_String(float_precision));
}
void SEDHOM_Draw_Text::Text_OverFlow(Coordinate_t coordinate,const SEDHOM_GFXfont* font, Color_t color,char * txt,int number_overFlow,char* overFlow_chars)
{
    char buffer[100]; 
    int txt_len = strlen(txt);
    int overflow_len = strlen(overFlow_chars);
    if(txt_len <= number_overFlow)
    {
        Text(coordinate, font, color, txt);
        return;
    }
    int copy_len = number_overFlow - overflow_len;
    if(copy_len < 0) copy_len = 0;
    strncpy(buffer, txt, copy_len);
    buffer[copy_len] = '\0';
    strcat(buffer, overFlow_chars);
    Text(coordinate, font, color, buffer);
}
//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
