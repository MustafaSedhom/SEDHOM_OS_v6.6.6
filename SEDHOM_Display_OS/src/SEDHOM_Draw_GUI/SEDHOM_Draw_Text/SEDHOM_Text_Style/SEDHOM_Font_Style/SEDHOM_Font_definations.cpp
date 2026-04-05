//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
#include "SEDHOM_Font_definations.h"
//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
Font SEDHOM_Font_definations::Default(Font_Size_t size)
{
    switch (size)
    {
        case Font_Size_Small:
            return Font(FONT_Default_SMALL);
        break;
        case Font_Size_Medium:
            return Font(FONT_Default_BIG);
        break;
        case Font_Size_Large:
            return Font(FONT_Default_BIG);
        break;
        case Font_Size_Very_Large:
            return Font(FONT_Default_BIG);
        break;
    }    
}
Font SEDHOM_Font_definations::Sans(Font_Size_t size , Font_Style_t style)
{
    switch (style)
    {
        // Default Font is Sans Font with Regular Style
        case Font_Style_Regular:
            switch (size)
            {
            case Font_Size_Small:
                return Font(FONT_FREESANS_SMALL);
            break;
            case Font_Size_Medium:
                return Font(FONT_FREESANS_MEDIUM);
            break;
            case Font_Size_Large:
                return Font(FONT_FREESANS_BIG);
            break;
            case Font_Size_Very_Large:
                return Font(FONT_FREESANS_VERYBIG);
            break;
            }    
        break;
        // Default Font is Sans Font with Bold Style
        case Font_Style_Bold:
            switch (size)
            {
            case Font_Size_Small:
                return Font(FONT_FREESANSBOLD_SMALL);
            break;
            case Font_Size_Medium:
                return Font(FONT_FREESANSBOLD_MEDIUM);
            break;
            case Font_Size_Large:
                return Font(FONT_FREESANSBOLD_BIG);
            break;
            case Font_Size_Very_Large:
                return Font(FONT_FREESANSBOLD_VERYBIG);
            break;
            }    
        break;
        // Default Font is Sans Font with Italic Style
        case Font_Style_Italic:
            switch (size)
            {
            case Font_Size_Small:
                return Font(FONT_FREESANSOBLIQUE_SMALL);
            break;
            case Font_Size_Medium:
                return Font(FONT_FREESANSOBLIQUE_MEDIUM);
            break;
            case Font_Size_Large:
                return Font(FONT_FREESANSOBLIQUE_BIG);
            break;
            case Font_Size_Very_Large:
                return Font(FONT_FREESANSOBLIQUE_VERYBIG);
            break;
            }    
        break;
        // Default Font is Sans Font with Bold and Italic Style
        case Font_Style_Bold_and_Italic:
            switch (size)
            {
            case Font_Size_Small:
                return Font(FONT_FREESANSOBLIQUE_SMALL);
            break;
            case Font_Size_Medium:
                return Font(FONT_FREESANSOBLIQUE_MEDIUM);
            break;
            case Font_Size_Large:
                return Font(FONT_FREESANSOBLIQUE_BIG);
            break;
            case Font_Size_Very_Large:
                return Font(FONT_FREESANSOBLIQUE_VERYBIG);
            break;
            }    
        break;
    }
}
Font SEDHOM_Font_definations::Serif(Font_Size_t size , Font_Style_t style)
{
    switch (style)
    {
        // Default Font is Serif Font with Regular Style
        case Font_Style_Regular:
            switch (size)
            {
            case Font_Size_Small:
                return Font(FONT_FREESERIF_SMALL);
            break;
            case Font_Size_Medium:
                return Font(FONT_FREESERIF_MEDIUM);
            break;
            case Font_Size_Large:
                return Font(FONT_FREESERIF_BIG);
            break;
            case Font_Size_Very_Large:
                return Font(FONT_FREESERIF_VERYBIG);
            break;
            }    
        break;
        // Default Font is Serif Font with Bold Style
        case Font_Style_Bold:
            switch (size)
            {
            case Font_Size_Small:
                return Font(FONT_FREESERIFBOLD_SMALL);
            break;
            case Font_Size_Medium:
                return Font(FONT_FREESERIFBOLD_MEDIUM);
            break;
            case Font_Size_Large:
                return Font(FONT_FREESERIFBOLD_BIG);
            break;
            case Font_Size_Very_Large:
                return Font(FONT_FREESERIFBOLD_VERYBIG);
            break;
            }    
        break;
        // Default Font is Serif Font with Italic Style
        case Font_Style_Italic:
            switch (size)
            {
            case Font_Size_Small:
                return Font(FONT_FREESERIFITALIC_SMALL);
            break;
            case Font_Size_Medium:
                return Font(FONT_FREESERIFITALIC_MEDIUM);
            break;
            case Font_Size_Large:
                return Font(FONT_FREESERIFITALIC_BIG);
            break;
            case Font_Size_Very_Large:
                return Font(FONT_FREESERIFITALIC_VERYBIG);
            break;
            }    
        break;
        // Default Font is Serif Font with Bold and Italic Style
        case Font_Style_Bold_and_Italic:
            switch (size)
            {
            case Font_Size_Small:
                return Font(FONT_FREESERIFBOLDITALIC_SMALL);
            break;
            case Font_Size_Medium:
                return Font(FONT_FREESERIFBOLDITALIC_MEDIUM);
            break;
            case Font_Size_Large:
                return Font(FONT_FREESERIFBOLDITALIC_BIG);
            break;
            case Font_Size_Very_Large:
                return Font(FONT_FREESERIFBOLDITALIC_VERYBIG);
            break;
            }    
        break;
    }
}
Font SEDHOM_Font_definations::Mono(Font_Size_t size , Font_Style_t style)
{
           switch (style)
    {
        // Default Font is mono Font with Regular Style
        case Font_Style_Regular:
            switch (size)
            {
            case Font_Size_Small:
                return Font(FONT_FREEMONO_SMALL);
            break;
            case Font_Size_Medium:
                return Font(FONT_FREEMONO_MEDIUM);
            break;
            case Font_Size_Large:
                return Font(FONT_FREEMONO_BIG);
            break;
            case Font_Size_Very_Large:
                return Font(FONT_FREEMONO_VERYBIG);
            break;
            }    
        break;
        // Default Font is Serif Font with Bold Style
        case Font_Style_Bold:
            switch (size)
            {
            case Font_Size_Small:
                return Font(FONT_FREEMONOBOLD_SMALL);
            break;
            case Font_Size_Medium:
                return Font(FONT_FREEMONOBOLD_MEDIUM);
            break;
            case Font_Size_Large:
                return Font(FONT_FREEMONOBOLD_BIG);
            break;
            case Font_Size_Very_Large:
                return Font(FONT_FREEMONOBOLD_VERYBIG);
            break;
            }    
        break;
        // Default Font is Serif Font with Italic Style
        case Font_Style_Italic:
            switch (size)
            {
            case Font_Size_Small:
                return Font(FONT_FREEMONOOBLIQUE_SMALL);
            break;
            case Font_Size_Medium:
                return Font(FONT_FREEMONOOBLIQUE_MEDIUM);
            break;
            case Font_Size_Large:
                return Font(FONT_FREEMONOOBLIQUE_BIG);
            break;
            case Font_Size_Very_Large:
                return Font(FONT_FREEMONOOBLIQUE_VERYBIG);
            break;
            }    
        break;
        // Default Font is mono Font with Bold and Italic Style
        case Font_Style_Bold_and_Italic:
            switch (size)
            {
            case Font_Size_Small:
                return Font(FONT_FREEMONOBOLDOBLIQUE_SMALL);
            break;
            case Font_Size_Medium:
                return Font(FONT_FREEMONOBOLDOBLIQUE_MEDIUM);
            break;
            case Font_Size_Large:
                return Font(FONT_FREEMONOBOLDOBLIQUE_BIG);
            break;
            case Font_Size_Very_Large:
                return Font(FONT_FREEMONOBOLDOBLIQUE_VERYBIG);
            break;
            }    
        break;
    }
}
Font SEDHOM_Font_definations::SevenSegment()
{
    return Font(FONT_SEVENSEGMENT);
}
//NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
