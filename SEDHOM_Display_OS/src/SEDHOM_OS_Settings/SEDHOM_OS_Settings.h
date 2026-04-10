//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
#ifndef SEDHOM_OS_SETTINGS_H_
#define SEDHOM_OS_SETTINGS_H_
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
                                    // include external libraries here
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// =====================================================
// it's not necessary to define it ❌
// =====================================================
// #include <Arduino.h>
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
                                    // Objects from Drivers class
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// objects and variables
// =====================================================
// it's necessary to define it ✅
// =====================================================
// =====================
// === Controller Selection ===
#define CONTROLLER_ARDUINO_UNO
//#define CONTROLLER_ESP32
//#define CONTROLLER_STM32
//#define CONTROLLER_RPI_PICO

// =====================
// === Screen Selection ===
#define USE_MCUFRIEND
//#define USE_ILI9341
//#define USE_ST7735

// =====================
// === Touch Selection ===
#define USE_ADAFRUIT_TOUCH
//#define USE_RESISTIVE_TOUCH

//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
                                    // Objects from Drivers class
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// =====================================================
// it's necessary to define it ✅
// =====================================================
#if defined(USE_MCUFRIEND)
#include <MCUFRIEND_kbv.h>
#define TFT_DRIVER MCUFRIEND_kbv
#elif defined(USE_ILI9341)
#include <Adafruit_ILI9341.h>
#define TFT_DRIVER Adafruit_ILI9341
#elif defined(USE_ST7735)
#include <Adafruit_ST7735.h>
#define TFT_DRIVER Adafruit_ST7735
#endif
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
                                    // Objects from Drivers class
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// =====================================================
// it's necessary to define it ✅
// =====================================================
// // === Touch Includes ===
// #if defined(USE_ADAFRUIT_TOUCH)
// #include <TouchScreen.h>
// #define TOUCH_DRIVER TouchScreen
// #elif defined(USE_RESISTIVE_TOUCH)
// #include <TouchScreen.h>
// #define TOUCH_DRIVER TouchScreen
// #endif
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
                                    // Mcu Selection Types
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// =====================================================
// it's not necessary to define it ❌
// =====================================================
#if defined(CONTROLLER_ARDUINO_UNO)
#define MCU "Arduino UNO"
#elif defined(CONTROLLER_ESP32)
#define MCU "ESP32"
#elif defined(CONTROLLER_STM32)
#define MCU "STM32"
#elif defined(CONTROLLER_RPI_PICO)
#define MCU "Raspberry Pi Pico"
#endif
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
                                    // Objects from Drivers class
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// =====================================================
// it's necessary to define it ✅
// =====================================================
// Display object
inline TFT_DRIVER Display_Object;

// // Touch object
// #if defined(USE_ADAFRUIT_TOUCH) || defined(USE_RESISTIVE_TOUCH)
// inline TOUCH_DRIVER ts;
// #endif
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
                                    // Display functions from Drivers
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// =====================================================
// it's necessary to define it ✅
// =====================================================
// Screen init function
inline void SEDHOM_Screen_Init()
{
    // Display_Object.begin();
    Display_Object.begin(Display_Object.readID());
}
// Screen init function
inline void SEDHOM_Screen_Rotation(uint8_t rotation)
{
    Display_Object.setRotation(rotation); 
}
// screen height
inline int SEDHOM_Screen_Height()
{
    return Display_Object.height(); // 480
}                                 
// screen width
inline int SEDHOM_Screen_Width()
{
    return Display_Object.width(); // 320
}
// Draw a pixel
inline void SEDHOM_Draw_Pixel(int16_t x, int16_t y, uint16_t color)
{
    Display_Object.drawPixel(x, y, color);
}
// Fill screen
inline void SEDHOM_Fill_Screen(uint16_t color)
{
    Display_Object.fillScreen(color);
}
inline void SEDHOM_Set_Address_Window(int16_t x, int16_t y, int16_t w, int16_t h)
{
    Display_Object.setAddrWindow(x, y, w, h);
}
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
                                    // Touch functions from Drivers
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// =====================================================
// it's necessary to define it ✅
// =====================================================
// // Touch abstraction
// #if defined(USE_ADAFRUIT_TOUCH) || defined(USE_RESISTIVE_TOUCH)
// TSPoint SEDHOM_GetTouchPoint()
// {
//     return ts.getPoint();
// }
// #endif
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
                                    // time functions from MCU Drivers
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
// =====================================================
// it's necessary to define it ✅
// =====================================================
#if defined(CONTROLLER_ARDUINO_UNO)
    #define OS_MICROS() micros()
    #define OS_DELAY(x) delay(x)
#elif defined(CONTROLLER_ESP32)
    #define OS_MICROS() micros()
    #define OS_DELAY(x) delay(x)
#elif defined(CONTROLLER_STM32)
    #define OS_MICROS() HAL_GetTick() * 1000UL
    #define OS_DELAY(x) HAL_Delay(x)
#elif defined(CONTROLLER_RPI_PICO)
    #define OS_MICROS() micros()
    #define OS_DELAY(x) delay(x)
#endif

inline unsigned long SEDHOM_Micros_Time()
{
    return OS_MICROS();
}
inline void SEDHOM_Wait_Time(int time_ms)
{
    OS_DELAY(time_ms);
}
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
                                    // store flash macros from Drivers
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
#ifdef __AVR__
  #include <avr/pgmspace.h>
  #define SEDHOM_PROGMEM           PROGMEM
#elif defined(ESP8266) || defined(ESP32)
  #include <pgmspace.h>
  #define SEDHOM_PROGMEM           
#else
  #define SEDHOM_PROGMEM
#endif

#ifndef pgm_read_byte
#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#endif

#ifndef pgm_read_word
#define pgm_read_word(addr) (*(const unsigned short *)(addr))
#endif

#ifndef pgm_read_dword
#define pgm_read_dword(addr) (*(const unsigned long *)(addr))
#endif

#if !defined(__INT_MAX__) || (__INT_MAX__ > 0xFFFF)
#define pgm_read_pointer(addr) ((void *)pgm_read_dword(addr))
#else
#define pgm_read_pointer(addr) ((void *)pgm_read_word(addr))
#endif
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
#endif // !SEDHOM_OS_SETTINGS_H_
//SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS