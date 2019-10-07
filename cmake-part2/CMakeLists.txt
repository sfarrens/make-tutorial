# Set the minumum version of CMake required
cmake_minimum_required(VERSION 3.0.0)

# Set the project name
project(cmake_part2)

  # Specify where header files are located
  include_directories(include)

  # List the source files
  aux_source_directory(src SOURCES)

  # Build the executable main
  add_executable(main ${SOURCES})
