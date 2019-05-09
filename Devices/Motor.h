//
// Created by irena.ankerl on 09.05.2019.
//

#ifndef P3AT_HERBERT_MOTOR_H
#define P3AT_HERBERT_MOTOR_H

#include "../Interfaces/IMotor.h"

class Motor : IMotor{
public:
    /// returns the velocity of the motor
    double getVelocity();

    /// sets the velocity of the motor
    void setVelocity(double vel);

    /// returns the acceleration of the motor
    double getAcceleration() = 0;

    /// sets the acceleration of the motor
    void setAcceleration(double acc) = 0;

    /// returns the position of the motor
    double getPosition() = 0;

    /// sets the position of the motor
    void setPosition(double pos) = 0;
};


#endif //P3AT_HERBERT_MOTOR_H
