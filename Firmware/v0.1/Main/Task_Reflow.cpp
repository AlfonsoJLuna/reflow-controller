#include "Task_Reflow.h"
#include "Display.h"
#include "Input.h"
#include "State.h"
#include "Temperature.h"
#include "Profile.h"
#include "Output.h"
#include <Arduino.h>


void Task_Reflow()
{
    bool quit = 0;

    uint64_t current_millis = 0;
    uint64_t last_millis_process = 0;
    uint64_t last_millis_temp = 0;
    uint64_t reflow_started_millis = millis();

    Display_Clear();

    Display_Text_Center_Small("REFLOWING...", 1);
    Display_Option_C("CANCEL");

    Display_Axis();

    // Display profile curve
    for (int time = 0; time <= 400; time++)
    {
        Display_Point_Profile(time, Profile_Get_Temp(time));
    }

    while (quit == 0)
    {
        current_millis = millis();

        if (current_millis >= (last_millis_process + 10))
        {
            last_millis_process = current_millis;

            Input_Process();
            Output_Process();

            if (Input_Read_C() == 1)
            {
                State_Set(MENU);
                quit = 1;
            }
        }

        if (current_millis >= (last_millis_temp + 1000))
        {
            last_millis_temp = current_millis;

            int16_t temp = Temperature_Read_Oven();

            Display_Temperature(temp, 3, COLOR_RED);

            Display_Point_Real((current_millis - reflow_started_millis) / 1000, temp);
        }

        if (current_millis >= (reflow_started_millis + 400000))
        {
            State_Set(DONE);
            quit = 1;
        }
    }
}
