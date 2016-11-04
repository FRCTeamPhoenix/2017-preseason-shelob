/*
 * Arm.h
 *
 *  Created on: Nov 3, 2016
 *      Author: Bryce Czuba
 */

#ifndef SRC_ARM_H_
#define SRC_ARM_H_
#include "WPILib.h"
#include "constants.h"

class Arm {
private:
	Joystick * m_gamepad;
	AnalogInput * m_leftPotentiometer;
	AnalogInput * m_rightPotentiometer;
	DigitalInput * m_leftLowerLimit;
	DigitalInput * m_leftUpperLimit;
	DigitalInput * m_rightLowerLimit;
	DigitalInput * m_rightUpperLimit;
	Talon * m_leftArmMotor;
	Talon * m_rightArmMotor;


public:
	Arm(
			AnalogInput * leftPotentiometer,
				AnalogInput * rightPotentiometer,
				DigitalInput * leftLowerLimit,
				DigitalInput * leftUpperLimit,
				DigitalInput * rightLowerLimit,
				DigitalInput * rightUpperLimit,
				Talon * leftArmMotor,
				Talon * rightArmMotor,
				Joystick * gamepad);

	void run();
	float getRightAngle();
	float getLeftAngle();
	void getGamepadWithDeadzone();
	void setState()
	void stop();

	enum state {
		Joystick_Control,
		Button_Control,
		Idle
	}

	virtual ~Arm();
private:
	state m_state;
	float m_rightAngle;
	float m_leftAngle;
	float m_rightLLimit;
	float m_leftLLimit;
	float m_rightULimit;
	float m_leftULimit;
	float m_gamepadJoystickY;


};

#endif /* SRC_ARM_H_ */
