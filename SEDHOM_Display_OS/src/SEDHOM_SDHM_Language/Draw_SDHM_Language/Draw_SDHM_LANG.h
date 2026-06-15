# pragma once
///////////////////////////////
#include "../../SEDHOM_Draw_GUI/SEDHOM_Draw_Text/SEDHOM_Draw_Text.h"
#include "../../SEDHOM_Draw_GUI/SEDHOM_Draw_Text/SEDHOM_Text_Style/SEDHOM_Style_of_Text/SEDHOM_Text_Style.h"
//////////////////////////////
class SEDHOM_Draw_SDHM_Lang:private SEDHOM_Draw_Text,private SEDHOM_Text_Style
{
    private:
    SEDHOM_Text_Style Text_Style;
    SEDHOM_Draw_Text Text;
    Coordinate_t _start = {10,0};
    int _skip_step_y = 20 ;
        struct TokenInfo
        {
            const char* Text;
            Color_t Color;
        };

        TokenInfo Language[50] =
        {
            // init lang
            {"SYSTEM",      Color_Cyan},
            {"SDHM",      Color_Cyan},
            {"LANG",    Color_Cyan},
            // Commands
            {"SMov",      Color_Cyan},
            {"DMov",      Color_Cyan},
            {"TMov",      Color_Cyan},
            {"Turn",      Color_Cyan},
            {"Wait",      Color_Cyan},
            {"Go",        Color_Cyan},
            {"Set",        Color_Cyan},

            // Units
            {"Deg",       Color_Cyan},
            {"Rad",       Color_Cyan},
            {"Sec",       Color_Cyan},
            {"Min",       Color_Cyan},
            {"Hour",      Color_Cyan},
            {"MSec",      Color_Cyan},
            {"USec",      Color_Cyan},

            // Parameters
            {"+",         Color_Green},
            {"-",         Color_Red},
            {"ON",        Color_Green},
            {"OFF",       Color_Red},
            {"RUN",        Color_Green},
            {"STOP",       Color_Red},
            {"ALL",       Color_Cyan},

            // Loops
            {"StartLoop", Color_Cyan},
            {"EndLoop",   Color_Cyan},
            {">>>",       Color_Orange},

            // Comments
            {"Comment",   Color_Green},
            {"???",       Color_Green},

            // Symbols
            {"!",         Color_White},
            {":",         Color_Blue},
            {"$",         Color_Orange},
            {"%",         Color_Orange},
        };
        //=============================================================================

        Color_t GetColor(String token);
        //=============================================================================
        void DrawToken(int &x,int y,String token);
        //=============================================================================
    public:
        //=============================================================================
        void init(Coordinate_t start);
        void DrawCommand(Coordinate_t point,String line);
        void DrawCommand(String line);
        //=============================================================================
};