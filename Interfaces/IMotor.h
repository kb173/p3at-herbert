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
    /// returns true if everything worked
    /// returns false if not
    virtual bool setVelocity(double vel) = 0;
protected:
    /// stores the velocity of the motor
    double velocity;
};


#endif //P3AT_HERBERT_IMOTOR_H
