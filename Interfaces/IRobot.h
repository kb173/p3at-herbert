//
// Created by karl on 30.04.19.
//

#ifndef P3AT_HERBERT_IROBOT_H
#define P3AT_HERBERT_IROBOT_H

#include "IVirtualDeviceManager.h"
#include "IWbDeviceGetter.h"

class IRobot {
public:
    /// Inserts all devices of this robot into a VirtualDeviceManager
    /// @param deviceManager The IVirtualDeviceManager to fill
    virtual void
    fillDeviceManager(std::shared_ptr<IVirtualDeviceManager> deviceManager, std::shared_ptr<IWbDeviceGetter>) = 0;
};

#endif //P3AT_HERBERT_IROBOT_H
