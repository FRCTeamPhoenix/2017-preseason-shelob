/*
 * AutoShooter.cpp
 *
 *  Created on: Nov 19, 2016
 *      Author: joshc
 */

#include "AutoShooter.h"

AutoShooter::AutoShooter(
		Talon * leftFlywheelMotor,
		Talon * rightFlywheelMotor,
		Talon * loaderMotor,
		DigitalInput * lightSensor,
		Joystick * joystick):
		m_leftFlywheelMotor(leftFlywheelMotor),
		m_rightFlywheelMotor(rightFlywheelMotor),
		m_loaderMotor(loaderMotor),
		m_lightSensor(lightSensor),
		m_joystick(joystick)
{
	// TODO Auto-generated constructor stub
	m_oldLightState = m_lightSensor->Get();
	m_state = state::IDLE;
}

void AutoShooter::stop()
{
	m_loaderMotor->Set(0.0f);
	m_leftFlywheelMotor->Set(0.0f);
	m_rightFlywheelMotor->Set(0.0f);
}

void AutoShooter::load() {
	float resistance = 1;
	m_leftFlywheelMotor->Set(-1.0f * resistance);
	m_rightFlywheelMotor->Set(1.0f * resistance);
	Wait(1);
	m_loaderMotor->Set(-1.0f);
}

void AutoShooter::shoot()
{
	float resistance = 1;
	m_leftFlywheelMotor->Set(-1.0f * resistance);
	m_rightFlywheelMotor->Set(1.0f * resistance);
	Wait(1);
//	m_loaderMotor->Set(-1.0f);
}

void AutoShooter::unload()
{
	m_loaderMotor->Set(1.0f);
	Wait(3);
}

void AutoShooter::run()
{
	switch (m_state)
	{
	case IDLE:
		stop();
		if (!m_joystick->GetRawButton(DriveStationConstants::buttonjNames::trigger))
		{
			break;
		}
		m_state = SHOOT;
		break;

	case SHOOT:
		load();
		shoot();
		if (m_oldLightState != m_lightSensor->Get())
		{
			break;
		}
		m_state = UNLOAD;
		break;
	case UNLOAD:
		unload();
		m_state = IDLE;
		break;
	}

}

AutoShooter::~AutoShooter() {
	// TODO Auto-generated destructor stub
}

