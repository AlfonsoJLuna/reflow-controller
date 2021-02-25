#include "Task_Menu.h"
#include "Configuration.h"
#include "Display.h"
#include "Input.h"
#include "Profile.h"
#include "State.h"
#include "Temperature.h"
#include "Output.h"
#include <Arduino.h>


void Task_Menu()
{
    bool quit = 0;

    uint64_t current_millis = 0;
    uint64_t last_millis_process = 0;
    uint64_t last_millis_temp = 0;

    uint8_t profile_count = constrain(Profile_Get_Count(), 1, 4);
    uint8_t menu_option = 0;

    Output_1_Set(0);
    Output_2_Set(0);

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

    while (quit == 0)
    {
        current_millis = millis();

        if (current_millis >= (last_millis_process + 10))
        {
            last_millis_process = current_millis;

            Input_Process();
            Output_Process();

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

            if (Input_Read_C() == 1)
            {
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

                quit = 1;
            }
        }

        if (current_millis >= (last_millis_temp + 1000))
        {
            last_millis_temp = current_millis;

            #ifdef USE_MAX31855
                Display_Value(Temperature_Read_Ambient(), 'c', 120, 2, COLOR_BLUE);
            #endif

            Display_Value(Temperature_Read_Oven(), 'c', 120, 5, COLOR_RED);
        }
    }
}
