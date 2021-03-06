/*
 * Loader.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: joshua
 */

#include <Loader.h>


Loader::Loader(
		Talon * motor,
		DigitalInput * lightSensor,
		Joystick * gamepad,
		Joystick * joystick)
{
	// TODO Auto-generated constructor stub
	m_motor = motor;
	m_lightSensor = lightSensor;
	m_gamepad = gamepad;
	m_joystick = joystick;
	m_oldSensorState = m_lightSensor->Get();
	m_state = Idle;
}

bool Loader::sensorChange() //Tracks the sensor value
{
	return(m_oldSensorState != m_lightSensor->Get());
}

bool Loader::getSensorState() //Gets sensor state
{
	return m_oldSensorState;
}

void Loader::setState(state state) //Used to set the state
{
	m_state = state;
}

void Loader::load() //Loads a ball
{
	m_motor->Set(-1.0f);
	Wait(0.01f);
}

void Loader::unLoad() //Unloads a ball
{
	m_motor->Set(1.0f);
}

void Loader::stop()
{
	m_motor->Set(0.0f);
}

void Loader::run()
{
	switch (m_state) {
	case Idle:
		stop();
//		if (!m_gamepad->GetRawButton(buttonNames::buttonA) || !m_gamepad->GetRawButton(buttonNames::buttonB) )
		if(m_gamepad->GetRawButton(buttonNames::buttonA))
		{
			setState(In);
		}
		else if (m_gamepad->GetRawButton(buttonNames::buttonB))
		{
			setState(Out);
		}
		break;

	case In:
		m_motor->Set(1.0f);
		if(m_gamepad->GetRawButton(buttonNames::buttonA))
		{
			setState(Idle);
		}
		else if (m_gamepad->GetRawButton(buttonNames::buttonB))
		{
			setState(Out);
		}
		if (sensorChange())
		{
			setState(Idle);
		}
		break;

	case Out:
		m_motor->Set(-1.0f);
		if(m_gamepad->GetRawButton(buttonNames::buttonA))
		{
			setState(In);
		}
		else if (m_gamepad->GetRawButton(buttonNames::buttonB))
		{
			setState(Idle);
		}
		if (sensorChange())
		{
			setState(Idle);
		}
		break;
	}
	m_oldSensorState = m_lightSensor->Get();
}


Loader::~Loader() {
	// TODO Auto-generated destructor stub
}
