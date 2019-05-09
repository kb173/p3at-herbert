//
// Created by Max on 30.04.2019.
//

#ifndef P3AT_HERBERT_IVIRTUALDEVICEMANAGER_H
#define P3AT_HERBERT_IVIRTUALDEVICEMANAGER_H

#include "controller/c/webots/types.h"
#include <memory>
#include <map>

///
/// IVirtualDeviceManager stores a collection of all the devices within a std::map
/// It has a method getDeviceByTag() that returns a device for a given tag;
///

class IDevice;

class IVirtualDeviceManager {
public:
    /// returns the device associated to the given tag
    virtual std::shared_ptr<IDevice> getDeviceByTag(WbDeviceTag tag) = 0;

    /// attaches device to the map
    /// returns true if everything worked
    /// returns false if not
    virtual bool attachDeviceToMap(WbDeviceTag tag, std::shared_ptr<IDevice> device) = 0;
protected:
    /// collection of all the devices associated with their tags
    std::map<WbDeviceTag,std::shared_ptr<IDevice>> devices;
};


#endif //P3AT_HERBERT_IVIRTUALDEVICEMANAGER_H