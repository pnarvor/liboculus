cmake_minimum_required(VERSION 3.10)
project(liboculus_tool VERSION 0.1)

find_package(CLI11 REQUIRED)

add_executable(oculus_client
    oculus_client.cpp
)
target_link_libraries(oculus_client PRIVATE
    liboculus
    CLI11::CLI11
)
