#include "Display.h"
#include "Input.h"
#include "State.h"
#include "Temperature.h"
#include "Output.h"
#include "Task_Boot.h"
#include "Task_Menu.h"
#include "Task_Cooldown.h"
#include "Task_Warmup.h"
#include "Task_Reflow.h"
#include "Task_Done.h"


void setup()
{
    delay(500); // Wait for stabilization

    Input_Init();
    Output_Init();
    Display_Init();
    Temperature_Init();

    State_Set(BOOT);
}

void loop()
{
    switch (State_Get())
    {
       case BOOT:
           Task_Boot();
           break;
       case MENU:
           Task_Menu();
           break;
       case COOLDOWN:
           Task_Cooldown();
           break;
       case WARMUP:
           Task_Warmup();
           break;
       case REFLOW:
           Task_Reflow();
           break;
       case DONE:
           Task_Done();
           break;
       default:
           break;
    }
}
