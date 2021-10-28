#include "Configuration.h"
#include "Display.h"
#include "Temperature.h"
#include <Arduino.h>


#ifdef USE_MAX31855
    #include <Adafruit_MAX31855.h>
    Adafruit_MAX31855 thermocouple(MAXCLK, MAXCS, MAXDO);
#endif

#ifdef USE_MAX6675
    #include <max6675.h>
    MAX6675 thermocouple(MAXCLK, MAXCS, MAXDO);
#endif


static double temp_ambient = 0;
static double temp_oven = 0;


void Temperature_Init()
{
    #ifdef USE_MAX31855
        if (thermocouple.begin() == 0)
        {
            Display_Text_Center_Small("TC INIT ERR", 0);
        }
    #endif
}

static void Thermocouple_Error()
{
    uint8_t error_code = thermocouple.readError();

    if (error_code == 0b001)
    {
        Display_Text_Center_Small("TC OPEN ERR", 0);
    }
    else if (error_code == 0b010)
    {
        Display_Text_Center_Small("TC GND SHORT ERR", 0);
    }
    else if (error_code == 0b100)
    {
        Display_Text_Center_Small("TC VCC SHORT ERR", 0);
    }
    else
    {
        Display_Text_Center_Small("TC ERR", 0);
    }
}

uint16_t Temperature_Read_Ambient()
{
    #ifdef USE_MAX31855
        double new_temp_ambient = thermocouple.readInternal();

        if (isnan(new_temp_ambient))
        {
            Thermocouple_Error();
        }
        else
        {
            temp_ambient = new_temp_ambient;
        }

        return constrain(round(temp_ambient), 0, 999);
    #endif

    #ifdef USE_MAX6675
        return 21; // MAX6675 does not provide real ambient temperature
    #endif
}

uint16_t Temperature_Read_Oven()
{
    double new_temp_oven = thermocouple.readCelsius();

    if (isnan(new_temp_oven))
    {
        Thermocouple_Error();
    }
    else
    {
        temp_oven = new_temp_oven;
    }

    SerialUSB.println(temp_oven);

    return constrain(round(temp_oven + TEMP_OFFSET), 0, 999);
}
