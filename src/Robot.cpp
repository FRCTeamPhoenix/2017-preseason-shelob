#include <iostream>
#include "Arm.h"
#include "DriveTrain.h"
#include "WPILib.h"
#include "constants.h"
#include "plog/Log.h"
#include "sys/stat.h"

using namespace std;

class Robot : public SampleRobot
{
        Talon m_BLDriveMotor;
        Talon m_FLDriveMotor;
        Talon m_BRDriveMotor;
        Talon m_FRDriveMotor;
        Talon m_leftArmMotor;
        Talon m_rightArmMotor;
        AnalogInput m_leftPotentiometer;
        AnalogInput m_rightPotentiometer;
        DigitalInput m_leftLowerLimit;
        DigitalInput m_leftUpperLimit;
        DigitalInput m_rightLowerLimit;
        DigitalInput m_rightUpperLimit;
        Joystick m_joystick;
        Joystick m_gamepad;
        RobotDrive m_robotDrive;
        Arm m_arm;


    public:
        Robot() :
            m_BLDriveMotor(PortAssign::blDriveMotor),
            m_FLDriveMotor(PortAssign::flDriveMotor),
            m_BRDriveMotor(PortAssign::brDriveMotor),
            m_FRDriveMotor(PortAssign::frDriveMotor),
			m_leftArmMotor(PortAssign::leftArmMotor),
			m_rightArmMotor(PortAssign::rightArmMotor),
			m_leftPotentiometer(PortAssign::leftPotentiometer),
    		m_rightPotentiometer(PortAssign::rightPotentiometer),
			m_leftLowerLimit(PortAssign::leftLowerLimit),
			m_leftUpperLimit(PortAssign::leftUpperLimit),
			m_rightLowerLimit(PortAssign::rightLowerLimit),
			m_rightUpperLimit(PortAssign::rightUpperLimit),
            m_joystick(PortAssign::joystick),
            m_gamepad(PortAssign::gamepad),
            m_robotDrive(m_FLDriveMotor,m_BLDriveMotor,m_FRDriveMotor,m_BRDriveMotor),
    		m_arm(&m_leftPotentiometer, &m_rightPotentiometer, &m_leftLowerLimit, &m_leftUpperLimit, &m_rightLowerLimit, &m_rightUpperLimit, &m_leftArmMotor, &m_rightArmMotor, &m_gamepad)
        {
        	plog::init(plog::debug, "/home/lvuser/robot_logger.txt");
   		    LOGD << "-------------------------New Run-------------------------";
        }
    void Autonomous()
    {
        while(IsAutonomous() && IsEnabled())
        {

        }
    }
    void OperatorControl()
    {
        m_robotDrive.SetSafetyEnabled(false);
        while(IsOperatorControl() && IsEnabled())
        {

            float throttle = m_joystick.GetY();
            float twist = m_joystick.GetZ();

            m_robotDrive.TankDrive((throttle + twist),(throttle - twist));
            m_arm.run();
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
