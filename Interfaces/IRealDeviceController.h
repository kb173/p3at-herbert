//
// Created by Mathias on 30.04.2019.
//

#ifndef P3AT_HERBERT_IREALDEVICECONTROLLER_H
#define P3AT_HERBERT_IREALDEVICECONTROLLER_H

/// Interface for the mandatory functions which every RealDeviceController requires
/// find more Information: https://www.cyberbotics.com/doc/guide/controller-plugin

class IRealDeviceController {
public:

    /// This function is called when the connection with the real robot should start.
    /// The return value of this function should inform if the connection has been a success or not.
    /// The argument matches with the argument given to the wb_robot_set_mode function when initializing the remote-control.
    /// As the robot window library is often responsible for calling the wb_robot_set_mode function,
    /// the structure passed between them should match.
    /// @param arg
    /// @return hasConnected

    virtual bool start (void *arg) = 0;

    /// This function is called when the connection with the real robot should stop.
    /// Typically a command stopping the real robot actuators should be sent just before stopping the connection.

    virtual void stop () = 0;

    /// This function is called very often by libController to check the validity of the connection.
    /// The value returned by this function should always match with the connection validity.
    /// @return hasFailed

    virtual bool hasFailed () = 0;

    /// This function is called to stop the actuators of the real robot.
    /// This is called when the user pressed the pause button of the simulator.

    virtual void stopActuators () = 0;

    /// This function is called when the controller enters in the step loop.
    /// The aim of this function is to send the actuator commands and then to read the vaues of the enabled sensors.
    /// The timing problem should be solved there.
    /// The robot should wait at least period milliseconds, and return the delta time if this period is exceeded.
    /// @param period
    /// @return deltaTime

    virtual int robotStep (int period) = 0;
};

#endif //P3AT_HERBERT_IREALDEVICECONTROLLER_H
