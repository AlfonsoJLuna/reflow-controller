#ifndef CONFIGURATION_H
#define CONFIGURATION_H


//////////////////////////////////////////////////
// Temperature sensor selection
//////////////////////////////////////////////////


#define USE_MAX31855
// #define USE_MAX6675


//////////////////////////////////////////////////
// Temperature reading offset
//////////////////////////////////////////////////


#define TEMP_OFFSET 0


//////////////////////////////////////////////////
// Pin definitions
//////////////////////////////////////////////////


#define MAXDO   PB14
#define MAXCS   PB12
#define MAXCLK  PB13

#define BUZZ    PA1
#define OUT1    PB6
#define OUT2    PB5

#define BTNA    PB15
#define BTNB    PB1
#define BTNC    PB10

#define LCDDO   PA7
#define LCDCS   PA4
#define LCDCLK  PA5
#define LCDRST  PA3
#define LCDDC   PA2
#define LCDBL   PA6


#endif
