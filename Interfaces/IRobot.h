//
// Created by karl on 30.04.19.
//

#ifndef P3AT_HERBERT_IROBOT_H
#define P3AT_HERBERT_IROBOT_H

#include "IVirtualDeviceManager.h"
#include "IWbDeviceGetter.h"

/// Model for any robot with devices. It is mainly used as a nicer interface to devices
/// for RealDeviceControllers. This way, these controllers can get robot devices here
/// instead of having to know about WbDeviceTags, making them independent from WeBots.
/// It is also responsible for filling the VirtualDeviceManager with the same devices
/// and tags as the corresponding WeBots robot.
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
