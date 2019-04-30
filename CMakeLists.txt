cmake_minimum_required(VERSION 3.12)
project(p3at_herbert CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(p3at_herbert SHARED Interfaces/IRealDeviceController.h Interfaces/IRobot.h Interfaces/IP3AT.h library.cpp library.h Interfaces/IDevice.h Interfaces/IVirtualDeviceManager.cpp Interfaces/IVirtualDeviceManager.h Controller/RealDeviceControllerComposite.cpp Controller/RealDeviceControllerComposite.h)

add_executable(tests tests.cpp Controller/RealDeviceControllerComposite.cpp Controller/RealDeviceControllerComposite.h)

include_directories("webots/include")
include_directories("Aria/include")
include_directories("Catch2/single_include/catch2")

target_link_libraries(tests p3at_herbert)
