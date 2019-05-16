//
// Created by irena.ankerl on 09.05.2019.
//

#ifndef P3AT_HERBERT_MOTOR_H
#define P3AT_HERBERT_MOTOR_H

#include "../Interfaces/IMotor.h"

class Motor : public IMotor {
public:
    /// constructor, sets all values 0
    Motor();

    /// returns the velocity of the motor
    double getVelocity();

    /// sets the velocity of the motor
    void setVelocity(double vel);

    /// returns the acceleration of the motor
    double getAcceleration();

    /// sets the acceleration of the motor
    void setAcceleration(double acc);

    /// returns the position of the motor
    double getPosition();

    /// sets the position of the motor
    void setPosition(double pos);
};


#endif //P3AT_HERBERT_MOTOR_H
