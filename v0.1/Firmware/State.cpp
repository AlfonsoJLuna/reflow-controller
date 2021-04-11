#include "State.h"


static state_t state = BOOT;


void State_Set(state_t new_state)
{
    state = new_state;
}

state_t State_Get()
{
    return state;
}
