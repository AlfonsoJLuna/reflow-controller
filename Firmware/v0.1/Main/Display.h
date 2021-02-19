#ifndef DISPLAY_H
#define DISPLAY_H


#include <stdint.h>


#define COLOR_BLACK      0x0000
#define COLOR_BLUE       0x001F
#define COLOR_RED        0xF800
#define COLOR_GREEN      0x07E0
#define COLOR_CYAN       0x07FF
#define COLOR_MAGENTA    0xF81F
#define COLOR_YELLOW     0xFFE0 
#define COLOR_WHITE      0xFFFF
#define COLOR_GREY_DARK  0x3186
#define COLOR_GREY_LIGHT 0x528A


void Display_Init();
void Display_Clear();

void Display_Text_Center_Small(char* text, uint8_t row);
void Display_Text_Center_Big(char* text, uint8_t row);

void Display_Text_Left_Menu(char* text, uint8_t row);

void Display_Arrow_Menu(uint8_t row);

void Display_Temperature(int16_t number, uint8_t row, uint16_t color);

void Display_Option_A(char* text);
void Display_Option_B(char* text);
void Display_Option_C(char* text);

void Display_Axis();
void Display_Point_Real(uint16_t time, int16_t temp);
void Display_Point_Profile(uint16_t time, int16_t temp);


#endif
