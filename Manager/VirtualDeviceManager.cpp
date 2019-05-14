//
// Created by Max on 09.05.2019.
//

#include "VirtualDeviceManager.h"


std::shared_ptr<IDevice> VirtualDeviceManager::getDeviceByTag(WbDeviceTag tag)
{
    if(devices.count(tag) > 0)
    {
        return devices[tag];
    }else
    {
        return nullptr;
    }
}

void VirtualDeviceManager::attachDeviceToMap(WbDeviceTag tag, std::shared_ptr<IDevice> device)
{
    if(devices.count(tag) > 0)
    {
        devices[tag]=device;
    }else
    {
        devices.insert({tag, device});
    }

}

std::map<WbDeviceTag,std::shared_ptr<IDevice>> VirtualDeviceManager::getDevices()
{
    return devices;
}