//
// Created by karl on 13.05.19.
//

#include "P3AT.h"
#include "../Interfaces/IMotor.h"
#include "../Devices/Motor.h"
#include "../Devices/Sensor.h"

void P3AT::fillDeviceManager(std::shared_ptr<IVirtualDeviceManager> deviceManager) {
    leftWheels = std::dynamic_pointer_cast<IDevice>
            (std::make_shared<Motor>(Motor()));

    rightWheels = std::dynamic_pointer_cast<IDevice>
            (std::make_shared<Motor>(Motor()));

    insertEightSensors(frontSonarArray);
    insertEightSensors(backSonarArray);

    deviceManager->attachDeviceToMap(0, leftWheels);
    deviceManager->attachDeviceToMap(1, rightWheels);

    insertAll(deviceManager, frontSonarArray, 10);
    insertAll(deviceManager, backSonarArray, 20);
}

std::shared_ptr<IDevice> P3AT::getLeftWheels() {
    return leftWheels;
}

std::shared_ptr<IDevice> P3AT::getRightWheels() {
    return rightWheels;
}

std::list<std::shared_ptr<IDevice>> P3AT::getFrontSonarArray() {
    return frontSonarArray;
}

std::list<std::shared_ptr<IDevice>> P3AT::getBackSonarArray() {
    return backSonarArray;
}

void P3AT::insertEightSensors(std::list<std::shared_ptr<IDevice>> &sonarArray) {
    for (int i = 0; i < 8; i++) {
        auto sensor = std::dynamic_pointer_cast<IDevice>
                (std::make_shared<Sensor>(Sensor()));
        sonarArray.push_back(sensor);
    }
}

void P3AT::insertAll(const std::shared_ptr<IVirtualDeviceManager> &deviceManager,
                     const std::list<std::shared_ptr<IDevice>> &list, unsigned short startTag) {
    unsigned short index = startTag;

    for (const auto &device : list) {
        deviceManager->attachDeviceToMap(index, device);
        index++;
    }
}
