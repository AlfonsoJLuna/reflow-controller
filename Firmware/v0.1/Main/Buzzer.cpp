#include "Buzzer.h"
#include "Configuration.h"
#include <stdbool.h>
#include <Arduino.h>


static bool output = 0;
static bool output_next = 0;

static uint64_t period_start_millis = 0;


void Buzzer_Init()
{
    output = 0;
    output_next = 0;

    pinMode(BUZZ, OUTPUT);
    digitalWrite(BUZZ, LOW);
}

void Buzzer_Process()
{
    uint64_t current_millis = millis();

    if (current_millis >= (period_start_millis + 2000))
    {
        period_start_millis = current_millis;

        output = output_next;
    }
    else
    {
        if (current_millis < (period_start_millis + 1000))
        {
            #if BUZZER_EN
                digitalWrite(BUZZ, output);
            #endif
        }
        else
        {
            digitalWrite(BUZZ, LOW);
        }
    }
}

void Buzzer_Beep()
{
    output_next = true;
}

void Buzzer_Silent()
{
    output_next = false;
}
