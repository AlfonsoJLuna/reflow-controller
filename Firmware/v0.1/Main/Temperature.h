#ifndef TEMPERATURE_H
#define TEMPERATURE_H


#include <stdint.h>


void    Temperature_Init();

int16_t Temperature_Read_Ambient();
int16_t Temperature_Read_Oven();


#endif
