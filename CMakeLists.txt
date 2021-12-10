cmake_minimum_required (VERSION 3.8)

project(classwork-03)

set(CMAKE_CXX_STANDARD 11)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX") # CMake already contains W3 in its flags
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

include_directories(src)

add_executable(day_1 src/day_1/sonar_sweep.cpp)
add_executable(day_2 src/day_2/dive.cpp)
add_executable(day_3 src/day_3/binary_diagnostics.cpp)
add_executable(day_4 src/day_4/bingo.cpp)
add_executable(day_5 src/day_5/hydrothermal_venture.cpp)
add_executable(day_6 src/day_6/lanternfish.cpp)
add_executable(day_7 src/day_7/crab_fuel.cpp)
add_executable(day_8 src/day_8/seven_segments.cpp)
add_executable(day_9 src/day_9/smoke_basin.cpp)
add_executable(day_10 src/day_10/syntax_scoring.cpp)

