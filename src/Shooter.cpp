/*
 * Shooter.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: cbadu
 */

#include "Shooter.h"

Shooter::Shooter(
		Talon * leftFlywheelMotor,
		Talon * rightFlywheelMotor,
		Joystick * joystick,
		Loader * loader):
		m_loader(loader)
{
	m_leftFlywheelMotor = leftFlywheelMotor;
	m_rightFlywheelMotor = rightFlywheelMotor;
	m_isActivated = false;
	m_state = IDLE;
	m_joystick = joystick;
}

Shooter::~Shooter()
{
}

void Shooter::autoShoot()
{
	m_loader->getSenserState();
	m_loader->load();
	Wait(0.05);
	if (m_loader->sensorChange())
	{
		m_loader->stop();
		Wait(0.05);
		start();
		Wait(1.5);
		m_loader->load();
		Wait(0.4);
		stop();
		m_loader->stop();
	}
}

void Shooter::run()
{
	switch (m_state)
	{
	case IDLE:
		stop();
		if (m_joystick->GetRawButton(DriveStationConstants::buttonjNames::button2))
		{
			m_state = ON;
			break;
		}

		if (m_joystick->GetRawButton(DriveStationConstants::buttonjNames::trigger))
		{
			m_state = AUTO;
			break;
		}
		break;

	case ON:
		start();
		if (m_joystick->GetRawButton(DriveStationConstants::buttonjNames::button2))
		{
			break;
		}
		m_state = OFF;
		break;

	case OFF:
		stop();
		if (m_joystick->GetRawButton(DriveStationConstants::buttonjNames::button2))
		{
			m_state = ON;
			break;
		}
		m_state = IDLE;
		break;

	case AUTO:
		autoShoot();
		if (m_joystick->GetRawButton(DriveStationConstants::buttonjNames::trigger))
		{
			break;
		}
		m_state = IDLE;
		break;
	}
}

void Shooter::start()
{
	float resistance = 1;
	m_leftFlywheelMotor->Set(-1.0f * resistance);
	m_rightFlywheelMotor->Set(1.0f * resistance);
}

void Shooter::stop()
{
	m_leftFlywheelMotor->Set(0.0f);
	m_rightFlywheelMotor->Set(0.0f);
}
