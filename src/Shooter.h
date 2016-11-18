/*
 * Shooter.h
 *
 *  Created on: Nov 7, 2016
 *      Author: cbadu
 */

#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_
#include "WPILib.h"
#include "constants.h"

class Shooter
{
        Talon* m_leftFlywheelMotor;
        Talon* m_rightFlywheelMotor;

        Joystick* m_gamepad;

        bool m_isActivated;

    public:
        Shooter(Talon* leftFlywheelMotor, Talon* rightFlywheelMotor, Joystick* gamepad);
        virtual ~Shooter();

        enum STATE
        {
            OFF,
            ON
        };

        void run();
        void start();
        void stop();
        STATE getCurrentState();

};

#endif /* SRC_SHOOTER_H_ */
