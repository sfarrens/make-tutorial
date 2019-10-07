# Set the minumum version of CMake required
cmake_minimum_required(VERSION 3.0.0)

# Set the project name
project(cmake_part3)

  # Specify where header files are located
  include_directories(include)

  # List the source files
  aux_source_directory(src SOURCES)

  # Find the sphere library
  find_library(sphere_lib NAMES sphere PATHS "${PROJECT_SOURCE_DIR}/lib")

  # Build the executable main
  add_executable(main ${SOURCES})

  # Link the library to the executable
  target_link_libraries(main ${sphere_lib})
