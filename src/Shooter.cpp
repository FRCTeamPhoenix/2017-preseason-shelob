/*
 * Shooter.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: cbadu
 */

#include <Shooter.h>

Shooter::Shooter(Talon* leftFlywheelMotor, Talon* rightFlywheelMotor, Joystick* gamepad):
    m_leftFlywheelMotor(leftFlywheelMotor),
    m_rightFlywheelMotor(rightFlywheelMotor),
    m_gamepad(gamepad)
{
    m_state = IDLE;
}

Shooter::~Shooter()
{
}

void Shooter::run()
{
    switch (m_state)
    {
        case IDLE:
            stop();
            if (m_gamepad->GetRawButton(DriveStationConstants::buttonNames::buttonX))
            {
                m_state = ON;
                break;
            }
            break;

        case ON:
            start();
            if (!m_gamepad->GetRawButton(DriveStationConstants::buttonNames::buttonX))
            {
                m_state = OFF;
                break;
            }
            break;

        case OFF:
            stop();
            if (m_gamepad->GetRawButton(DriveStationConstants::buttonNames::buttonX))
            {
                m_state = ON;
                break;
            }
            m_state = IDLE;
            break;
    }
}

void Shooter::start()
{
    m_leftFlywheelMotor->Set(-1.0f);
    m_rightFlywheelMotor->Set(1.0f);
}

void Shooter::stop()
{
    m_leftFlywheelMotor->Set(0.0f);
    m_rightFlywheelMotor->Set(0.0f);
}
