cmake_minimum_required(VERSION 3.6)
project(ORACS)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp main.h solution/solution.cpp solution/solution.h depot/depot.cpp depot/depot.h vehicle/vehicle.cpp vehicle/vehicle.h solution/print.cpp route/route.cpp route/route.h vehicle/vehicle1.cpp customer/customer.cpp customer/customer.h)
add_executable(ORACS ${SOURCE_FILES})