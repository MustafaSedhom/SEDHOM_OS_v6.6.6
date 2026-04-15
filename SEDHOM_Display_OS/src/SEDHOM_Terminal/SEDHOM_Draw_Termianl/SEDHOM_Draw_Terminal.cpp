//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
#include "SEDHOM_Draw_Terminal.h"
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
// private functions
void SEDHOM_Draw_Terminal::Init_path()
{
    strcpy(path, start_folder_path);
    strcat(path, end_path);
}
void SEDHOM_Draw_Terminal::Welcome_Message()
{
    Text({x_coordinate,y_coordinate},"===========================",Terminal_Style.color(start_msg_color));
    y_coordinate += char_height;
    Text({x_coordinate,y_coordinate}," SEDHOM OS Terminal V6.6.6",Terminal_Style.color(start_msg_color));
    y_coordinate += char_height ;
    Text({x_coordinate,y_coordinate},"===========================",Terminal_Style.color(start_msg_color));
    y_coordinate += char_height;
}
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
// public functions
void SEDHOM_Draw_Terminal::Change_terminal_colors(Color_t path_color, Color_t command_answer_color, Color_t command_answer_wrong_color, Color_t answer_color, Color_t User_command_color, Color_t Terminal_Background_color, Color_t start_msg_color)
{
    this->path_color = path_color;
    this->command_answer_color = command_answer_color;
    this->command_answer_wrong_color = command_answer_wrong_color;
    this->answer_color = answer_color;
    this->User_command_color = User_command_color;
    this->Terminal_Background_color = Terminal_Background_color;
    this->start_msg_color = start_msg_color;
}
void SEDHOM_Draw_Terminal::Change_terminal_dimensions(int char_width, int char_height, int start_x_coordinate, int start_y_coordinate, int max_characters_in_line, int max_lines_on_screen)
{
    this->char_width = char_width;
    this->char_height = char_height;
    this->x_coordinate = start_x_coordinate;
    this->y_coordinate = start_y_coordinate;
    this->max_characters_in_line = max_characters_in_line;
    this->max_lines_on_screen = max_lines_on_screen;
}
void SEDHOM_Draw_Terminal::Change_Terminal_Settings(char* start_folder_path, char* separator_path, char* end_path, char* command_answer_char)
{
    strcpy(this->start_folder_path, start_folder_path);
    strcpy(this->separator_path, separator_path);
    strcpy(this->end_path, end_path);
    strcpy(this->command_answer_char, command_answer_char);
    Init_path();
}
void SEDHOM_Draw_Terminal::Draw_Init_Terminal()
{
    Draw_Clear_Terminal();
    Init_path();
    Welcome_Message();
    Draw_path();
}
void SEDHOM_Draw_Terminal::Draw_path()
{
    int len = strlen(path);
    int index = 0;
    int line = 0;
    while (index < len)
    {
        char buffer[max_characters_in_line+5 + 1];

        int i = 0;
        while (i < max_characters_in_line+5 && index < len)
        {
            buffer[i++] = path[index++];
        }

        buffer[i] = '\0';
       y_coordinate += line * char_height;
        Text({x_coordinate, y_coordinate},
             buffer,
             Terminal_Style.color(path_color));

        line++;
    }
}
void SEDHOM_Draw_Terminal::Draw_Change_all_path(char* new_path)
{
    int len = strlen(new_path);
    int index = 0;

    while (index < len)
    {
        char buffer[max_characters_in_line + 1];
        int i = 0;

        while (i < max_characters_in_line && index < len)
        {
            if (new_path[index] == '\n')
            {
                index++;
                break;
            }

            buffer[i++] = new_path[index++];
        }
        buffer[i] = '\0';
    }
    strcpy(path, new_path);
    Draw_path();
}
void SEDHOM_Draw_Terminal::Draw_Answer_Command(char* answer, bool is_wrong_answer)
{
    int len = strlen(answer);
    int index = 0;
    while (index < len)
    {
        Text({x_coordinate, y_coordinate},
             command_answer_char,
             Terminal_Style.color(command_answer_color));
        int prefix_width = strlen(command_answer_char) * char_width;
        char buffer[max_characters_in_line + 1];
        int i = 0;
        while (i < max_characters_in_line && index < len)
        {
            if (answer[index] == '\n')
            {
                index++;  
                break;     
            }
            buffer[i++] = answer[index++];
        }
        buffer[i] = '\0';
        Text({x_coordinate + prefix_width, y_coordinate},
             buffer,
             Terminal_Style.color(
                 is_wrong_answer ? command_answer_wrong_color : answer_color));
        y_coordinate += char_height;
    }
    Draw_path();
}
void SEDHOM_Draw_Terminal::Draw_User_Command(char* command)
{
    int x_offset = strlen(path) * char_width-10;
    int y_offset = y_coordinate;
    if(strlen(path)>max_characters_in_line-5)
    {
        x_offset = (strlen(path) - max_characters_in_line-5) * char_width-10;
        y_offset = y_coordinate ;
    }
    Text({x_offset, y_offset},command,Terminal_Style.color(User_command_color));
    y_coordinate += char_height;
}
void SEDHOM_Draw_Terminal::Draw_Clear_Terminal()
{
    y_coordinate = start_y_coordinate;
    SEDHOM_Basic_Shapes::Fill_Screen(Terminal_Background_color);
    Draw_path();
}
void SEDHOM_Draw_Terminal::Draw_Add_folder_to_path(char* folder_name)
{
    int len = strlen(path);
    int end_path_len = strlen(end_path);
    if (len >= end_path_len)
    {
        path[len - end_path_len] = '\0';
    }
    if (strlen(path) > 0)
    {
        strcat(path, separator_path);
    }
    strcat(path, folder_name);
    strcat(path, end_path);
    Draw_path();
}
void SEDHOM_Draw_Terminal::Draw_Remove_folder_from_path()
{
    char root_path[300];
    snprintf(root_path, sizeof(root_path), "%s%s", start_folder_path, end_path);
    if (strcmp(path, root_path) == 0)
    {
        Draw_path();
        return;
    }
    int len = strlen(path);
    int end_path_len = strlen(end_path);
    // int separator_path_len = strlen(separator_path);
    if (len >= end_path_len && strcmp(path + len - end_path_len, end_path) == 0)
    {
        path[len - end_path_len] = '\0';
    }
    char* last = nullptr;
    for (char* p = path; *p; p++)
    {
        if (*p == separator_path[0] && *(p + 1) == separator_path[1])
        {
            last = p;
        }
    }
    if (last != nullptr)
    {
        *last = '\0';
    }
    else
    {
        strcpy(path, start_folder_path);
    }
    strcat(path, end_path);
    Draw_path();
}
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ