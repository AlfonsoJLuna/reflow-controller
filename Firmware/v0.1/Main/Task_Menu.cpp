#include "Task_Menu.h"
#include "State.h"
#include "Input.h"
#include "Display.h"
#include "Temp.h"
#include <Arduino.h>


void Task_Menu()
{
    uint64_t current_millis = 0;
    uint64_t last_millis_menu = 0;
    uint64_t last_millis_temp = 0;

    uint8_t menu_option = 0;

    Display_Clear();
#ifndef __USE_MAX6675__
    Display_Text_Center_Small("AMBIENT:", 1);
#endif
    Display_Text_Center_Small("OVEN:", 4);
    Display_Text_Center_Small("SELECT PASTE:", 8);
    Display_Text_Left_Menu("Sn42/Bi57.6/Ag0.4", 10);
    Display_Text_Left_Menu("Sn63/Pb37", 11);
    Display_Text_Left_Menu("Sn96.5/Ag3.0/Cu0.5", 12);

    Display_Option_A("UP");
    Display_Option_B("DOWN");
    Display_Option_C("START");

    Display_Arrow_Menu(menu_option);

    while (Input_Read_C() == 0)
    {
        current_millis = millis();

        if (current_millis >= (last_millis_menu + 10))
        {
            last_millis_menu = current_millis;

            Input_Process();

            if (Input_Read_A() == 1)
            {
                if (menu_option > 0)
                {
                    menu_option--;
                    Display_Arrow_Menu(menu_option);
                }
            }

            if (Input_Read_B() == 1)
            {
                if (menu_option < 2)
                {
                    menu_option++;
                    Display_Arrow_Menu(menu_option);
                }
            }
        }

        if (current_millis >= (last_millis_temp + 1000))
        {
            last_millis_temp = current_millis;
#ifndef __USE_MAX6675__
            Display_Temperature(Temp_Read_Ambient(), 2, COLOR_BLUE);
#endif
            Display_Temperature(Temp_Read_Oven(), 5, COLOR_RED);
        }
    }

    int16_t temp = Temp_Read_Oven();

    if (temp > 55)
    {
        State_Set(COOLDOWN);
    }
    else if (temp < 45)
    {
        State_Set(WARMUP);
    }
    else
    {
        State_Set(REFLOW);
    }
}
