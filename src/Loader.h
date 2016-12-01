/*
 * Loader.h
 *
 *  Created on: Nov 7, 2016
 *      Author: joshua
 */

#include "WPILib.h"
#include "constants.h"
#ifndef SRC_LOADER_H_
#define SRC_LOADER_H_

class Loader {
public:
	enum state {
		Idle,
		Out,
		In
	};

	Loader(
			Talon * motor,
			DigitalInput * lightSensor,
			Joystick * gamepad,
			Joystick * joystick);

	virtual ~Loader();
	void run();
	void stop();
	void load();
	void unLoad();

	// Getters
	bool sensorChange();
//	state getState(state state);
	bool getSenserState();

	// Setters
	void setState(state state);

private:
	Talon * m_motor;
	DigitalInput * m_lightSensor;
	Joystick * m_gamepad;
	Joystick * m_joystick;

	state m_state;
	bool m_oldSensorState;

};

#endif /* SRC_LOADER_H_ */
