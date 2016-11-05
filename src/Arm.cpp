/*
 * Arm.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: joshcal
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
	checkLimit();
	switch (m_state) {

	case Idle:
		stop();
		if (m_gamepadJoystickY && getLimit()) {
			m_state = Joystick_Control;
		}
		break;
	case Joystick_Control:
		m_leftArmMotor->Set(m_gamepadJoystickY);
		m_rightArmMotor->Set(m_gamepadJoystickY);
		if (m_gamepadJoystickY == 0.0f) {
			m_state = Idle;
		}
		break;
	case Button_Control: break;

	}
}

void Arm::checkLimit() {
	float rightCurrentVoltage = m_rightPotentiometer->GetVoltage();
	float leftCurrentVoltage = m_leftPotentiometer->GetVoltage();
	m_rightULimit = RobotConstants::maxSaftLimitRight;
	m_rightLLimit = RobotConstants::minSaftLimitRight;
	m_leftULimit = RobotConstants::maxSaftLimitLeft;
	m_leftLLimit = RobotConstants::minSaftLimitLeft;
	if (((rightCurrentVoltage >= m_rightULimit) && (leftCurrentVoltage >= m_leftULimit)) || ((rightCurrentVoltage >= m_rightULimit) || (leftCurrentVoltage >= m_leftULimit))){
		m_state = Idle;
	}
	else if (((rightCurrentVoltage <= m_rightLLimit) && (leftCurrentVoltage <= m_leftLLimit)) || ((rightCurrentVoltage <= m_rightLLimit) || (leftCurrentVoltage <= m_leftLLimit))){
		m_state = Idle;
	}
}

bool Arm::getLimit() {
	float rightCurrentVoltage = m_rightPotentiometer->GetVoltage();
	float leftCurrentVoltage = m_leftPotentiometer->GetVoltage();
	m_rightULimit = RobotConstants::maxSaftLimitRight;
	m_rightLLimit = RobotConstants::minSaftLimitRight;
	m_leftULimit = RobotConstants::maxSaftLimitLeft;
	m_leftLLimit = RobotConstants::minSaftLimitLeft;
	if (((rightCurrentVoltage >= m_rightULimit) && (leftCurrentVoltage >= m_leftULimit)) || ((rightCurrentVoltage >= m_rightULimit) || (leftCurrentVoltage >= m_leftULimit))){
		return false;
	}
	else if (((rightCurrentVoltage <= m_rightLLimit) && (leftCurrentVoltage <= m_leftLLimit)) || ((rightCurrentVoltage <= m_rightLLimit) || (leftCurrentVoltage <= m_leftLLimit))){
		return false;
	}
	else {
		return true;
	}
}

void Arm::stop(){
m_leftArmMotor->Set(0);
m_rightArmMotor->Set(0);
}

void Arm::getGamepadWithDeadzone() {
	m_gamepadJoystickY = m_gamepad->GetY();
	if (fabs(m_gamepadJoystickY) < 0.05f){
		m_gamepadJoystickY=0.0f;
	}
}

bool Arm::getArmJoystickButton(int buttonCode) {
	for (int i = 1; i < 6; i++) {
		m_armButton[i] = m_armJoystick->GetRawButton(i);
	}

	return m_armButton[buttonCode];
}

Arm::~Arm() {
	// TODO Auto-generated destructor stub
}

