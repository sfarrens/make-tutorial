# Set the minumum version of CMake required
cmake_minimum_required(VERSION 3.0.0)

# Set the project name
project(cmake_part1)

  # Specify where header files are located
  include_directories(src)

  # List the source files
  set(SOURCES src/main.cpp src/print.cpp src/sphere_trig.cpp)

  # Build the executable main
  add_executable(main ${SOURCES})
