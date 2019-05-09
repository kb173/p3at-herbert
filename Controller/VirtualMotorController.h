#include <utility>

//
// Created by karl on 09.05.19.
//

#ifndef P3AT_HERBERT_VIRTUALMOTORCONTROLLER_H
#define P3AT_HERBERT_VIRTUALMOTORCONTROLLER_H


#include "../Interfaces/IVirtualMotorController.h"

class VirtualMotorController : IVirtualMotorController{
public:
    VirtualMotorController(std::shared_ptr<IVirtualDeviceManager> dm) : IVirtualMotorController(std::move(dm)) {};

    void wbr_motor_set_position(WbDeviceTag tag, double position) override;

    void wbr_motor_set_acceleration(WbDeviceTag tag, double acceleration) override;

    void wbr_motor_set_velocity(WbDeviceTag tag, double velocity) override;

};


#endif //P3AT_HERBERT_VIRTUALMOTORCONTROLLER_H
