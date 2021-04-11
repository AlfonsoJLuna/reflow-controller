#ifndef TEMPERATURE_H
#define TEMPERATURE_H


#include <stdint.h>


void     Temperature_Init();

uint16_t Temperature_Read_Ambient();
uint16_t Temperature_Read_Oven();


#endif
