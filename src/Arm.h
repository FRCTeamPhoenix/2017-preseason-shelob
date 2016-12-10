/*
 * Arm.h
 *
 *  Created on: Nov 3, 2016
 *      Author: joshcal
 */

#ifndef SRC_ARM_H_
#define SRC_ARM_H_
#include "WPILib.h"
#include "constants.h"

class Arm
{
private:
	AnalogInput * m_leftPotentiometer;
	AnalogInput * m_rightPotentiometer;
	DigitalInput * m_leftLowerLimit;
	DigitalInput * m_leftUpperLimit;
	DigitalInput * m_rightLowerLimit;
	DigitalInput * m_rightUpperLimit;
	Talon * m_leftArmMotor;
	Talon * m_rightArmMotor;
	Joystick * m_gamepad;
	Joystick * m_armJoystick;


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

	void run(); // Arm Controller with state switches
	float getRightAngle(); // Angles of right arm
	float getLeftAngle(); // Angles of left arm
	void getGamepadWithDeadzone(); // Controller input more reasonable.
	void logVoltage(); // Voltage
	bool checkLowerLimit(); // Limit check Down
	bool checkUpperLimit(); // Limit check Up
	void setState(); // Change state
	void stop(); // Stop the robot
	void putDown(); // Puts the arms down to the bottom
	void rUp(); // moves the right arm up
	void rDown(); // moves the right arm down
	void lUp(); // moves the left arm up
	void lDown(); // moves the left arm down
	bool touchedTop(); // if arm touches top
	bool touchedBottom(); // if arm touches bottom



	bool getArmJoystickButton(int); // Joystick Button

	// State controller for the state of the Arm
	enum state
	{
		Joystick_Control,
		Button_Control,
		Idle
	};

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
	bool m_armButton[5];



};

#endif /* SRC_ARM_H_ */
