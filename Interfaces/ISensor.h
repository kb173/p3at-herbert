//
// Created by Max on 30.04.2019.
//

#ifndef P3AT_HERBERT_ISENSOR_H
#define P3AT_HERBERT_ISENSOR_H

///
/// Every sensor has a value and methods setValue and getValue
///

class ISensor : IDevice{
public:
    /// returns the value of the sensor
    virtual double getValue() = 0;

    /// sets the value of the sensor
    /// returns true if everything worked
    /// returns false if not
    virtual bool setValue(double val) = 0;
protected:
    /// stores the value of the sensor
    double value;
};


#endif //P3AT_HERBERT_ISENSOR_H
