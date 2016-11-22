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
	const static uint32_t leftPotentiometer = 2;
	const static uint32_t rightPotentiometer = 1;
	const static uint32_t leftArmMotor = 7;
	const static uint32_t rightArmMotor = 8;
	const static uint32_t leftLowerLimit = 4;
	const static uint32_t leftUpperLimit = 5;
	const static uint32_t rightLowerLimit = 6;
	const static uint32_t rightUpperLimit = 7;
	const static uint32_t loaderMotor = 4;
	const static uint32_t lightSensor = 8;
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

enum buttonjNames
{
	// This is for joystick
	trigger = 1,
	button2 = 2
};
};


struct RobotConstants {
	constexpr static const float maxSaftLimitLeft = 3.50f;
	constexpr static const float maxSaftLimitRight = 3.30f;
	constexpr static const float minSaftLimitLeft = 1.46f;
	constexpr static const float minSaftLimitRight = 1.46f;
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
	joystickRightButton = 11,
//	// This is for joystick
//	button1 = 1
};

#endif
