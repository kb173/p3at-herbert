//
// Created by Max on 09.05.2019.
//

#ifndef P3AT_HERBERT_VIRTUALDEVICEMANAGER_H
#define P3AT_HERBERT_VIRTUALDEVICEMANAGER_H

#include "../Interfaces/IVirtualDeviceManager.h"

class VirtualDeviceManager : public IVirtualDeviceManager {
public:
    /// returns the device associated to the given tag
    /// returns nullptr if there is no associated device to the given tag
    std::shared_ptr<IDevice> getDeviceByTag(WbDeviceTag tag) override;

    /// attaches device to the map
    void attachDeviceToMap(WbDeviceTag tag, std::shared_ptr<IDevice> device) override;

    /// returns the complete map of the devices
    std::map<WbDeviceTag, std::shared_ptr<IDevice>> getDevices() override;

protected:
    /// collection of all the devices associated with their tags
    std::map<WbDeviceTag, std::shared_ptr<IDevice>> devices;
};


#endif //P3AT_HERBERT_VIRTUALDEVICEMANAGER_H
