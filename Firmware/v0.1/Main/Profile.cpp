#include "Profile.h"
#include <Arduino.h>


// All profiles should start with time = 0, temp = 50 and end with time = 400, temp = 50


typedef struct
{
    char name[19];
    uint16_t time[10];
    uint16_t temp[10];
} profile_t;


static profile_t profile0 =
{
    "Sn42/Bi57.6/Ag0.4",

    // Time
    {
        0, 100, 200, 240, 260, 400, 400, 400, 400, 400
    },

    // Temperature
    {
        50, 100, 150, 250, 250, 50, 50, 50, 50, 50
    }
};

static profile_t profile1 =
{
    "Sn63/Pb37",

    // Time
    {
        0, 50, 100, 150, 200, 250, 300, 350, 400, 400
    },

    // Temperature
    {
        50, 200, 50, 100, 50, 250, 50, 150, 50, 50
    }
};

static profile_t profile2 =
{
    "Sn96.5/Ag3/Cu0.5",

    // Time
    {
        0, 50, 100, 150, 200, 250, 300, 350, 400, 400
    },

    // Temperature
    {
        50, 50, 200, 200, 50, 50, 200, 200, 50, 50
    }
};

static profile_t* profile_list[] = 
{
    &profile0,
    &profile1,
    &profile2
};

static uint8_t profile_count = sizeof(profile_list) / sizeof(profile_t*);

static profile_t* current_profile = &profile0;


uint8_t Profile_Get_Count()
{
    return profile_count;
}

char* Profile_Get_Name(uint8_t profile_no)
{
    if (profile_no < profile_count)
    {
        return profile_list[profile_no]->name;
    }
    else
    {
        return profile0.name;
    }  
}

void Profile_Set(uint8_t profile_no)
{
    if (profile_no < profile_count)
    {
        current_profile = profile_list[profile_no];
    }
}

uint16_t Profile_Get_Temp(uint16_t time)
{
    time = constrain(time, 0, 400);

    uint8_t index = 1;

    while (time > current_profile->time[index])
    {
        index++;
    }

    long time_min = current_profile->time[index - 1];
    long time_max = current_profile->time[index];
    long temp_min = current_profile->temp[index - 1];
    long temp_max = current_profile->temp[index];

    long temp = map(time, time_min, time_max, temp_min, temp_max);

    return constrain(temp, 50, 250);
}
