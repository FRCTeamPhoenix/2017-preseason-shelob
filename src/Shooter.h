/*
 * Shooter.h
 *
 *  Created on: Nov 7, 2016
 *      Author: cbadu
 */

#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_
#include "WPILib.h"
#include "constants.h"

class Shooter
{
	bool m_isActivated;

public:
	Shooter(Talon* leftFlywheelMotor, Talon* rightFlywheelMotor, Joystick* gamepad);
	virtual ~Shooter();


	enum state
	{
		IDLE,
		ON,
		OFF
	};

	void run();
	void start();
	void stop();
	state getCurrentState();


private:
	state m_state;
	Talon* m_leftFlywheelMotor;
	Talon* m_rightFlywheelMotor;
	Joystick* m_gamepad;
};

#endif /* SRC_SHOOTER_H_ */
