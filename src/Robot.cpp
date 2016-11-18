#include <iostream>
//#include "Arm.h"
#include "DriveTrain.h"
#include "WPILib.h"
#include "constants.h"
#include "Shooter.h"
using namespace std;

class Robot : public SampleRobot
{
        Talon m_BLDriveMotor;
        Talon m_FLDriveMotor;
        Talon m_BRDriveMotor;
        Talon m_FRDriveMotor;
        Talon m_leftFlywheelMotor;
        Talon m_rightFlywheelMotor;
        Joystick m_joystick;
        Joystick m_gamepad;
        RobotDrive m_robotDrive;
        Shooter m_shooter;

    public:
        Robot() :
            m_BLDriveMotor(PortAssign::blDriveMotor),
            m_FLDriveMotor(PortAssign::flDriveMotor),
            m_BRDriveMotor(PortAssign::brDriveMotor),
            m_FRDriveMotor(PortAssign::frDriveMotor),
            m_leftFlywheelMotor(PortAssign::flywheelLeftMotor),
            m_rightFlywheelMotor(PortAssign::flywheelRightMotor),
            m_joystick(PortAssign::joystick),
            m_gamepad(PortAssign::gamepad),
            m_robotDrive(m_FLDriveMotor,m_BLDriveMotor,m_FRDriveMotor,m_BRDriveMotor),
            m_shooter(&m_leftFlywheelMotor,&m_rightFlywheelMotor,&m_gamepad)
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
        m_robotDrive.SetSafetyEnabled(false);
        while(IsOperatorControl() && IsEnabled())
        {
            float throttle = m_joystick.GetY();
            float twist = m_joystick.GetZ();
            m_robotDrive.TankDrive((throttle + twist),(throttle - twist));
            m_shooter.run();
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
