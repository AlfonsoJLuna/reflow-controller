#include "Temp.h"
#include "Display.h"
#include <Arduino.h>
#include <Adafruit_MAX31855.h>


Adafruit_MAX31855 thermocouple(PB13, PB12, PB14);


void Temp_Init()
{
    if (thermocouple.begin() == 0)
    {
        Display_Text_Center_Small("THERMOCOUPLE ERROR", 0);
    }
}

int16_t Temp_Read_Ambient()
{
    double temp_internal = thermocouple.readInternal();

    if (isnan(temp_internal))
    {
        Display_Text_Center_Small("THERMOCOUPLE ERROR", 0);
        return 999;
    }

    return round(temp_internal);
}

int16_t Temp_Read_Oven()
{
    double temp_external = thermocouple.readCelsius();

    if (isnan(temp_external))
    {
        Display_Text_Center_Small("THERMOCOUPLE ERROR", 0);
        return 999;
    }

    return round(temp_external);
}
