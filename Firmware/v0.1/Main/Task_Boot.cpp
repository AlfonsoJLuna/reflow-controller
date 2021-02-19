#include "Task_Boot.h"
#include "State.h"
#include "Display.h"
#include <Arduino.h>


void Task_Boot()
{
    Display_Clear();

    Display_Text_Center_Small("REFLOW OVEN", 3);
    Display_Text_Center_Small("CONTROLLER", 4);

    Display_Text_Center_Small("FW v0.1", 11);
    
    Display_Text_Center_Small("@AlfonsoJLuna", 13);

    delay(3000);

    State_Set(MENU);
}
