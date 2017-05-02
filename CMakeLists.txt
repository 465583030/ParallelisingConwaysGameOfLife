cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(ParallelisingConwaysGameOfLife)

#set(CMAKE_CXX_STANDARD 11)

option(test "Build all tests." ON)

#===============================================================================
# Find OpenMP
#-------------------------------------------------------------------------------
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

include_directories(testing/catch/include)
include_directories(code/conway_lib)

ADD_SUBDIRECTORY(code)

if (test)
    ADD_SUBDIRECTORY(testing)
endif()