cmake_minimum_required(VERSION 3.5)
project(liboculus VERSION 0.1)

find_package(g3log REQUIRED)
find_package(active_object REQUIRED)
# find_package(Boost

list(APPEND liboculus_headers
    include/liboculus/BearingData.h
    include/liboculus/DataRx.h
    include/liboculus/DataTypes.h
    include/liboculus/ImageData.h
    include/liboculus/IoServiceThread.h
    include/liboculus/SimplePingResult.h
    include/liboculus/SonarClient.h
    include/liboculus/SonarConfiguration.h
    include/liboculus/SonarPlayer.h
    include/liboculus/SonarStatus.h
    include/liboculus/StatusRx.h
)

add_library(liboculus SHARED
    lib/DataRx.cpp
    lib/SimplePingResult.cpp
    lib/SonarClient.cpp
    lib/SonarConfiguration.cpp
    lib/SonarPlayer.cpp
    lib/SonarStatus.cpp
    lib/StatusRx.cpp
)
set_target_properties(liboculus PROPERTIES
    PUBLIC_HEADER "${liboculus_headers}"
)
target_include_directories(liboculus PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/liboculus/thirdparty>
    $<INSTALL_INTERFACE:include/libocolus/thirdparty>
)
target_link_libraries(liboculus PUBLIC
    g3log
    active_object
)

add_subdirectory(tools)


