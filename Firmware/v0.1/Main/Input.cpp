#include "Configuration.h"
#include "Input.h"
#include <stdint.h>
#include <Arduino.h>


typedef enum 
{ 
    RELEASED, 
    PRESSED, 
    CONSUMED 
} button_state_t;

static button_state_t a_state = RELEASED;
static button_state_t b_state = RELEASED;
static button_state_t c_state = RELEASED;

static bool a = 0;
static bool b = 0;
static bool c = 0;

static uint64_t last_a_release = 0;
static uint64_t last_b_release = 0;
static uint64_t last_c_release = 0;

static uint64_t last_a_press = 0;
static uint64_t last_b_press = 0;
static uint64_t last_c_press = 0;


void Input_Init()
{
    pinMode(BTNA, INPUT);
    pinMode(BTNB, INPUT);
    pinMode(BTNC, INPUT);
}

// Button debounce
void Input_Process()
{
    uint64_t current_millis = millis();

    // A
    if (digitalRead(BTNA) == 1)
    {
        if (a == 0)
        {
            a = 1;
            last_a_press = current_millis;
        }
    }
    else
    {
        if (a == 1)
        {
            a = 0;
            last_a_release = current_millis;
        }
    }

    if ((a_state == RELEASED) && (a == 1) && (current_millis > (last_a_press + 50)))
    {
        a_state = PRESSED;
    }

    if ((a == 0) && (current_millis > (last_a_release + 50)))
    {
        a_state = RELEASED;
    }

    // B
    if (digitalRead(BTNB) == 1)
    {
        if (b == 0)
        {
            b = 1;
            last_b_press = current_millis;
        }
    }
    else
    {
        if (b == 1)
        {
            b = 0;
            last_b_release = current_millis;
        }
    }

    if ((b_state == RELEASED) && (b == 1) && (current_millis > (last_b_press + 50)))
    {
        b_state = PRESSED;
    }

    if ((b == 0) && (current_millis > (last_b_release + 50)))
    {
        b_state = RELEASED;
    }

    // C
    if (digitalRead(BTNC) == 1)
    {
        if (c == 0)
        {
            c = 1;
            last_c_press = current_millis;
        }
    }
    else
    {
        if (c == 1)
        {
            c = 0;
            last_c_release = current_millis;
        }
    }

    if ((c_state == RELEASED) && (c == 1) && (current_millis > (last_c_press + 50)))
    {
        c_state = PRESSED;
    }

    if ((c == 0) && (current_millis > (last_c_release + 50)))
    {
        c_state = RELEASED;
    }
}

bool Input_Read_A()
{
    bool result = 0;

    if (a_state == PRESSED)
    {
        result = 1;
        a_state = CONSUMED;
    }

    return result;
}

bool Input_Read_B()
{
    bool result = 0;

    if (b_state == PRESSED)
    {
        result = 1;
        b_state = CONSUMED;
    }

    return result;
}

bool Input_Read_C()
{
    bool result = 0;

    if (c_state == PRESSED)
    {
        result = 1;
        c_state = CONSUMED;
    }

    return result;
}
