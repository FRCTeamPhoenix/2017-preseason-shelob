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
#include "Loader.h"

class Shooter
{
	bool m_isActivated;

public:
	Shooter(
			Talon * leftFlywheelMotor,
			Talon * rightFlywheelMotor,
			Joystick * joystick,
			Loader * loader);
	virtual ~Shooter();


	enum state
	{
		IDLE,
		ON,
		OFF,
		AUTO
	};

	void run(); // Works like a main() function
	void start(); // Starts the fly wheels
	void stop(); // Stops the fly wheels
	state getCurrentState(); // Gets the current state of the fly wheels
	void autoShoot(); // The auto shoot function works for when you press that special button


private:
	state m_state;
	Talon* m_leftFlywheelMotor;
	Talon* m_rightFlywheelMotor;
	Joystick * m_joystick;
	Loader * m_loader;
};

#endif /* SRC_SHOOTER_H_ */
