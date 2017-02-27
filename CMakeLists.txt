cmake_minimum_required(VERSION 3.6)
project(ORACS)

set(CMAKE_CXX_STANDARD 14)
include_directories(./inc)

set(SOURCE_FILES src/main.cpp inc/main.h src/solution/solution.cpp inc/solution.h src/depot/depot.cpp inc/depot.h src/vehicle/vehicle.cpp inc/vehicle.h src/solution/print.cpp src/route/route.cpp inc/route.h src/vehicle/vehicle1.cpp src/customer/customer.cpp inc/customer.h)
add_executable(ORACS ${SOURCE_FILES})