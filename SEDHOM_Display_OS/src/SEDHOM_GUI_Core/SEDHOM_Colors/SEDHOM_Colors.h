#ifndef SEDHOM_COLORS
#define SEDHOM_COLORS
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#include "../../SEDHOM_OS_Settings/SEDHOM_OS_Settings.h"
#include "../../SEDHOM_Utilits/SEDHOM_Data_Types/SEDHOM_Data_Types.h"
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
typedef U_int16_t Color_t ;
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#define Color_Black               0x0000      /*   0,   0,   0 */
#define Color_White               0xFFFF      /* 255, 255, 255 */
#define Color_Navy                0x000F      /*   0,   0, 128 */
#define Color_DarkGreen           0x03E0      /*   0, 128,   0 */
#define Color_DarkCyan            0x03EF      /*   0, 128, 128 */
#define Color_Maroon              0x7800      /* 128,   0,   0 */
#define Color_Purple              0x780F      /* 128,   0, 128 */
#define Color_Olive               0x7BE0      /* 128, 128,   0 */
#define Color_LightGrey           0xC618      /* 192, 192, 192 */
#define Color_DarkGrey            0x7BEF      /* 128, 128, 128 */
#define Color_Blue                0x001F      /*   0,   0, 255 */
#define Color_Green               0x07E0      /*   0, 255,   0 */
#define Color_Cyan                0x07FF      /*   0, 255, 255 */
#define Color_Red                 0xF800      /* 255,   0,   0 */
#define Color_Magenta             0xF81F      /* 255,   0, 255 */
#define Color_Orange              0xFDA0      /* 255, 180,   0 */
#define Color_GreenYellow         0xB7E0      /* 180, 255,   0 */
#define Color_Pink                0xFC9F      /* 255, 192, 203 */
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
class SEDHOM_Colors
{
    private:
        /* data */
    public:
        // colors
        Color_t set_Color(Color_RGB_t color);
        Color_t Set_Hex_Color(U_int16_t Hex_code); 
        U_int8_t RGB_to_Gray(U_int8_t R, U_int8_t G, U_int8_t B);
};
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
//{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
#endif // !SEDHOM_COLORS