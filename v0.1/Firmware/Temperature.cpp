#include "Configuration.h"
#include "Display.h"
#include "Temperature.h"
#include <Arduino.h>
#include <Adafruit_SPIDevice.h>


Adafruit_SPIDevice spidev(MAXCS, MAXCLK, MAXDO, -1, 1000000);

static uint16_t temp_oven = 0;


void Temperature_Init()
{
    if (spidev.begin() == 0)
    {
        Display_Text_Center_Small("TC INIT ERR", 0);
    }
}

static uint32_t SPI_Read_32()
{
    uint8_t Buffer[4];

    spidev.read(Buffer, 4);

    uint32_t Result = 0;

    Result = Buffer[0];
    Result <<= 8;
    Result |= Buffer[1];
    Result <<= 8;
    Result |= Buffer[2];
    Result <<= 8;
    Result |= Buffer[3];

    return Result;
}

static uint16_t SPI_Read_16()
{
    uint8_t Buffer[2];

    spidev.read(Buffer, 2);

    uint16_t Result = 0;

    Result = Buffer[0];
    Result <<= 8;
    Result |= Buffer[1];

    return Result;
}

uint16_t Temperature_Read_Ambient()
{
    uint16_t temp_ambient = 0;

    #ifdef USE_MAX31855
        uint32_t data = SPI_Read_32();

        // Check the sign
        if (data & 0x8000)
        {
            // Ambient temperature is negative
            temp_ambient = 0;
        }
        else
        {
            // Ambient temperature is positive
            uint16_t temp_11b = (data & 0x7FF0) >> 4;

            // 0.0625°C / LSB
            // temp_11b =    0 -> temperature =   0.0ºC
            // temp_11b =   16 -> temperature =   1.0ºC
            // temp_11b =  400 -> temperature =  25.0ºC
            // temp_11b = 2032 -> temperature = 127.0ºC
            temp_ambient = temp_11b / 16;
        }
    #endif

    #ifdef USE_MAX6675
        // MAX6675 does not provide ambient temperature
        temp_ambient = 0; 
    #endif

    return temp_ambient;
}

uint16_t Temperature_Read_Oven()
{
    #ifdef USE_MAX31855
        uint32_t data = SPI_Read_32();

        // Check if the thermocouple is open
        if (data & 0x1)
        {
            Display_Text_Center_Small("TC OPEN ERR", 0);
        }
        else
        {
            // Check if the thermocouple is shorted to GND
            if (data & 0x2)
            {
                Display_Text_Center_Small("TC GND SHORT ERR", 0);
            }

            // Check if the thermocouple is shorted to VCC
            if (data & 0x4)
            {
                Display_Text_Center_Small("TC VCC SHORT ERR", 0);
            }

            // Check the sign
            if (data & 0x80000000)
            {
                // Oven temperature is negative
                temp_oven = 0;
            }
            else
            {
                // Oven temperature is positive
                uint16_t temp_13b = (data & 0x7FFC0000) >> 18;

                // 0.25°C / LSB
                // temp_13b =    0 -> temperature =    0.0ºC
                // temp_13b =    4 -> temperature =    1.0ºC
                // temp_13b =  100 -> temperature =   25.0ºC
                // temp_13b = 6400 -> temperature = 1600.0ºC
                temp_oven = temp_13b / 4;
            }
        }
    #endif

    #ifdef USE_MAX6675
        uint16_t data = SPI_Read_16();

        // Check if the thermocouple is open
        if (data & 0x4)
        {
            // Display_Text_Center_Small("TC OPEN ERR", 0);
        }

        uint16_t temp_12b = (data & 0x7FF8) >> 3;

        // 0.25ºC / LSB
        // temp_12b =    0 -> temperature =    0.00ºC
        // temp_12b =    4 -> temperature =    1.00ºC
        // temp_12b = 4095 -> temperature = 1023.75ºC
        temp_oven = temp_12b / 4;
    #endif

    SerialUSB.println(temp_oven + TEMP_OFFSET);

    return temp_oven + TEMP_OFFSET;
}
