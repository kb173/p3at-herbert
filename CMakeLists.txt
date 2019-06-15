cmake_minimum_required(VERSION 3.12)
project(p3at_herbert CXX)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS -pthread)

set(WEBOTS_HOME /usr/local/webots)

set(WEBOTS_INCLUDE
        ${WEBOTS_HOME}/include/controller/c
        )

file(GLOB webots_libs
        "${WEBOTS_HOME}/lib/*.so*"
        )

find_library(WEBOTS_CONTROLLER_LIB Controller ${WEBOTS_HOME}/lib)

link_directories(${WEBOTS_HOME}/lib)
link_libraries(${webots_libs})

function(DisableCompilingPlatformSpecificSources file_list)
    foreach (file ${file_list})
        if (
        ((${file} MATCHES "^(.*)_WIN\\.cpp") AND NOT WIN32) OR
        ((${file} MATCHES "^(.*)_LIN\\.cpp") AND NOT UNIX)
        )
            set_source_files_properties(
                    ${file}
                    PROPERTIES HEADER_FILE_ONLY TRUE
            )
        endif ()
    endforeach ()
endfunction()

file(GLOB_RECURSE source_files
        "Aria/src/*.cpp"
        )

DisableCompilingPlatformSpecificSources("${source_files}")

add_library(p3at_herbert SHARED
        ${source_files}
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
        Controller/AriaController.cpp
        Controller/AriaController.h
        Controller/VirtualMotorController.cpp
        Controller/VirtualMotorController.h
        Devices/Motor.cpp
        Devices/Motor.h
        Manager/VirtualDeviceManager.cpp
        Manager/VirtualDeviceManager.h
        Robots/P3AT.cpp
        Robots/P3AT.h
        Devices/Sensor.cpp
        Tools/WbDeviceGetter.cpp
        Tools/WbDeviceGetter.h
        Interfaces/IWbDeviceGetter.h
        Devices/Sensor.h
        Controller/VirtualSensorController.cpp
        Controller/VirtualSensorController.h
        Tools/Converter.cpp
        Tools/Converter.h
        Interfaces/IConverter.h
        Tools/MockWbDeviceGetter.cpp
        Tools/MockWbDeviceGetter.h
        entry_points.cpp
        Wrapper.cpp
        Wrapper.h entry_points.hpp)

add_executable(tests
        tests.cpp
        Devices/DeviceTests.cpp
        Robots/RobotTests.cpp
        Manager/ManagerTest.cpp
        Tools/ToolTests.cpp)

add_executable(real_robot_test
        main.cpp)

target_link_libraries(tests ${CMAKE_DL_LIBS})
target_link_libraries(real_robot_test ${CMAKE_DL_LIBS})
include_directories(Aria/include)
include_directories(Catch2/single_include/catch2)
include_directories(${WEBOTS_INCLUDE})
include_directories(webots/include)

target_link_libraries(tests p3at_herbert)
target_link_libraries(real_robot_test p3at_herbert)