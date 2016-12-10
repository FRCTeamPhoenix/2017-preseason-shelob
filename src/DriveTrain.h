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
	void stop();  // Stoping the motors on the drive train
	void joystickWithDeadZoneY(); // Gets the joystick Y
	void joystickWithDeadZoneZ(); // Gets the joystick Z
	void joystickWithThrottle(); // Gets the joystick Throttle
	void safety(); // Enables saftey mode for you to move the drive train.
	bool joystickMoving(); // Checking to see if the joystick are not moving.
	bool moving(); // Checking to see if the joystick is moving.

	enum state
	{
		IDLE,
		CONTROLL
	};


private:
	state m_state;

};
