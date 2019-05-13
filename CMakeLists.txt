cmake_minimum_required(VERSION 3.12)
project(p3at_herbert CXX)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS -pthread)


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
        library.h
        Controller/AriaController.cpp
        Controller/AriaController.h
        Controller/VirtualMotorController.cpp
        Controller/VirtualMotorController.h
        Devices/Motor.cpp
        Devices/Motor.h Manager/VirtualDeviceManager.cpp
        Manager/VirtualDeviceManager.h
        Robots/P3AT.cpp
        Robots/P3AT.h
        Devices/Sensor.cpp
        Devices/Sensor.h )

function (DisableCompilingPlatformSpecificSources file_list)
    foreach(file ${file_list})
        if (
            ((${file} MATCHES "^(.*)_WIN\\.cpp") AND NOT WIN32) OR
            ((${file} MATCHES "^(.*)_LIN\\.cpp") AND NOT UNIX)
        )
            set_source_files_properties(
                    ${file}
                    PROPERTIES HEADER_FILE_ONLY TRUE
            )
        endif()
    endforeach()
endfunction()

file(GLOB_RECURSE source_files
        "Aria/src/*.cpp"
        )

DisableCompilingPlatformSpecificSources("${source_files}")

add_executable(tests
        ${source_files}
        tests.cpp
        Controller/ControllerTests.cpp
        Robots/RobotTests.cpp)

target_link_libraries(tests ${CMAKE_DL_LIBS})

include_directories(webots/include)
include_directories(Aria/include)
include_directories(Catch2/single_include/catch2)

target_link_libraries(tests p3at_herbert)
