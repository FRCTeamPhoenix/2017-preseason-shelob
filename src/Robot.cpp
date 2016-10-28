#include <iostream>
//#include "Arm.h"
#include "DriveTrain.h"
#include "WPILib.h"
#include "constants.h"
using namespace std;

class Robot : public SampleRobot
{
        Talon m_BLDriveMotor;
        Talon m_FLDriveMotor;
        Talon m_BRDriveMotor;
        Talon m_FRDriveMotor;
        Joystick m_joystick;
        Joystick m_gamepad;
        RobotDrive m_robotDrive;


    public:
        Robot() :
            m_BLDriveMotor(PortAssign::blDriveMotor),
            m_FLDriveMotor(PortAssign::flDriveMotor),
            m_BRDriveMotor(PortAssign::brDriveMotor),
            m_FRDriveMotor(PortAssign::frDriveMotor),
            m_joystick(PortAssign::joystick),
            m_gamepad(PortAssign::gamepad),
            m_robotDrive(m_FLDriveMotor,m_BLDriveMotor,m_FRDriveMotor,m_BRDriveMotor)
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
