#ifndef DEFINES_H
#define DEFINES_H

//<!----------------------Values to set motors speed-------------------------!>
#define maxSpeed 255
#define stop 0
#define brake -60
//<!--------------------------------------------------------------------------!>

//<!----------------------Values to set turbine speed-------------------------!>
#define maxBuoyancy 100
#define minBuoyancy 10
//<!--------------------------------------------------------------------------!>

//<!-------------------------Define ESC pin-----------------------------------!>
#define TURBINE 2
//<!--------------------------------------------------------------------------!>

//<!------------------------Define sonsors pins-------------------------------!>
#define NUM_SENSORS 10
#define THRESHOLD 5000
#define MAX_SENSOR_READING 1023

#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define S7 7
#define S8 8
#define SENSOR_MAP 9
#define SENSOR_STOP 10
   
//<!--------------------------------------------------------------------------!>

//<!-------------------------Define motors pins-------------------------------!>
#define LEFT_MOTOR_PIN_1  10
#define LEFT_MOTOR_PIN_2  11
#define RIGHT_MOTOR_PIN_1 12
#define RIGHT_MOTOR_PIN_2 9
//<!---------------------------------------------------------------------------!>



#endif // DEFINES_H

