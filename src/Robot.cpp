#include <iostream>
#include "Loader.h"
#include "DriveTrain.h"
#include "Arm.h"
#include "WPILib.h"
#include "constants.h"
#include "plog/Log.h"
#include "sys/stat.h"
#include "Shooter.h"
using namespace std;

class Robot : public SampleRobot
{
	Talon m_BLDriveMotor;
	Talon m_FLDriveMotor;
	Talon m_BRDriveMotor;
	Talon m_FRDriveMotor;
	Talon m_loaderMotor;
	Talon m_leftArmMotor;
	Talon m_rightArmMotor;
	Talon m_rightFlywheelMotor;
    Talon m_leftFlywheelMotor;
	AnalogInput m_leftPotentiometer;
	AnalogInput m_rightPotentiometer;
	DigitalInput m_leftLowerLimit;
	DigitalInput m_leftUpperLimit;
	DigitalInput m_rightLowerLimit;
	DigitalInput m_rightUpperLimit;
	DigitalInput m_lightSensor;
	Joystick m_joystick;
	Joystick m_gamepad;
	Loader m_loader;
	Arm m_arm;
	DriveTrain m_driveTrain;
	Shooter m_shooter;



public:
	Robot() :
		m_BLDriveMotor(PortAssign::blDriveMotor),
		m_FLDriveMotor(PortAssign::flDriveMotor),
		m_BRDriveMotor(PortAssign::brDriveMotor),
		m_FRDriveMotor(PortAssign::frDriveMotor),
		m_loaderMotor(PortAssign::loaderMotor),
		m_leftArmMotor(PortAssign::leftArmMotor),
		m_rightArmMotor(PortAssign::rightArmMotor),
        m_rightFlywheelMotor(PortAssign::flywheelRightMotor),
        m_leftFlywheelMotor(PortAssign::flywheelLeftMotor),
		m_leftPotentiometer(PortAssign::leftPotentiometer),
		m_rightPotentiometer(PortAssign::rightPotentiometer),
		m_leftLowerLimit(PortAssign::leftLowerLimit),
		m_leftUpperLimit(PortAssign::leftUpperLimit),
		m_rightLowerLimit(PortAssign::rightLowerLimit),
		m_rightUpperLimit(PortAssign::rightUpperLimit),
		m_lightSensor(PortAssign::lightSensor),
		m_joystick(PortAssign::joystick),
		m_gamepad(PortAssign::gamepad),
		m_loader(&m_loaderMotor, &m_lightSensor, &m_gamepad, &m_joystick),
		m_arm(&m_leftPotentiometer, &m_rightPotentiometer, &m_leftLowerLimit, &m_leftUpperLimit, &m_rightLowerLimit, &m_rightUpperLimit, &m_leftArmMotor, &m_rightArmMotor, &m_gamepad),
		m_driveTrain(&m_BLDriveMotor,&m_FLDriveMotor,&m_FRDriveMotor,&m_BRDriveMotor,&m_joystick),
		m_shooter(&m_leftFlywheelMotor,&m_rightFlywheelMotor,&m_joystick, &m_loader)
{
}
	void Autonomous()
	{
		while(IsAutonomous() && IsEnabled())
		{

		}
	}
	void OperatorControl()
	{
		m_driveTrain.safety(); // Enable drive train saftey mode
		while(IsOperatorControl() && IsEnabled())
		{
			m_driveTrain.run(); // Drive Tain Run
			m_arm.run(); // Arm Run
			m_loader.run(); // Loader Run
			m_shooter.run(); // Shooter Run
		}
	}
	void Test()
	{
		while(IsTest() && IsEnabled())
		{

		}
	}
};
START_ROBOT_CLASS(Robot)
