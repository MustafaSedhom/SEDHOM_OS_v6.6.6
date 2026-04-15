//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
#include "SEDHOM_Termianl_Do.h"
//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
void SEDHOM_Terminal::Init_Terminal_commands()
{
    Draw_Init_Terminal();
}
void SEDHOM_Terminal::Clear_commands()
{
    Draw_Clear_Terminal();
}
void SEDHOM_Terminal::Ls_commands(char* command)
{
    Draw_User_Command(command);

    char buffer[128];
    strncpy(buffer, command, sizeof(buffer));
    buffer[127] = '\0';

    char* cmd = strtok(buffer, " ");
    char* arg = strtok(NULL, "");

    if (cmd == NULL || strcmp(cmd, "ls") != 0)
    {
        char answer[64];
        snprintf(answer, sizeof(answer), "Unknown command: %s", command);
        Draw_Answer_Command(answer, true);
        return;
    }

    // ===== ls (default) =====
    if (arg == NULL || strcmp(arg, "") == 0 || strcmp(arg, "-all") == 0)
    {
        Draw_Answer_Command(
            "Folders<> and Files[]:\n"
            "Desktop/\nDocuments/\nDownloads/\nSD Card/\n"
            "file.txt\nimage.png\naudio.mp3\nvideo.mp4"
        );
    }

    else if (strcmp(arg, "-folders") == 0)
    {
        Draw_Answer_Command(
            "Folders only:\nDesktop/\nDocuments/\nDownloads/\nSD Card/"
        );
    }

    else if (strcmp(arg, "-files") == 0)
    {
        Draw_Answer_Command(
            "Files only:\nfile.txt\nimage.png\naudio.mp3\nvideo.mp4"
        );
    }

    else
    {
        char answer[64];
        snprintf(answer, sizeof(answer), "Unknown ls option: %s", arg);
        Draw_Answer_Command(answer, true);
    }
}
void SEDHOM_Terminal::Cd_commands(char* command)
{
    Draw_User_Command(command);
    if (strncmp(command, "cd ", 3) != 0)
    {
        char answer[64];
        snprintf(answer, sizeof(answer), "Unknown cd: %s", command);
        Draw_Answer_Command(answer, true);
        return;
    }
    if (strcmp(command, "cd ..") == 0)
    {
        Draw_Remove_folder_from_path();
    }
    else
    {
        Draw_Add_folder_to_path(command + 3);
    }
}
//DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
