/*
 * Arm.cpp
 *
 *  Created on: Nov 3, 2016
 *      Author: joshcal
 */

#include "Arm.h"
#include "plog/Log.h"
#include "sys/stat.h"

// Arm Function Caller
Arm::Arm(
		AnalogInput * leftPotentiometer,
		AnalogInput * rightPotentiometer,
		DigitalInput * leftLowerLimit,
		DigitalInput * leftUpperLimit,
		DigitalInput * rightLowerLimit,
		DigitalInput * rightUpperLimit,
		Talon * leftArmMotor,
		Talon * rightArmMotor,
		Joystick * gamepad
		//		Joystick * armJoystick
):
m_leftPotentiometer(leftPotentiometer),
m_rightPotentiometer(rightPotentiometer),
m_leftLowerLimit(leftLowerLimit),
m_leftUpperLimit(leftUpperLimit),
m_rightLowerLimit(rightLowerLimit),
m_rightUpperLimit(rightUpperLimit),
m_leftArmMotor(leftArmMotor),
m_rightArmMotor(rightArmMotor),
m_gamepad(gamepad)
//m_armJoystick(armJoystick)
{
	// TODO Auto-generated constructor stub
	m_state = Arm::state::Idle;

}

void Arm::run()
{
	getGamepadWithDeadzone();
	logVoltage();
	switch (m_state)
	{
	case Idle: //Stops, if joystick moves, sets state to joystick control, otherwise breaks.
		stop();
		if (m_gamepadJoystickY)
		{
			m_state = Joystick_Control;
		}
		break;
	case Joystick_Control:
	    /*Controls the motors according to joystick values, sets the state to idle if they've reached the limit,
	     * otherwise sets the state to idle if the joystick is at 0
	     */
		m_leftArmMotor->Set((m_gamepadJoystickY * 0.5));
		m_rightArmMotor->Set((m_gamepadJoystickY * 0.5));
		if (((m_gamepadJoystickY > 0)  && checkUpperLimit() )  ||
				((m_gamepadJoystickY < 0)  && checkLowerLimit()))
		{
			m_state = Idle;
		}
		else if (m_gamepadJoystickY == 0.0f)
		{
			m_state = Idle;
		}
		break;
	case Button_Control: break;

	}
}

bool Arm::checkLowerLimit() //Checks if the arms have reached the lower limit
{
	float rightCurrentVoltage = m_rightPotentiometer->GetVoltage();
	float leftCurrentVoltage = m_leftPotentiometer->GetVoltage();
	m_rightLLimit = RobotConstants::minSaftLimitRight;
	m_leftLLimit = RobotConstants::minSaftLimitLeft;
	bool belowLimitLeft = (leftCurrentVoltage <= m_leftLLimit);
	bool belowLimitRight = (rightCurrentVoltage <= m_rightLLimit);
	return (belowLimitLeft && belowLimitRight);
}

bool Arm::checkUpperLimit() //Checks if the arms have reached the upper limit
{
	float rightCurrentVoltage = m_rightPotentiometer->GetVoltage();
	float leftCurrentVoltage = m_leftPotentiometer->GetVoltage();
	m_leftULimit = RobotConstants::maxSaftLimitLeft;
	m_rightULimit = RobotConstants::maxSaftLimitRight;
	bool aboveLimitLeft = (leftCurrentVoltage >= m_leftULimit);
	bool aboveLimitRight = (rightCurrentVoltage >= m_rightULimit);
	return (aboveLimitLeft && aboveLimitRight);
}

void Arm::logVoltage()
{  // Logging the voltage to check to see if the limits work
	float rightCurrentVoltage = m_rightPotentiometer->GetVoltage();
	float leftCurrentVoltage = m_leftPotentiometer->GetVoltage();
	m_rightULimit = RobotConstants::maxSaftLimitRight;
	m_rightLLimit = RobotConstants::minSaftLimitRight;
	m_leftULimit = RobotConstants::maxSaftLimitLeft;
	m_leftLLimit = RobotConstants::minSaftLimitLeft;

	bool outsideLimitLeft = (leftCurrentVoltage >= m_leftULimit) || (leftCurrentVoltage <= m_leftLLimit);
	bool outsideLimitRight = (rightCurrentVoltage >= m_rightULimit) || (rightCurrentVoltage <= m_rightLLimit);
//	LOGD << "RIGHT VOLTAGE: " << rightCurrentVoltage;
//	LOGD << "LEFT VOLTAGE: " << leftCurrentVoltage;
//	LOGD << "RIGHT LIMIT: " << outsideLimitRight;
//	LOGD << "LEFT LIMIT: " << outsideLimitLeft;
}

void Arm::stop()
{
	m_leftArmMotor->Set(0);
	m_rightArmMotor->Set(0);
}

void Arm::getGamepadWithDeadzone() //Gets the joystick Y axis
{
	m_gamepadJoystickY = -m_gamepad->GetY();
	if (fabs(m_gamepadJoystickY) < 0.05f)
	{
		m_gamepadJoystickY=0.0f;
	}
}

bool Arm::getArmJoystickButton(int buttonCode)
{
	for (int i = 1; i < 6; i++)
	{
		m_armButton[i] = m_armJoystick->GetRawButton(i);
	}

	return m_armButton[buttonCode];
}

void Arm::putDown() //Puts the arms down
{
	if (checkUpperLimit() || checkLowerLimit())
	{
		stop();
	}
	else
	{
		m_leftArmMotor->Set(-1.0f);
		m_rightArmMotor->Set(-1.0f);
	}
}

bool Arm::touchedBottom() { //Checks if the arms have touched the bottom
	float rightCurrentVoltage = m_rightPotentiometer->GetVoltage();
	float leftCurrentVoltage = m_leftPotentiometer->GetVoltage();
	m_rightLLimit = RobotConstants::minSaftLimitRight;
	m_leftLLimit = RobotConstants::minSaftLimitLeft;

	bool bottomLimit = ((rightCurrentVoltage <= m_rightLLimit) || (leftCurrentVoltage <= m_leftLLimit));
	return bottomLimit;
}

bool Arm::touchedTop() { //Checks if the arms have touched the top
	float rightCurrentVoltage = m_rightPotentiometer->GetVoltage();
	float leftCurrentVoltage = m_leftPotentiometer->GetVoltage();
	m_rightULimit = RobotConstants::maxSaftLimitRight;
	m_leftULimit = RobotConstants::maxSaftLimitLeft;

	bool outsideLimit = ((rightCurrentVoltage >= m_rightULimit) || (leftCurrentVoltage >= m_leftULimit));
	return outsideLimit;
}

void Arm::rUp() { //Moves the right arm up
	if (touchedTop()) {
		stop();
	}
	m_rightArmMotor->Set(1.0f);
}

void Arm::rDown() { //Moves the right arm down
	if (touchedBottom()) {
		stop();
	}
	m_rightArmMotor->Set(-1.0f);
}

void Arm::lUp() { //Moves the left arm up
	if (touchedTop()) {
		stop();
	}
	m_leftArmMotor->Set(1.0f);
}

void Arm::lDown() { //Moves the left arm down
	if (touchedBottom()) {
		stop();
	}
	m_leftArmMotor->Set(-1.0f);
}

Arm::~Arm() {
	// TODO Auto-generated destructor stub
}

