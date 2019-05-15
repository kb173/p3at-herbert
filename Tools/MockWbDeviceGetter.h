//
// Created by karl on 15.05.19.
//

#ifndef P3AT_HERBERT_MOCKWBDEVICEGETTER_H
#define P3AT_HERBERT_MOCKWBDEVICEGETTER_H


#include "../Interfaces/IWbDeviceGetter.h"

class MockWbDeviceGetter : public IWbDeviceGetter {
public:
    WbDeviceTag getByName(const std::string &string) override;

};


#endif //P3AT_HERBERT_MOCKWBDEVICEGETTER_H
