#include "Temp.h"
#include "Display.h"
#include <Arduino.h>

#ifndef __USE_MAX6675__
#include <Adafruit_MAX31855.h>
#else
#include <max6675.h>
#endif

#ifndef __USE_MAX6675__
Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);
#else
MAX6675 thermocouple(MAXCLK, MAXCS, MAXDO);
#endif

void Temp_Init()
{
#ifndef __USE_MAX6675__
    if (thermocouple.begin() == 0)
    {
        Display_Text_Center_Small("THERMOCOUPLE ERROR", 0);
    }
#endif
}

int16_t Temp_Read_Ambient()
{
#ifndef __USE_MAX6675__
    double temp_internal = thermocouple.readInternal();

    if (isnan(temp_internal))
    {
        Display_Text_Center_Small("THERMOCOUPLE ERROR", 0);
        return 999;
    }

    return round(temp_internal);
#else
    return 21;
#endif
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
