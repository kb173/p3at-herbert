#include <utility>

//
// Created by irena.ankerl on 30.04.2019.
//

#ifndef P3AT_HERBERT_IVIRTUALMOTORCONTROLLER_H
#define P3AT_HERBERT_IVIRTUALMOTORCONTROLLER_H

#include <webots/types.h>
#include "IVirtualDeviceManager.h"

/// Implements the required WeBots remote control functions for motors.
/// These functions should be mapped to the incoming WeBots calls.
class IVirtualMotorController {
public:
    IVirtualMotorController(std::shared_ptr<IVirtualDeviceManager> dm) : deviceManager(std::move(dm)) {};

    ///specifies a new target position that the PID-controller will attempt to reach using the current velocity, acceleration and motor torque/force parameters. The specified position is expressed in radian (rad)
    virtual void (wbr_motor_set_position)(WbDeviceTag tag, double position) = 0;

    ///specifies the acceleration that the PID-controller should use when trying to reach the specified velocity. The acceleration is expressed in radian per second squared (rad/s²)
    virtual void (wbr_motor_set_acceleration)(WbDeviceTag tag, double acceleration) = 0;

    ///specifies the velocity that a motor should reach while moving to the target position. The velocity is expressed in radian per second (rad/s)
    virtual void (wbr_motor_set_velocity)(WbDeviceTag tag, double velocity) = 0;

    virtual ~IVirtualMotorController() = default;

protected:
    std::shared_ptr<IVirtualDeviceManager> deviceManager;

};


#endif //P3AT_HERBERT_IVIRTUALMOTORCONTROLLER_H
