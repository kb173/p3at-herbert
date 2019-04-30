//
// Created by karl on 30.04.19.
//

#ifndef P3AT_HERBERT_IROBOT_H
#define P3AT_HERBERT_IROBOT_H

#include "IVirtualDeviceManager.h"

class IRobot {
public:
    /// Inserts all devices of this robot into a VirtualDeviceManager
    /// @param deviceManager The IVirtualDeviceManager to fill
    virtual void fillDeviceManager(IVirtualDeviceManager deviceManager) = 0;
};

#endif //P3AT_HERBERT_IROBOT_H
