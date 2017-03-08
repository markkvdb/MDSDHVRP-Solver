cmake_minimum_required(VERSION 3.6)
project(ORACS)

set(CMAKE_CXX_STANDARD 14)
include_directories(./inc)

set(SOURCE_FILES src/main.cpp inc/main.h src/solution/solution.cpp inc/solution.h src/depot/depot.cpp inc/depot.h src/vehicle/vehicle.cpp inc/vehicle.h src/solution/print.cpp src/route/route.cpp inc/route.h src/vehicle/vehicle1.cpp src/customer/customer.cpp inc/customer.h inc/init.h src/init/init.cpp src/init/showmatrix.cpp src/init/showvehiclematrix.cpp src/init/showdepotmatrix.cpp src/init/showcustomermatrix.cpp src/init/createdistancematrix.cpp src/init/distance.cpp src/init/showdistancematrix.cpp inc/solution.h src/customer/operatoroutput.cpp src/route/traveldistance.cpp src/env/env.cpp inc/env.h src/env/env1.cpp src/solver/solver.cpp inc/solver.h src/solver/initialsolution.cpp src/solver/allocatecustomer.cpp src/solver/getclosestdepots.cpp src/solver/sortvehiclelist.cpp src/solver/assignroutetovehicle.cpp src/solver/addcustomer.cpp src/solver/getclosestcustomer.cpp src/solver/cheapestinsertion.cpp src/route/updatedistance.cpp src/route/updateservicetime.cpp src/route/updateload.cpp src/depot/operatoroutput.cpp src/vehicle/operatoroutput.cpp src/solver/print.cpp src/route/operatoroutput.cpp src/solution/totalcost.cpp src/solution/solution1.cpp)
add_executable(ORACS ${SOURCE_FILES})