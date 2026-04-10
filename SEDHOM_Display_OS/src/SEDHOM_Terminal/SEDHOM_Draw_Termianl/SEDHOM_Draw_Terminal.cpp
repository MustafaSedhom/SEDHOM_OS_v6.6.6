//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
#include "SEDHOM_Draw_Terminal.h"
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ
void SEDHOM_Terminal::Welcome_Message()
{
    Text({x_coordinate,y_coordinate},"===========================",Terminal_Style);
    y_coordinate += char_height;
    Text({x_coordinate,y_coordinate},"Welcome to SEDHOM Terminal",Terminal_Style);
    y_coordinate += char_height ;
    Text({x_coordinate,y_coordinate},"===========================",Terminal_Style);
    y_coordinate += char_height;
}
void SEDHOM_Terminal::Draw_path()
{
    int len = strlen(path);
    int index = 0;
    while (index < len)
    {
        char buffer[max_characters_in_line + 1];
        int i = 0;
        while (i < max_characters_in_line && index < len)
        {
            // handle newline
            if (path[index] == '\n')
            {
                index++;
                break;
            }
            buffer[i++] = path[index++];
        }
        buffer[i] = '\0';
        if (len > max_characters_in_line)
        {
           y_coordinate += char_height;
        }
        Text({x_coordinate, y_coordinate},
             buffer,
             Terminal_Style.color(path_color));
    }
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
        y_coordinate += char_height;
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
void SEDHOM_Terminal::Draw_Terminal()
{
    Start_New_Terminal();
    User_Command("test");
    Answer_Command("This is a test answer");
    Draw_path();
    User_Command("ls -la");
    Answer_Command("total 0\ndirwbr-xr-x  2 user\n group 4096 bbg bh gbh gd0 eei dd dd djd ddbdhd dhbdhb jdndjd ");
    Draw_path();
    User_Command("ls -la");
    Answer_Command("wrong msg file is not exit",true);
    Draw_path();
    User_Command("ls -la");
    Answer_Command("wrong msg file is not exit");
    Draw_path();
    User_Command("ls -la");
    Answer_Command("wrong msg file is not exit",true);
    Change_path("Root::Home::Documents -> ");
    Draw_path();
    User_Command("ls -la");
    Answer_Command("wrong msg file is not exit",true);
    Draw_path();
    User_Command("ls -la");
    Answer_Command("wrong msg file is not exit");
}
//JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ