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
void SEDHOM_Draw_Text::Text(Coordinate_t coordinate,const SEDHOM_GFXfont* font,Color_t color,Dynamic val,int float_precision)
{
  Text(coordinate, font, color, val.to_String(float_precision));
}
//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
