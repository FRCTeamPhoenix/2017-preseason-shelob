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
    public:
        Robot() :
            m_BLDriveMotor(PortAssign::blDriveMotor),
            m_FLDriveMotor(PortAssign::flDriveMotor),
            m_BRDriveMotor(PortAssign::brDriveMotor),
            m_FRDriveMotor(PortAssign::frDriveMotor)
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
        while(IsOperatorControl() && IsEnabled())
        {

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
