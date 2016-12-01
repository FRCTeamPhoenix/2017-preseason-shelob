/*
 * DriveTrain.h
 *
 *  Created on: Nov 10, 2016
 *      Author: joshua
 */

#include "WPILib.h"
#include "constants.h"

class DriveTrain
{
private:
	float m_joystickY;
	float m_joystickZ;
	float m_joystickThrottle;

	Talon * m_BL_WHEEL_MOTOR;
	Talon * m_BR_WHEEL_MOTOR;
	Talon * m_FL_WHEEL_MOTOR;
	Talon * m_FR_WHEEL_MOTOR;

	Joystick * m_joystick;
	RobotDrive m_robotDrive;

public:
	DriveTrain(
			Talon * BL_WHEEL_MOTOR,
			Talon * FL_WHEEL_MOTOR,
			Talon * FR_WHEEL_MOTOR,
			Talon * BR_WHEEL_MOTOR,
			Joystick * joystick
	);
	virtual ~ DriveTrain();
	void run();     // This turns the motors on
	void move();    // This is controlled by the joystick
	void stop();
	void joystickWithDeadZoneY();
	void joystickWithDeadZoneZ();
	void joystickWithThrottle();
	void safety();
	bool isMoving();
	bool moving();

	enum state {
		Idle,
		Controll
	};


private:
	state m_state;

};
