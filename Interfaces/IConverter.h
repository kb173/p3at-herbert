//
// Created by irena.ankerl on 14.05.2019.
//

#ifndef P3AT_HERBERT_ICONVERTER_H
#define P3AT_HERBERT_ICONVERTER_H

class IConverter {
public:
    virtual double radToMm(double radius, double radian) = 0;

    virtual ~IConverter() = default;
};

#endif //P3AT_HERBERT_ICONVERTER_H
