# Set the minumum version of CMake required
cmake_minimum_required(VERSION 3.0.0)

# Include package finder
include(FindPkgConfig)

# Set the project name
project(cmake_part4)

  # Find the CFITSIO installation
  pkg_check_modules(CFITSIO REQUIRED cfitsio)

  # Specify where header files are located
  include_directories(include ${CFITSIO_INCLUDE_DIRS})

  # Specify where library files are located
  link_directories(${CFITSIO_LIBRARY_DIRS})

  # List the source files
  aux_source_directory(src SOURCES)

  # Build the executable main
  add_executable(listheader ${SOURCES})

  # Link the library to the executable
  target_link_libraries(listheader ${CFITSIO_LIBRARIES})
