#include <iostream>
#include "Loader.h"
#include "DriveTrain.h"
#include "Arm.h"
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
        Talon m_loaderMotor;
        DigitalInput m_lightSensor;
        Joystick m_joystick;
        Joystick m_gamepad;
        Arm m_arm;
        DriveTrain m_driveTrain;
        Loader m_loader;



    public:
        Robot() :
            m_BLDriveMotor(PortAssign::blDriveMotor),
            m_FLDriveMotor(PortAssign::flDriveMotor),
            m_BRDriveMotor(PortAssign::brDriveMotor),
            m_FRDriveMotor(PortAssign::frDriveMotor),
			m_loaderMotor(PortAssign::loaderMotor),
			m_lightSensor(PortAssign::lightSensor),
            m_joystick(PortAssign::joystick),
            m_gamepad(PortAssign::gamepad),
			m_loader(&m_loaderMotor, &m_lightSensor, &m_gamepad, &m_joystick),
			m_driveTrain(&m_BLDriveMotor,&m_FLDriveMotor,&m_FRDriveMotor,&m_BRDriveMotor,&m_joystick)
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
        m_driveTrain.safety();
        while(IsOperatorControl() && IsEnabled())
        {
        	m_driveTrain.run();
            m_loader.run();
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
