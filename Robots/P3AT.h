//
// Created by karl on 13.05.19.
//

#ifndef P3AT_HERBERT_P3AT_H
#define P3AT_HERBERT_P3AT_H


#include "../Interfaces/IP3AT.h"

class P3AT : public IP3AT {
public:

    explicit P3AT(double radius);

    void
    fillDeviceManager(std::shared_ptr<IVirtualDeviceManager> deviceManager,
                      std::shared_ptr<IWbDeviceGetter> deviceGetter) override;

    double getRadius() override;

    std::shared_ptr<IDevice> getLeftWheels() override;

    std::shared_ptr<IDevice> getRightWheels() override;

    std::vector<std::shared_ptr<IDevice>> getFrontSonarArray() override;

    std::vector<std::shared_ptr<IDevice>> getBackSonarArray() override;

private:
    static void insertEightSensors(std::vector<std::shared_ptr<IDevice>> &);

    void
    insertAll(const std::shared_ptr<IVirtualDeviceManager> &deviceManager,
              const std::vector<std::shared_ptr<IDevice>> &list,
              const std::shared_ptr<IWbDeviceGetter> &deviceGetter, unsigned short startTag);

    const double radius;

    std::shared_ptr<IDevice> leftWheels;

    std::shared_ptr<IDevice> rightWheels;

    std::vector<std::shared_ptr<IDevice>> frontSonarArray;

    std::vector<std::shared_ptr<IDevice>> backSonarArray;

    const std::string LEFTWHEELSNAME = "front left wheel";

    const std::string RIGHTWHEELSNAME = "front right wheel";

    const std::string SENSORSNAME = "so";

};


#endif //P3AT_HERBERT_P3AT_H
