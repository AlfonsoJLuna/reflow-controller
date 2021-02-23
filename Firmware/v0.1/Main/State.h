#ifndef STATE_H
#define STATE_H


typedef enum 
{ 
    BOOT,
    MENU,
    COOLDOWN,
    WARMUP,
    REFLOW,
    DONE
} state_t;


void    State_Set(state_t new_state);
state_t State_Get();


#endif
