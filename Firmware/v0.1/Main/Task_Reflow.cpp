#include "Task_Reflow.h"
#include "Buzzer.h"
#include "Configuration.h"
#include "Control.h"
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

    Display_Graph_Axis();

    // Display profile curve
    for (int time = 0; time <= 400; time++)
    {
        Display_Graph_Point(time, Profile_Get_Temp(time), COLOR_BROWN);
    }

    Control_PID_Reset();

    while (quit == 0)
    {
        current_millis = millis();

        if (current_millis >= (last_millis_process + 10))
        {
            last_millis_process = current_millis;

            Input_Process();
            Output_Process();
            Buzzer_Process();

            if (Input_Read_C() == 1)
            {
                State_Set(MENU);
                quit = 1;
            }
        }

        if (current_millis >= (last_millis_temp + 1000))
        {
            last_millis_temp = current_millis;

            uint16_t time = (current_millis - reflow_started_millis) / 1000;

            uint16_t temp_target = Profile_Get_Temp(time);
            uint16_t temp_oven = Temperature_Read_Oven();

            uint8_t pid_output = Control_PID_Run(temp_target, temp_oven);

            Output_1_Set(pid_output);
            Output_2_Set(pid_output);

            if ((pid_output == 0) && (time > 100) && (temp_oven > (temp_target + 10)))
            {
                Display_Text_Center_Small(" OPEN DOOR! ", 1);
                Buzzer_Beep();
            }
            else
            {
                Buzzer_Silent();
            }

            Display_Value(pid_output, '%', 203, 3, COLOR_YELLOW);
            Display_Graph_Point(time, pid_output, COLOR_YELLOW);

            #ifdef USE_MAX31855
                uint16_t temp_ambient = Temperature_Read_Ambient();
                Display_Value(temp_ambient, 'c', 36, 3, COLOR_BLUE);
                Display_Graph_Point(time, temp_ambient, COLOR_BLUE);
            #endif

            Display_Value(temp_oven, 'c', 120, 3, COLOR_RED);
            Display_Graph_Point(time, temp_oven, COLOR_RED);
        }

        if (current_millis >= (reflow_started_millis + 400000))
        {
            State_Set(DONE);
            quit = 1;
        }
    }
}
