//
// Created by Max on 30.04.2019.
//

#ifndef P3AT_HERBERT_IMOTOR_H
#define P3AT_HERBERT_IMOTOR_H

///
/// Every motor has velocity and methods setVelocity and getVelocity
///

class IMotor {
public:
    /// returns the velocity of the motor
    virtual double getVelocity() = 0;

    /// sets the velocity of the motor
    virtual void setVelocity(double vel) = 0;

    /// returns the acceleration of the motor
    virtual double getAcceleration() = 0;

    /// sets the acceleration of the motor
    virtual void setAcceleration(double acc) = 0;

    /// returns the position of the motor
    virtual double getPosition() = 0;

    /// sets the position of the motor
    virtual void setPosition(double pos) = 0;
protected:
    /// stores the velocity of the motor
    double velocity;
    /// stores the acceleration of the motor
    double acceleration;
    /// stores the position of the motor
    double position;
};


#endif //P3AT_HERBERT_IMOTOR_H
