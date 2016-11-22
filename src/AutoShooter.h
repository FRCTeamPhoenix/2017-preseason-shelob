/*
 * AutoShooter.h
 *
 *  Created on: Nov 19, 2016
 *      Author: joshc
 */
#include "constants.h"
#ifndef AUTOSHOOTER_H_
#define AUTOSHOOTER_H_

class AutoShooter {
public:
	AutoShooter(
			Talon * leftFlywheelMotor,
			Talon * rightFlywheelMotor,
			Talon * loaderMotor,
			DigitalInput * lightSensor,
			Joystick * joystick);
	virtual ~AutoShooter();
	void run();
	void stop();
	void shoot();
	void unload();
	void load();

	enum state {
		IDLE,
		SHOOT,
		UNLOAD
	};

private:
	Talon * m_leftFlywheelMotor;
	Talon * m_rightFlywheelMotor;
	Talon * m_loaderMotor;
	DigitalInput * m_lightSensor;
	Joystick * m_joystick;
	state m_state;
	bool m_oldLightState;
};

#endif /* AUTOSHOOTER_H_ */
