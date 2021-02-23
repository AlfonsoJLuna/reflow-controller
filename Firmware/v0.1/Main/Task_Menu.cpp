#include "Task_Menu.h"
#include "Configuration.h"
#include "Display.h"
#include "Input.h"
#include "Profile.h"
#include "State.h"
#include "Temperature.h"
#include <Arduino.h>


void Task_Menu()
{
    uint64_t current_millis = 0;
    uint64_t last_millis_menu = 0;
    uint64_t last_millis_temp = 0;

    uint8_t profile_count = constrain(Profile_Get_Count(), 1, 4);
    uint8_t menu_option = 0;

    Display_Clear();

    #ifdef USE_MAX31855
        Display_Text_Center_Small("AMBIENT:", 1);
    #endif

    Display_Text_Center_Small("OVEN:", 4);
    Display_Text_Center_Small("SELECT PROFILE:", 8);

    for (int i = 0; i < profile_count; i++)
    {
        Display_Text_Left_Menu(Profile_Get_Name(i), 10 + i);
    }

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
                if (menu_option < (profile_count - 1))
                {
                    menu_option++;
                    Display_Arrow_Menu(menu_option);
                }
            }
        }

        if (current_millis >= (last_millis_temp + 1000))
        {
            last_millis_temp = current_millis;

            #ifdef USE_MAX31855
                Display_Temperature(Temperature_Read_Ambient(), 2, COLOR_BLUE);
            #endif

            Display_Temperature(Temperature_Read_Oven(), 5, COLOR_RED);
        }
    }

    Profile_Set(menu_option);

    int16_t temp = Temperature_Read_Oven();

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
