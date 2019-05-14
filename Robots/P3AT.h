//
// Created by karl on 13.05.19.
//

#ifndef P3AT_HERBERT_P3AT_H
#define P3AT_HERBERT_P3AT_H


#include "../Interfaces/IP3AT.h"

class P3AT : public IP3AT {
public:
    // TODO: We probably need to keep those tags synchronized with group 17?
    /// The layout of the devices will look like this:
    /// 0: Left wheels
    /// 1: Right wheels
    /// 10-17: Front sonar array
    /// 20-27: Back sonar array
    void fillDeviceManager(std::shared_ptr<IVirtualDeviceManager> deviceManager) override;

    std::shared_ptr<IDevice> getLeftWheels() override;

    std::shared_ptr<IDevice> getRightWheels() override;

    std::list<std::shared_ptr<IDevice>> getFrontSonarArray() override;

    std::list<std::shared_ptr<IDevice>> getBackSonarArray() override;

private:
    static void insertEightSensors(std::list<std::shared_ptr<IDevice>> &);

    static void
    insertAll(const std::shared_ptr<IVirtualDeviceManager> &deviceManager, const std::list<std::shared_ptr<IDevice>> &,
              unsigned short);

    std::shared_ptr<IDevice> leftWheels;

    std::shared_ptr<IDevice> rightWheels;

    std::list<std::shared_ptr<IDevice>> frontSonarArray;

    std::list<std::shared_ptr<IDevice>> backSonarArray;

};


#endif //P3AT_HERBERT_P3AT_H
