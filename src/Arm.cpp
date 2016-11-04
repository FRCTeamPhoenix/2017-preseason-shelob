/*
 * Arm.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: Bryce Czuba
 */

#include "Arm.h"

Arm::Arm(
		AnalogInput * leftPotentiometer,
			AnalogInput * rightPotentiometer,
			DigitalInput * leftLowerLimit,
			DigitalInput * leftUpperLimit,
			DigitalInput * rightLowerLimit,
			DigitalInput * rightUpperLimit,
			Talon * leftArmMotor,
			Talon * rightArmMotor,
			Joystick * gamepad):

			m_leftPotentiometer(leftPotentiometer),
			m_rightPotentiometer(rightPotentiometer),
			m_leftLowerLimit(leftLowerLimit),
			m_leftUpperLimit(leftUpperLimit),
			m_rightLowerLimit(rightLowerLimit),
			m_rightUpperLimit(rightUpperLimit),
			m_leftArmMotor(leftArmMotor),
			m_rightArmMotor(rightArmMotor),
			m_gamepad(gamepad)
			{
	// TODO Auto-generated constructor stub
	m_state = Arm::state::Idle;

}

void Arm::run(){

	getGamepadWithDeadzone();
	switch (m_state) {

	case Idle:
		stop();
		if (m_gamepadJoystickY == 0) {
			m_state = Joystick_Control;
		}
		break;
	case Joystick_Control:
		m_leftArmMotor->Set(m_gamepadJoystickY);
		m_rightArmMotor->Set(m_gamepadJoystickY);
		if (m_gamepadJoystickY == 0) {
			m_state = Idle;
		}
		break;
	case Button_Control: break;

	}
}

void Arm::stop(){


}

void Arm::getGamepadWithDeadzone() {
	m_gamepadJoystickY = m_gamepad->GetY();
	if (fabs(m_gamepadJoystickY) < 0.05f){
		m_gamepadJoystickY=0;
	}
}

Arm::~Arm() {
	// TODO Auto-generated destructor stub
}

