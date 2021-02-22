#ifndef PROFILE_H
#define PROFILE_H

#include "Configuration.h"
#include <stdint.h>


uint8_t Profile_Get_Count();

void Profile_Set(uint8_t profile);

char* Profile_Get_Name();

uint16_t Profile_Get_Temp(uint16_t time);


#endif
