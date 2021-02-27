#include "Control.h"
#include "Configuration.h"
#include <stdbool.h>
#include <Arduino.h>


static const float Ts = 1.0f;

static const float Kp = PID_KP;
static const float Ki = PID_KI;
static const float Kd = PID_KD;

static float LastError = 0;
static float ErrorSum = 0;

static bool IsOutputSaturated = false;


void Control_PID_Reset()
{
    LastError = 0;
    ErrorSum = 0;
    IsOutputSaturated = false;
}

uint8_t Control_PID_Run(uint16_t TargetTemp, uint16_t ActualTemp)
{
    float Error = (float)TargetTemp - (float)ActualTemp;

    // Anti-Windup
    if (IsOutputSaturated == false)
    {
        ErrorSum += (Error * Ts);
    }

    float ErrorDiff = (Error - LastError) / Ts;

    float Up = Kp * Error;
    float Ui = Ki * ErrorSum;
    float Ud = Kd * ErrorDiff;
    float U = Up + Ui + Ud;

    LastError = Error;

    if ((U >= 0) || (U <= 100))
    {
        IsOutputSaturated = false;
    }
    else
    {
        IsOutputSaturated = true;
    }

    uint8_t Output = constrain(round(U), 0, 100);

    return Output;
}
