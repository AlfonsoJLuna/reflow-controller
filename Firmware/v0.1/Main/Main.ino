#include "Configuration.h"
#include "Input.h"
#include "Display.h"
#include "Temp.h"
#include "State.h"
#include "Task_Boot.h"
#include "Task_Menu.h"
#include "Task_Cooldown.h"
#include "Task_Warmup.h"
#include "Task_Reflow.h"
#include "Task_Done.h"


// Buzzer and relay outputs
// pinMode(BUZZER, OUTPUT);
// pinMode(OUT1, OUTPUT);
// pinMode(OUT2, OUTPUT);


void setup()
{
    // Wait for stabilization
    delay(500);

    Input_Init();
    Display_Init();
    Temp_Init();

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
