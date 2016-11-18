#include "WPILib.h"

class DriveTrain
{
    public:
        virtual ~ DriveTrain();
        void run();     // This turns the motors on
        void move();    // This is controlled by the joystick

    private:
        float joystickFNB;
        float joystickRNL;
};
