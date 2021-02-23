#include "Task_Cooldown.h"
#include "Display.h"
#include "Input.h"
#include "State.h"
#include "Temperature.h"
#include <Arduino.h>


void Task_Cooldown()
{
    bool quit = 0;

    uint64_t current_millis = 0;
    uint64_t last_millis_menu = 0;
    uint64_t last_millis_temp = 0;

    Display_Clear();

    Display_Text_Center_Small("TEMP > 50c", 1);
    Display_Text_Center_Small("COOLING DOWN...", 3);

    Display_Option_C("CANCEL");

    while (quit == 0)
    {
        current_millis = millis();

        if (current_millis >= (last_millis_menu + 10))
        {
            last_millis_menu = current_millis;

            Input_Process();

            if (Input_Read_C() == 1)
            {
                quit = 1;
                State_Set(MENU);
            }
        }

        if (current_millis >= (last_millis_temp + 1000))
        {
            last_millis_temp = current_millis;

            int16_t temp = Temperature_Read_Oven();

            Display_Temperature(temp, 5, COLOR_RED);

            if (temp <= 50)
            {
                quit = 1;
                State_Set(REFLOW);
            }
        }
    }
}
