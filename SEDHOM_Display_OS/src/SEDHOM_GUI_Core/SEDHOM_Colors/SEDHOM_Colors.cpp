//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#include "SEDHOM_Colors.h"
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
// colors
Color_t SEDHOM_Colors::set_Color(Color_RGB_t color)
{
    U_int16_t rgb565 = ((color.R & 0xF8) << 8) |
                  ((color.G & 0xFC) << 3) |
                  (color.B >> 3);

   return(rgb565);
}
Color_t SEDHOM_Colors::Set_Hex_Color(U_int16_t Hex_code)
{
    return Hex_code;
}
U_int8_t SEDHOM_Colors::RGB_to_Gray(U_int8_t R, U_int8_t G, U_int8_t B)
{
    return (R*77 + G*150 + B*29) >> 8;
}
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
