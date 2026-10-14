cmake_minimum_required(VERSION 3.10)

project(Lab00)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")

add_executable(Konrad_Machowski ${SOURCES})

target_include_directories(Konrad_Machowski PRIVATE include)