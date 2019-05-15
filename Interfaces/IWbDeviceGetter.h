//
// Created by karl on 14.05.19.
//

#ifndef P3AT_HERBERT_IWBDEVICEGETTER_H
#define P3AT_HERBERT_IWBDEVICEGETTER_H

#include <string>
#include <webots/types.h>


class IWbDeviceGetter {
public:
    virtual WbDeviceTag getByName(const std::string &) = 0;
};

#endif //P3AT_HERBERT_IWBDEVICEGETTER_H
