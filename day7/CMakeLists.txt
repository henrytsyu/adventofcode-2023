cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
project(AdventOfCode)

# Add the executable targets for part 1 and part 2
add_executable(part1.exe part1.cpp)
add_executable(part2.exe part2.cpp)

# Copy input.txt to the build directory
configure_file(input.txt input.txt COPYONLY)
