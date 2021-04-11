#include "Output.h"
#include "Configuration.h"
#include <Arduino.h>


static uint8_t output1 = 0;
static uint8_t output2 = 0;

static uint8_t output1_next = 0;
static uint8_t output2_next = 0;

static uint64_t period_start_millis = 0;


void Output_Init()
{
    output1 = 0;
    output2 = 0;

    output1_next = 0;
    output2_next = 0;

    pinMode(OUT1, OUTPUT);
    pinMode(OUT2, OUTPUT);

    digitalWrite(OUT1, LOW);
    digitalWrite(OUT2, LOW);
}

void Output_Process()
{
    uint64_t current_millis = millis();

    if (current_millis >= (period_start_millis + 1000))
    {
        period_start_millis = current_millis;

        output1 = output1_next;
        output2 = output2_next;
    }
    else
    {
        uint8_t current_slice = (current_millis - period_start_millis) / 10; // 0-99

        digitalWrite(OUT1, (output1 > current_slice ? HIGH : LOW));
        digitalWrite(OUT2, (output2 > current_slice ? HIGH : LOW));
    }
}

void Output_1_Set(uint8_t new_value)
{
    output1_next = constrain(new_value, 0, 100);
}

void Output_2_Set(uint8_t new_value)
{
    output2_next = constrain(new_value, 0, 100);
}
