#include <utility>

//
// Created by karl on 09.05.19.
//

#ifndef P3AT_HERBERT_VIRTUALMOTORCONTROLLER_H
#define P3AT_HERBERT_VIRTUALMOTORCONTROLLER_H


#include "../Interfaces/IVirtualMotorController.h"

class VirtualMotorController : public IVirtualMotorController {
public:
    VirtualMotorController(std::shared_ptr<IVirtualDeviceManager> dm) : IVirtualMotorController(std::move(dm)) {};

    void setPosition(WbDeviceTag tag, double position) override;

    void setAcceleration(WbDeviceTag tag, double acceleration) override;

    void setVelocity(WbDeviceTag tag, double velocity) override;

};


#endif //P3AT_HERBERT_VIRTUALMOTORCONTROLLER_H
