#ifndef DISPLAY_H
#define DISPLAY_H


#include <stdint.h>


#define COLOR_BLACK      0x0000
#define COLOR_GREY_DARK  0x3186
#define COLOR_GREY_LIGHT 0xCE59
#define COLOR_WHITE      0xFFFF
#define COLOR_BROWN      0x61E7
#define COLOR_RED        0xEA28
#define COLOR_BLUE       0x561A
#define COLOR_YELLOW     0xFEF0 


void Display_Init();
void Display_Clear();

void Display_Text_Center_Small(char* text, uint8_t row);
void Display_Text_Center_Big(char* text, uint8_t row);

void Display_Text_Left_Menu(char* text, uint8_t row);

void Display_Arrow_Menu(uint8_t row);

void Display_Value(uint16_t number, char unit, uint8_t column, uint8_t row, uint16_t color);

void Display_Option_A(char* text);
void Display_Option_B(char* text);
void Display_Option_C(char* text);

void Display_Graph_Axis();
void Display_Graph_Point(uint16_t time, uint16_t temp, uint16_t color);


#endif
