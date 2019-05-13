//
// Created by karl on 30.04.19.
//

#ifndef P3AT_HERBERT_IP3AT_H
#define P3AT_HERBERT_IP3AT_H

#include <memory>
#include <list>
#include "IRobot.h"
#include "IDevice.h"

class IP3AT : public IRobot {
public:
    virtual void fillDeviceManager(std::shared_ptr<IVirtualDeviceManager> deviceManager) override = 0;

    /// @return The left wheels of the robot, which is of type IMotor (returned as shared pointer to an IDevice)
    virtual std::shared_ptr<IDevice> getLeftWheels() = 0;

    /// @return The right wheels of the robot, which is of type IMotor (returned as shared pointer to an IDevice)
    virtual std::shared_ptr<IDevice> getRightWheels() = 0;

    /// Returns all sonar devices in the front sonar array of the robot.
    /// Viewed from the front, they are laid out like this: 7 6 5 4 3 2 1 0
    /// @return A list of all sensors from right to left, which are of type ISensor (returned as shared pointers to IDevices)
    virtual std::list<std::shared_ptr<IDevice>> getFrontSonarArray() = 0;

    /// Returns all sonar devices in the back sonar array of the robot.
    /// Viewed from the front, they are laid out like this: 7 6 5 4 3 2 1 0
    /// @return A list of all sensors from right to left, which are of type ISensor (returned as shared pointers to IDevices)
    virtual std::list<std::shared_ptr<IDevice>> getBackSonarArray() = 0;
};

#endif //P3AT_HERBERT_IP3AT_H
