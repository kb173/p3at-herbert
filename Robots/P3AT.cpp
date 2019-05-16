//
// Created by karl on 13.05.19.
//

#include "P3AT.h"
#include "../Interfaces/IMotor.h"
#include "../Devices/Motor.h"
#include "../Devices/Sensor.h"

void P3AT::fillDeviceManager(std::shared_ptr<IVirtualDeviceManager> deviceManager,
                             std::shared_ptr<IWbDeviceGetter> deviceGetter) {
    leftWheels = std::dynamic_pointer_cast<IDevice>
            (std::make_shared<Motor>(Motor()));

    rightWheels = std::dynamic_pointer_cast<IDevice>
            (std::make_shared<Motor>(Motor()));

    insertEightSensors(frontSonarArray);
    insertEightSensors(backSonarArray);

    deviceManager->attachDeviceToMap(deviceGetter->getByName(LEFTWHEELSNAME), leftWheels);
    deviceManager->attachDeviceToMap(deviceGetter->getByName(RIGHTWHEELSNAME), rightWheels);

    insertAll(deviceManager, frontSonarArray, deviceGetter, 0);
    insertAll(deviceManager, backSonarArray, deviceGetter, 8);
}

std::shared_ptr<IDevice> P3AT::getLeftWheels() {
    return leftWheels;
}

std::shared_ptr<IDevice> P3AT::getRightWheels() {
    return rightWheels;
}

std::vector<std::shared_ptr<IDevice>> P3AT::getFrontSonarArray() {
    return frontSonarArray;
}

std::vector<std::shared_ptr<IDevice>> P3AT::getBackSonarArray() {
    return backSonarArray;
}

void P3AT::insertEightSensors(std::vector<std::shared_ptr<IDevice>> &sonarArray) {
    for (int i = 0; i < 8; i++) {
        auto sensor = std::dynamic_pointer_cast<IDevice>
                (std::make_shared<Sensor>(Sensor()));
        sonarArray.push_back(sensor);
    }
}

void P3AT::insertAll(const std::shared_ptr<IVirtualDeviceManager> &deviceManager,
                     const std::vector<std::shared_ptr<IDevice>> &list,
                     const std::shared_ptr<IWbDeviceGetter> &deviceGetter, unsigned short startTag) {
    unsigned short index = startTag;

    for (const auto &device : list) {
        deviceManager->attachDeviceToMap(deviceGetter->getByName(SENSORSNAME + std::to_string(index)), device);
        index++;
    }
}

double P3AT::getRadius() {
    return radius;
}

P3AT::P3AT(const double radius) : radius(radius) {}
