//
// Created by Max on 30.04.2019.
//

#ifndef P3AT_HERBERT_IDEVICE_H
#define P3AT_HERBERT_IDEVICE_H

#include "controller/c/webots/types.h"

///
/// Every device has a deviceTag.
///
class IDevice {
public:
    ///getTag() returns the tag of the current object
    virtual WbDeviceTag getTag() = 0;
protected:
    ///deviceTag is the identification number of a device given by webots
    WbDeviceTag deviceTag;
};


#endif //P3AT_HERBERT_IDEVICE_H
