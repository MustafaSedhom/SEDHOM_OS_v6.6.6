//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
#ifndef SEDHOM_DRAW_TEXT_H_
#define SEDHOM_DRAW_TEXT_H_
//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
#include "../SEDHOM_OS_Settings/SEDHOM_OS_Settings.h"
#include "../SEDHOM_Utilits/SEDHOM_Data_Types/SEDHOM_Data_Types.h"
#include "../SEDHOM_GUI_Core/SEDHOM_GUI_Core.h"
//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
class SEDHOM_Draw_Text : private SEDHOM_GUI_Core
{
    private:
        /* data */
    public:
        void Char(Coordinate_t coordinate,const SEDHOM_GFXfont* font,Color_t color,char c);
        void Text(Coordinate_t coordinate,const SEDHOM_GFXfont* font,Color_t color,char* txt);
        void Text(Coordinate_t coordinate,const SEDHOM_GFXfont* font,Color_t color,Dynamic val,int float_precision = 2);
        void Text_OverFlow(Coordinate_t coordinate,const SEDHOM_GFXfont* font, Color_t color,char * txt,int number_overFlow = 10,char* overFlow_chars = "...");

};
//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
#endif // !SEDHOM_DRAW_TEXT_H_
//TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
