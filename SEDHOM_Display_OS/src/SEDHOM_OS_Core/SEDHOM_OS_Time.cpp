//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#include "SEDHOM_OS_Time.h"
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
// define all functions
void SEDHOM_Time::Wait(int time_milli_second)
{
    SEDHOM_Wait_Time(time_milli_second);
}
void SEDHOM_Time::Stop_Display(int time_milli_second)
{
    Wait(time_milli_second);
}
unsigned long SEDHOM_Time::Calc_time_micro_second()
{
    return SEDHOM_Micros_Time();
}
unsigned long SEDHOM_Time::Calc_time_milli_second()
{
    return Calc_time_micro_second() / 1000UL;
}
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""