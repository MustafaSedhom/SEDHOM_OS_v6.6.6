//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
#include "SEDHOM_Draw_Terminal.h"
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
void SEDHOM_Terminal::change_terminal_colors(Color_t path_color, Color_t command_answer_color, Color_t command_answer_wrong_color, Color_t answer_color, Color_t User_command_color, Color_t Terminal_Background_color, Color_t start_msg_color)
{
    this->path_color = path_color;
    this->command_answer_color = command_answer_color;
    this->command_answer_wrong_color = command_answer_wrong_color;
    this->answer_color = answer_color;
    this->User_command_color = User_command_color;
    this->Terminal_Background_color = Terminal_Background_color;
    this->start_msg_color = start_msg_color;
}
void SEDHOM_Terminal::change_terminal_dimensions(int char_width, int char_height, int x_coordinate, int y_coordinate, int max_characters_in_line, int max_lines_on_screen)
{
    this->char_width = char_width;
    this->char_height = char_height;
    this->x_coordinate = x_coordinate;
    this->y_coordinate = y_coordinate;
    this->max_characters_in_line = max_characters_in_line;
    this->max_lines_on_screen = max_lines_on_screen;
}
void SEDHOM_Terminal::Welcome_Message()
{
    Text({x_coordinate,y_coordinate},"===========================",Terminal_Style.color(start_msg_color));
    y_coordinate += char_height;
    Text({x_coordinate,y_coordinate},"Welcome to SEDHOM Terminal",Terminal_Style.color(start_msg_color));
    y_coordinate += char_height ;
    Text({x_coordinate,y_coordinate},"===========================",Terminal_Style.color(start_msg_color));
    y_coordinate += char_height;
}
void SEDHOM_Terminal::Draw_path()
{
    Text({x_coordinate,y_coordinate},path,Terminal_Style.color(path_color));
}
void SEDHOM_Terminal::Start_New_Terminal()
{
    Welcome_Message();
    Draw_path();
}
void SEDHOM_Terminal::Change_path(char* new_path)
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
}
void SEDHOM_Terminal::Answer_Command(char* answer, bool is_wrong_answer)
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
}
void SEDHOM_Terminal::User_Command(char* command)
{
    Text({x_coordinate + strlen(path) * char_width-10, y_coordinate},command,Terminal_Style.color(User_command_color));
    y_coordinate += char_height;
}
void SEDHOM_Terminal::Clear_Terminal()
{
    y_coordinate = 10;
    SEDHOM_Basic_Shapes::Fill_Screen(Terminal_Background_color);
    Draw_path();
}
void SEDHOM_Terminal::Add_folder_to_path(char* folder_name)
{
    strcat(path, folder_name);
    strcat(path, " -> ");
}
//////////////////////////////////////////////////////
void SEDHOM_Terminal::Draw_Terminal()
{
    Start_New_Terminal();
    User_Command("test");
    Answer_Command("This is a test answer");
    Draw_path();
    User_Command("ls");
    Answer_Command("choose folders<> and files[] => \nDocuments/ \nDownloads/ \nfile.txt \nimage.png \naudio.mp3 \nvideo.mp4");
    Draw_path();
    User_Command("open mustafa.txt");
    Answer_Command("wrong msg file is not exit",true);
    Draw_path();
    User_Command("open SEDHOM");
    Answer_Command("wrong msg Folder is not exit",true);
    Draw_path();
    User_Command("cd Documents");
    Change_path("Root::Home::Documents -> ");
    Draw_path();
    User_Command("mkdir Folder1");
    Answer_Command("Ok");
    Draw_path();
}
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ