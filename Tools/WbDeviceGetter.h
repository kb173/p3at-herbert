//
// Created by karl on 14.05.19.
//

#ifndef P3AT_HERBERT_WBDEVICEGETTER_H
#define P3AT_HERBERT_WBDEVICEGETTER_H


#include "../Interfaces/IWbDeviceGetter.h"

class WbDeviceGetter : public IWbDeviceGetter {
public:
    WbDeviceTag getByName(const std::string &name) override;
};


#endif //P3AT_HERBERT_WBDEVICEGETTER_H
