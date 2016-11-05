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
		const static uint32_t leftLowerLimit = 999;
		const static uint32_t leftUpperLimit = 1000;
		const static uint32_t rightLowerLimit = 1001;
		const static uint32_t rightUpperLimit = 1002;

};

struct RobotConstants {
	constexpr static const float maxSaftLimitLeft = 3.6;
	constexpr static const float maxSaftLimitRight = 3.68;
	constexpr static const float minSaftLimitLeft = 1.55;
	constexpr static const float minSaftLimitRight = 1.55;
};

enum armButtons {
	buttonBottom = 1,
	buttonCDF = 2,
	buttonMiddle = 3,
	buttonDrawBridge = 4,
	buttonTop = 5
};

#endif

