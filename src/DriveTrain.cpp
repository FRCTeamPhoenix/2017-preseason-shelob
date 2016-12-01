/*
 * DriveTrain.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: joshua
 */

#include "DriveTrain.h"

DriveTrain::DriveTrain(
		Talon * BL_WHEEL_MOTOR,
		Talon * FL_WHEEL_MOTOR,
		Talon * FR_WHEEL_MOTOR,
		Talon * BR_WHEEL_MOTOR,
		Joystick * joystick
):
m_BL_WHEEL_MOTOR(BL_WHEEL_MOTOR),
m_BR_WHEEL_MOTOR(BR_WHEEL_MOTOR),
m_FL_WHEEL_MOTOR(FL_WHEEL_MOTOR),
m_FR_WHEEL_MOTOR(FR_WHEEL_MOTOR),
m_joystick(joystick),
m_robotDrive(m_FL_WHEEL_MOTOR,m_BL_WHEEL_MOTOR,m_FR_WHEEL_MOTOR,m_BR_WHEEL_MOTOR)
{
	// TODO Auto-generated constructor stub
	m_state = DriveTrain::state::Idle;
}

void DriveTrain::safety()
{
	m_robotDrive.SetSafetyEnabled(false);
}

// joystick throttle is meant to be used as a resistance for the driver train.
// added throttle function
void DriveTrain::joystickWithThrottle() {
	 m_joystickThrottle = -(0.5 * m_joystick->GetThrottle()) + 0.5;
}

void DriveTrain::joystickWithDeadZoneY()
{
	m_joystickY = -m_joystick->GetY();//* m_joystickThrottle;
	if (fabs(m_joystickY) < 0.05f)
	{
		m_joystickY=0.0f;
	}
	m_joystickY = m_joystickY * m_joystickThrottle;
}

void DriveTrain::joystickWithDeadZoneZ()
{
	m_joystickZ = m_joystick->GetZ();
	if (fabs(m_joystickZ) < 0.15f)
	{
		m_joystickZ=0.0f;
	}
	m_joystickZ = m_joystickZ * m_joystickThrottle;

}

void DriveTrain::stop()
{
	m_BL_WHEEL_MOTOR->Set(0.0f);
	m_FL_WHEEL_MOTOR->Set(0.0f);
	m_FR_WHEEL_MOTOR->Set(0.0f);
	m_BR_WHEEL_MOTOR->Set(0.0f);
}

void DriveTrain::move()
{
	m_robotDrive.TankDrive((m_joystickY + m_joystickZ),(m_joystickY - m_joystickZ));
//	m_robotDrive.TankDrive(m_joystickZ,m_joystickZ);
}

bool DriveTrain::isMoving() {
	// TODO Move Constants
	if ((m_joystickY && m_joystickZ))
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool DriveTrain::moving() {
	// TODO Move Constants
	if ((m_joystickY || m_joystickZ))
	{
		return true;
	}
	else
	{
		return false;
	}
}



void DriveTrain::run()
{
	joystickWithThrottle();
	joystickWithDeadZoneY();
	joystickWithDeadZoneZ();
	switch (m_state)
	{
	case Idle:
		stop();
		if (!isMoving())
		{
			break;
		}
		m_state = Controll;
		break;

	case Controll:
		move();
		if (moving())
		{
			break;
		}
		m_state = Idle;
		break;
	}
}

DriveTrain::~DriveTrain()
{
	// TODO Auto-generated destructor stub
}

