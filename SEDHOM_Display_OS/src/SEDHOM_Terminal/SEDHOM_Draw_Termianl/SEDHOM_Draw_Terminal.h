//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
#ifndef SEDHOM_DRAW_TERMINAL_H
#define SEDHOM_DRAW_TERMINAL_H
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
#include "../../SEDHOM_Draw_GUI/SEDHOM_Draw_Text/SEDHOM_Draw_Text.h"
#include "../../SEDHOM_Draw_GUI/SEDHOM_Basic_Shapes/SEDHOM_Basic_Shapes.h"
#include "../../SEDHOM_Utilits/SEDHOM_Data_Types/SEDHOM_Data_Types.h"
#include "../../SEDHOM_Draw_GUI/SEDHOM_Draw_Text/SEDHOM_Text_Style/SEDHOM_Style_of_Text/SEDHOM_Text_Style.h"
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
class SEDHOM_Terminal : private SEDHOM_Draw_Text , private SEDHOM_Font_definations , private SEDHOM_Text_Style
{
    private:
        ///////// terminal private settings //////////
        SEDHOM_Font_definations Fonts;
        const char start_folder_path[6] = "Root";
        const char separator_path[6] = "::";
        const char end_path[6] = " -> ";
        const char command_answer_char[6] = "$$$?";
        char path[300] = "";
        int path_length_after_wraping = 0;
        bool is_path_wrapped = false;
        ///////// terminal settings //////////
        // terminal dimensions
        int char_width = 12;
        int char_height = 16;
        int start_x_coordinate = 10;
        int start_y_coordinate = 20;
        int x_coordinate = start_x_coordinate;
        int y_coordinate = start_y_coordinate;
        int max_characters_in_line = 35;
        int max_lines_on_screen = 19;
        // terminal colors
        Color_t path_color = Color_Orange;
        Color_t command_answer_color = Color_White;
        Color_t command_answer_wrong_color = Color_Red;
        Color_t answer_color = Color_Blue;
        Color_t User_command_color = Color_Green;
        Color_t Terminal_Background_color = Color_Black;
        Color_t start_msg_color = Color_Magenta;
        // private functions
        void Init_path();
        void Welcome_Message();
    public:
        SEDHOM_Text_Style Terminal_Style = SEDHOM_Text_Style().font(Fonts.Mono(Font_Size_Small)).color(Color_Green);
        // settings functions
        void Change_terminal_colors(Color_t path_color = Color_Orange,Color_t command_answer_color = Color_White,Color_t command_answer_wrong_color = Color_Red,Color_t answer_color = Color_Blue,Color_t User_command_color = Color_Green,Color_t Terminal_Background_color = Color_Black,Color_t start_msg_color = Color_Magenta);
        void Change_terminal_dimensions(int char_width = 12,int char_height = 16,int start_x_coordinate = 10,int start_y_coordinate = 10,int max_characters_in_line = 35,int max_lines_on_screen = 19);
        void Change_Terminal_Settings(char* start_folder_path = (char*)"Root",char* separator_path = (char*)"::",char* end_path = (char*)" -> ",char* command_answer_char = (char*)"$$$?");
        //Terminal functions
        void Init_Terminal();
        void Clear_Terminal();
        void Draw_path();
        void Change_all_path(char* new_path);
        void Add_folder_to_path(char* folder_name);
        void Remove_folder_from_path();
        void User_Command(char* command);
        void Answer_Command(char* answer, bool is_wrong_answer = false);
};


//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
#endif // !SEDHOM_DRAW_TERMINAL_H
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ