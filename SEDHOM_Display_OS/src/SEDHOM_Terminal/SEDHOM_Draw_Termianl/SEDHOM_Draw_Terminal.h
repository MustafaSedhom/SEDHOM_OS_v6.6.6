//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
#ifndef SEDHOM_DRAW_TERMINAL_H
#define SEDHOM_DRAW_TERMINAL_H
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
#include "../SEDHOOM_Terminal_Process/SEDHOM_Termianl_Do.h"
#include "../../SEDHOM_Draw_GUI/SEDHOM_Draw_Text/SEDHOM_Draw_Text.h"
#include "../../SEDHOM_Draw_GUI/SEDHOM_Basic_Shapes/SEDHOM_Basic_Shapes.h"
#include "../../SEDHOM_Utilits/SEDHOM_Data_Types/SEDHOM_Data_Types.h"
#include "../../SEDHOM_Utilits/SEDHOM_Math/SEDHOM_Math.h"
#include "../../SEDHOM_Draw_GUI/SEDHOM_Draw_Text/SEDHOM_Text_Style/SEDHOM_Style_of_Text/SEDHOM_Text_Style.h"
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
class SEDHOM_Terminal : private SEDHOM_Draw_Text , private SEDHOM_Basic_Shapes , 
                        private SEDHOM_Font_definations , private SEDHOM_Math , private SEDHOM_Text_Style
{
    private:
        int char_width = 12;
        int char_height = 16;
        int x_coordinate = 10;
        int y_coordinate = 10;
        int max_characters_in_line = 35;
        int max_lines_on_screen = 19;
        SEDHOM_Font_definations Fonts;
        char path[300] = "Root::Home -> ";
        Color_t path_color = Color_Orange;
        Color_t command_answer_color = Color_White;
        Color_t command_answer_wrong_color = Color_Red;
        Color_t answer_color = Color_Blue;
        Color_t User_command_color = Color_Green;
        const char command_answer_char[6] = "$$$?";
        // functions
        void Welcome_Message();
        void Start_New_Terminal();
        void Answer_Command(char* answer, bool is_wrong_answer = false);
        void User_Command(char* command);
        void Draw_path();
        void Change_path(char* new_path);
    public:
        SEDHOM_Text_Style Terminal_Style = SEDHOM_Text_Style().font(Fonts.Mono(Font_Size_Small)).color(Color_Green);
        // functions
        void Draw_Terminal();
};


//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
#endif // !SEDHOM_DRAW_TERMINAL_H
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ