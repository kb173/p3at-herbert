//
// Created by Max on 30.04.2019.
//

#ifndef P3AT_HERBERT_IVIRTUALDEVICEMANAGER_H
#define P3AT_HERBERT_IVIRTUALDEVICEMANAGER_H

#include <webots/types.h>
#include <memory>
#include <map>

class IDevice;

/// Maps IWbDeviceTags to IDevices using a std::map.
class IVirtualDeviceManager {
public:
    /// returns the device associated to the given tag
    /// returns nullptr if there is no associated device to the given tag
    virtual std::shared_ptr<IDevice> getDeviceByTag(WbDeviceTag tag) = 0;

    /// attaches device to the map
    virtual void attachDeviceToMap(WbDeviceTag tag, std::shared_ptr<IDevice> device) = 0;

    /// returns the complete map of the devices
    virtual std::map<WbDeviceTag, std::shared_ptr<IDevice>> getDevices() = 0;

    virtual ~IVirtualDeviceManager() = default;

protected:
    /// collection of all the devices associated with their tags
    std::map<WbDeviceTag, std::shared_ptr<IDevice>> devices;
};


#endif //P3AT_HERBERT_IVIRTUALDEVICEMANAGER_H
