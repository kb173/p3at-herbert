//
// Created by karl on 30.04.19.
//

#ifndef P3AT_HERBERT_REALDEVICECONTROLLERCOMPOSITE_H
#define P3AT_HERBERT_REALDEVICECONTROLLERCOMPOSITE_H


#include <list>
#include <memory>
#include "../Interfaces/IRealDeviceController.h"

class RealDeviceControllerComposite : public IRealDeviceController {
public:
    void addController(std::shared_ptr<IRealDeviceController> controller);

    bool start(void *arg) override;

    void stop() override;

    bool hasFailed() override;

    void stopActuators() override;

    int robotStep(int period) override;

protected:
    std::list<std::shared_ptr<IRealDeviceController>> controllers;

};


#endif //P3AT_HERBERT_REALDEVICECONTROLLERCOMPOSITE_H
