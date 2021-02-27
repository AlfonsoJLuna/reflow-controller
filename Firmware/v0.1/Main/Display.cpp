#include "Configuration.h"
#include "Display.h"
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>


Adafruit_ST7789 display = Adafruit_ST7789(LCDCS, LCDDC, LCDRST);


void Display_Init()
{
    // Turn display backlight on
    pinMode(LCDBL, OUTPUT);
    digitalWrite(LCDBL, HIGH);

    display.init(240, 320);
    display.fillScreen(COLOR_BLACK);
    display.setTextColor(COLOR_WHITE, COLOR_BLACK);
    display.setTextSize(2);
}

void Display_Clear()
{
    display.fillScreen(COLOR_BLACK);
}

static void Display_Text_Left(char* text, uint8_t row)
{
    display.setCursor(0, row * 20);
    display.setTextColor(COLOR_WHITE, COLOR_BLACK);
    display.print(text);
}

static void Display_Text_Center(char* text, uint8_t row)
{
    int16_t x1, y1;
    uint16_t w, h;

    display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
    display.setCursor(120 - w/2, row * 20);
    display.setTextColor(COLOR_WHITE, COLOR_BLACK);
    display.print(text);
}

static void Display_Text_Right(char* text, uint8_t row)
{
    int16_t x1, y1;
    uint16_t w, h;

    display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
    display.setCursor(239 - w, row * 20);
    display.setTextColor(COLOR_WHITE, COLOR_BLACK);
    display.print(text);
}

void Display_Text_Center_Small(char* text, uint8_t row)
{
    display.setTextSize(2);
    Display_Text_Center(text, row);
}

void Display_Text_Center_Big(char* text, uint8_t row)
{
    display.setTextSize(3);
    Display_Text_Center(text, row);
}

void Display_Text_Left_Menu(char* text, uint8_t row)
{
    display.setTextSize(2);
    display.setCursor(24, row * 20);
    display.setTextColor(COLOR_WHITE, COLOR_BLACK);
    display.print(text);
}

void Display_Arrow_Menu(uint8_t row)
{
    display.setTextSize(2);
    display.setTextColor(COLOR_YELLOW, COLOR_BLACK);

    display.setCursor(0, (0 + 10) * 20);
    display.print(" ");

    display.setCursor(0, (1 + 10) * 20);
    display.print(" ");

    display.setCursor(0, (2 + 10) * 20);
    display.print(" ");

    display.setCursor(0, (3 + 10) * 20);
    display.print(" ");

    display.setCursor(0, (row + 10) * 20);
    display.print(">");
}

void Display_Value(uint16_t number, char unit, uint8_t column, uint8_t row, uint16_t color)
{
    number = constrain(number, 0, 999);

    uint8_t text_width;

    if (number >= 100)
    {
        text_width = 4;
    }
    else if (number >= 10)
    {
        text_width = 3;
        display.fillRect(column - 36, row * 20, 9, 21, COLOR_BLACK);
        display.fillRect(column + 36 - 9, row * 20, 9, 21, COLOR_BLACK);
    }
    else
    {
        text_width = 2;
        display.fillRect(column - 36, row * 20, 18, 21, COLOR_BLACK);
        display.fillRect(column + 36 - 18, row * 20, 18, 21, COLOR_BLACK);
    }

    display.setTextSize(3);
    display.setTextColor(color, COLOR_BLACK);
    display.setCursor(column - (text_width * 18) / 2, row * 20);
    display.print(number);
    display.print(unit);
}

void Display_Option_A(char* text)
{
    display.setTextSize(2);
    Display_Text_Left(text, 15);
}

void Display_Option_B(char* text)
{
    display.setTextSize(2);
    Display_Text_Center(text, 15);
}

void Display_Option_C(char* text)
{
    display.setTextSize(2);
    Display_Text_Right(text, 15);
}

void Display_Graph_Axis()
{
    display.drawLine( 20, 110, 230, 110, COLOR_GREY_DARK);
    display.drawLine( 20, 140, 230, 140, COLOR_GREY_DARK);
    display.drawLine( 20, 170, 230, 170, COLOR_GREY_DARK);
    display.drawLine( 20, 200, 230, 200, COLOR_GREY_DARK);
    display.drawLine( 20, 230, 230, 230, COLOR_GREY_DARK);
    display.drawLine( 20, 260, 230, 260, COLOR_GREY_DARK);

    display.drawLine( 20, 110,  20, 260, COLOR_GREY_DARK);
    display.drawLine( 62, 110,  62, 260, COLOR_GREY_DARK);
    display.drawLine(104, 110, 104, 260, COLOR_GREY_DARK);
    display.drawLine(146, 110, 146, 260, COLOR_GREY_DARK);
    display.drawLine(188, 110, 188, 260, COLOR_GREY_DARK);
    display.drawLine(230, 110, 230, 260, COLOR_GREY_DARK);

    display.setTextSize(1);
    display.setTextColor(COLOR_WHITE, COLOR_BLACK);
    display.setCursor(0, 110 - 4);
    display.print("250");
    display.setCursor(0, 140 - 4);
    display.print("200");
    display.setCursor(0, 170 - 4);
    display.print("150");
    display.setCursor(0, 200 - 4);
    display.print("100");
    display.setCursor(0, 230 - 4);
    display.print(" 50");
    display.setCursor(0, 260 - 4);
    display.print("  0");

    display.setCursor(20 - 3, 266);
    display.print("0");
    display.setCursor(62 - 6, 266);
    display.print("80");
    display.setCursor(104 - 9, 266);
    display.print("160");
    display.setCursor(146 - 9, 266);
    display.print("240");
    display.setCursor(188 - 9, 266);
    display.print("320");
    display.setCursor(230 - 9, 266);
    display.print("400");
}

void Display_Graph_Point(uint16_t time, uint16_t temp, uint16_t color)
{
    uint16_t x = constrain(map(time, 0, 400, 20, 230), 20, 230);
    uint16_t y = constrain(map(temp, 0, 250, 260, 110), 110, 260);
    uint16_t w;

    if (time < 400)
    {
        w = 2;
    }
    else if (time == 400)
    {
        w = 1;
    }

    display.fillRect(x, y, w, 2, color);
}
