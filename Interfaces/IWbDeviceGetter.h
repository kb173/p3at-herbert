//
// Created by karl on 14.05.19.
//

#ifndef P3AT_HERBERT_IWBDEVICEGETTER_H
#define P3AT_HERBERT_IWBDEVICEGETTER_H

#include <string>
#include <webots/types.h>

/// Wrapper for wb_robot_get_device. Talks to WeBots to map device names to WbDeviceTags.
class IWbDeviceGetter {
public:
    /// Gets the WbDeviceTag which corresponds to the given name.
    /// Used to keep device tags synchronized between here and WeBots.
    /// \param name The name which the device has in WeBots
    /// \return The WbDeviceTag which corresponds to this name according to WeBots
    virtual WbDeviceTag getByName(const std::string &name) = 0;
};

#endif //P3AT_HERBERT_IWBDEVICEGETTER_H
