cmake_minimum_required(VERSION 3.12)
project(p3at_herbert CXX)

set(CMAKE_CXX_STANDARD 17)


add_library(p3at_herbert SHARED
        Controller/RealDeviceControllerComposite.cpp
        Controller/RealDeviceControllerComposite.h
        Interfaces/IRealDeviceController.h
        Interfaces/IRobot.h
        Interfaces/IP3AT.h
        Interfaces/IDevice.h
        Interfaces/IMotor.h
        Interfaces/ISensor.h
        Interfaces/IVirtualDeviceManager.h
        Interfaces/IVirtualMotorController.h
        Interfaces/IVirtualSensorController.h
        library.cpp
        Controller/VirtualMotorController.cpp
        Controller/VirtualMotorController.h
        library.h
        Controller/AriaController.cpp
        Controller/AriaController.h
        Devices/Motor.cpp
        Devices/Motor.h)

add_executable(tests
        tests.cpp
        Controller/ControllerTests.cpp)

include_directories("webots/include")
include_directories("Aria/include")
include_directories("Catch2/single_include/catch2")

target_link_libraries(tests p3at_herbert)
