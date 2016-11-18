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
        const static uint32_t flywheelLeftMotor = 6;
        const static uint32_t flywheelRightMotor = 5;
};
namespace DriveStationConstants
{
    enum buttonNames
    {
         buttonX = 1,
         buttonA = 2,
         buttonB = 3,
         buttonY = 4
    };
};
#endif
