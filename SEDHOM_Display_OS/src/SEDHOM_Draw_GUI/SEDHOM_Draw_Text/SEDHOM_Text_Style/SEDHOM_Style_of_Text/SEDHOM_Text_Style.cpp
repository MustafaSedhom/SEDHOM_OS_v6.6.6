//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#include "SEDHOM_Text_Style.h"
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// functions definitions
SEDHOM_Text_Style& SEDHOM_Text_Style::font(Font font)
{
    if (font.return_font() == nullptr)   
        _font = Default();    
    else
        _font = font;     

    return *this;
}
SEDHOM_Text_Style& SEDHOM_Text_Style::color(Color_t color)
{
    _color = color;
    return *this;
}
//...................................................
// gets
Font SEDHOM_Text_Style::getFont() const
{
    return _font;
}
Color_t SEDHOM_Text_Style::getColor() const
{
    return _color;
}
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
