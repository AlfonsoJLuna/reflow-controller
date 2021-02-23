#ifndef PROFILE_H
#define PROFILE_H


#include <stdint.h>


uint8_t  Profile_Get_Count();
char*    Profile_Get_Name(uint8_t profile_no);
void     Profile_Set(uint8_t profile_no);

uint16_t Profile_Get_Temp(uint16_t time);


#endif
