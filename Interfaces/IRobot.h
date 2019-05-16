//
// Created by karl on 30.04.19.
//

#ifndef P3AT_HERBERT_IROBOT_H
#define P3AT_HERBERT_IROBOT_H

#include "IVirtualDeviceManager.h"
#include "IWbDeviceGetter.h"

class IRobot {
public:
    /// Instances all devices of this robot and adds them to the given deviceManager.
    /// The tags are chosen by the given deviceGetter to keep them in sync with the tags in WeBots.
    /// For this, the device names (private constants) are used.
    /// \param deviceManager The VirtualDeviceManager to put the devices into
    /// \param deviceGetter The WbDeviceGetter which should provide the WbDeviceTags
    virtual void
    fillDeviceManager(std::shared_ptr<IVirtualDeviceManager> deviceManager, std::shared_ptr<IWbDeviceGetter>) = 0;
};

#endif //P3AT_HERBERT_IROBOT_H
