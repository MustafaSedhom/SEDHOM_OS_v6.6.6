#ifndef SEDHOM_OS_TIME_H_
#define SEDHOM_OS_TIME_H_
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
#include "../SEDHOM_OS_Settings/SEDHOM_OS_Settings.h"
//""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
class SEDHOM_Time
{
  private:
    //
  public:
    void Stop_Display(int time_milli_second);
    void Wait(int time_milli_second);
    unsigned long Calc_time_micro_second();
    unsigned long Calc_time_milli_second();
};
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

// #include "Settings.h"

// add all functions to this file in future and add RTOS OS for this operating system and make it OS
// // Delay in milliseconds
//  void delay(U_int32_t ms) {
//     U_int32_t start = millis();
//     while ((millis() - start) < ms) {
//         // Optionally, add low-power or yield here
//     }
// }

// // Delay in microseconds
//  void delayMicroseconds(U_int32_t us) {
//     U_int32_t start = micros();
//     while ((micros() - start) < us) {
//         // Busy wait
//     }
// }
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

#endif // !SEDHOM_OS_TIME_H_