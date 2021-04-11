#ifndef OUTPUT_H
#define OUTPUT_H


#include <stdint.h>


void Output_Init();
void Output_Process();
void Output_1_Set(uint8_t new_value); // 0-100%
void Output_2_Set(uint8_t new_value); // 0-100%


#endif
