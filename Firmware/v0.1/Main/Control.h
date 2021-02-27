#ifndef CONTROL_H
#define CONTROL_H


#include <stdint.h>


void    Control_PID_Reset();
uint8_t Control_PID_Run(uint16_t TargetTemp, uint16_t ActualTemp);


#endif
