#ifndef TEMP_H
#define TEMP_H


#include <stdint.h>


void Temp_Init();

int16_t Temp_Read_Ambient();
int16_t Temp_Read_Oven();


#endif
