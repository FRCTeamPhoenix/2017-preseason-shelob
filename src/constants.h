#ifndef SRC_CONSTANTS_H
#define SRC_CONSTANTS_H
#include "WPILib.h"
struct PortAssign
{
        const static uint32_t blDriveMotor = 0;
        const static uint32_t flDriveMotor = 1;
        const static uint32_t frDriveMotor = 2;
        const static uint32_t brDriveMotor = 3;
        const static uint32_t joystick = 0;
        const static uint32_t gamepad = 1;
        const static uint32_t loaderMotor = 4;
        const static uint32_t lightSensor = 8;

};

enum buttonNames
{
   buttonX = 0,
   buttonA = 1,
   buttonB = 2,
   buttonY = 3,
   buttonLB = 4,
   buttonRB = 5,
   triggerLT = 6,
   triggerRT = 7,
   buttonBack = 8,
   buttonStart = 9,
   joystickLeftButton = 10,
   joystickRightButton = 11
};


#endif
