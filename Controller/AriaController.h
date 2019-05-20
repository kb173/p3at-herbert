//
// Created by mathias on 30.04.19.
//

#ifndef P3AT_HERBERT_ARIACONTROLLER_H
#define P3AT_HERBERT_ARIACONTROLLER_H

#include "Aria.h"
#include "../Interfaces/IRealDeviceController.h"
#include "../Interfaces/IP3AT.h"

/// Has functions to actually set and apply the data to and from the real robot, does this in the tick function
/// For examples look at: https://github.com/cinvesrob/Aria/blob/master/examples/
/// e.g. simpleMotionCommands.cpp

class AriaController : public IRealDeviceController {
public:

    AriaController(std::shared_ptr<IP3AT> virtualRobot);

    bool start(void *arg) override;

    void stop() override;

    bool hasFailed() override;

    void stopActuators() override;

    int robotStep(int period) override;

private:
    void fillSonarDevices(std::vector<std::shared_ptr<IDevice>> &virtualSonarVector, double startAngle, int multiplier);

    ArRobot realRobot;
    ArSonarDevice sonarInitializer;
    ArSonarDevice sonarInitializer2;
    std::shared_ptr<ArArgumentParser> argParser;
    bool connectionStopped = false;
    std::shared_ptr<IP3AT> virtualRobot;
    std::shared_ptr<ArRangeDevice> realSonar;
    std::shared_ptr<ArRobotConnector> robotConnector;
    std::shared_ptr<ArSonarConnector> sonarConnector;
};


#endif //P3AT_HERBERT_ARIACONTROLLER_H

