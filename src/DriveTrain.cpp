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
	m_joystickZ = 0;
	m_joystickY = 0;
	m_state = DriveTrain::state::Idle;
}

void DriveTrain::safety() {
	m_robotDrive.SetSafetyEnabled(false);
}

void DriveTrain::joystickWithDeadZoneY()
{
	m_joystickY = -m_joystick->GetY();
	if (fabs(m_joystickY) < 0.05f)
	{
		m_joystickY=0.0f;
	}
}

void DriveTrain::joystickWithDeadZoneZ()
{
	m_joystickZ = -m_joystick->GetZ();
	if (fabs(m_joystickZ) < 0.05f)
	{
		m_joystickZ=0.0f;
	}
}

void DriveTrain::stop()
{
	m_BL_WHEEL_MOTOR->Set(0.0);
	m_FL_WHEEL_MOTOR->Set(0.0f);
	m_FR_WHEEL_MOTOR->Set(0.0f);
	m_BR_WHEEL_MOTOR->Set(0.0f);
}

void DriveTrain::move()
{
	m_robotDrive.TankDrive((m_joystickY + m_joystickZ),(m_joystickY - m_joystickZ));
}

void DriveTrain::run() {
	joystickWithDeadZoneY();
	joystickWithDeadZoneZ();
	switch (m_state)
	{
	case Idle:
		stop();
		if (!m_joystickY && !m_joystickZ)
		{
			break;
		}
		m_state = Controll;
		break;

	case Controll:
		move();
		if (m_joystickY && m_joystickZ)
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

