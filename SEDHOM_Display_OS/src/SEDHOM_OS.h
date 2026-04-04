//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
#ifndef SEDHOM_OS_H_
#define SEDHOM_OS_H_
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
#include "SEDHOM_OS_Settings/SEDHOM_OS_Settings.h"
#include "SEDHOM_Utilits/SEDHOM_Data_Types/SEDHOM_Data_Types.h"
#include "SEDHOM_Utilits/SEDHOM_Math.h"
#include "SEDHOM_Draw_GUI/SEDHOM_Basic_Shapes.h"
#include "SEDHOM_GUI_Core/SEDHOM_Colors.h"
#include "SEDHOM_OS_Core/SEDHOM_OS_Time.h"
#include "SEDHOM_Draw_GUI/SEDHOM_Draw_Text.h"
#include "SEDHOM_GUI_Core/SEDHOM_English_Fonts.h"
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
SEDHOM_Basic_Shapes Shapes;
SEDHOM_Time Time;
SEDHOM_Colors Colors;
SEDHOM_Draw_Text Text;
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
class SEDHOM_OS
{
  private:
    Color_t OS_Mode;
    // my name is Mustafa SEDHOM i wrote this lib to make easy way to use TFT Display in embedded projects
  public:
    /// define all functions
    void Init_OS(ROTATION_STATUS_t Rotate = Rotate_90_Degree,Color_t Mode = Night_Mode);
    void Restart_OS();
    int Screen_Height();
    int Screen_Width();
    void Fill_Screen(Color_t color = Night_Mode);
    void Set_Mode(Color_t Mode = Night_Mode);
    Color_t Mode();
    Color_t Not_Mode();
    // define all variables
    Color_t Night_mode = Night_Mode ;
    Color_t Light_mode = Light_Mode ;
    ROTATION_STATUS_t Rotate_0 = Rotate_0_Degree; 
    ROTATION_STATUS_t Rotate_90 = Rotate_90_Degree;
    ROTATION_STATUS_t Rotate_180 = Rotate_180_Degree;
    ROTATION_STATUS_t Rotate_270 = Rotate_270_Degree;
};
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// define all functions
void SEDHOM_OS::Init_OS(ROTATION_STATUS_t Rotate,Color_t Mode)
{
  SEDHOM_Screen_Init();
  SEDHOM_Screen_Rotation(Rotate);
  OS_Mode = Mode;
  Set_Mode(Mode);
}
void SEDHOM_OS::Restart_OS()
{
  Init_OS();
}
void SEDHOM_OS::Set_Mode(Color_t Mode)
{
  OS_Mode = Mode;
  Fill_Screen(OS_Mode);
}
Color_t SEDHOM_OS::Mode()
{
  return OS_Mode;
}
Color_t SEDHOM_OS::Not_Mode()
{
  if(OS_Mode == Color_Black) return Color_White;
  else return Color_Black;
}
void SEDHOM_OS::Fill_Screen(Color_t color)
{
  SEDHOM_Fill_Screen(color);
}
int SEDHOM_OS::Screen_Width()
{
  return SEDHOM_Screen_Width();
}
int SEDHOM_OS::Screen_Height()
{
  return SEDHOM_Screen_Height();
}
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
#endif /*SEDHOM_OS_H_*/
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS