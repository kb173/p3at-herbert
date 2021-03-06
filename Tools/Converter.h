//
// Created by irena.ankerl on 14.05.2019.
//

#ifndef P3AT_HERBERT_CONVERTER_H
#define P3AT_HERBERT_CONVERTER_H

#include "../Interfaces/IConverter.h"

///A class for converting different units
class Converter : public IConverter {
public:
    ///converts radian/s to mm/s, needs radius
    double radToMm(double radius, double radian);
};

#endif //P3AT_HERBERT_CONVERTER_H
