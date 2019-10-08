# Set the minumum version of CMake required
cmake_minimum_required(VERSION 3.0.0)

# Include package finder
include(FindPkgConfig)

# Set the project name
project(cmake_part5)

  # Find the CFITSIO installation
  pkg_check_modules(CFITSIO REQUIRED cfitsio)

  # Find the sphere library
  find_library(sphere_lib NAMES sphere PATHS "${PROJECT_SOURCE_DIR}/lib")

  # Specify where header files are located
  include_directories(include ${CFITSIO_INCLUDE_DIRS})

  # Specify where library files are located
  link_directories(${CFITSIO_LIBRARY_DIRS})

  # List the source files
  aux_source_directory(src SOURCES)

  # Specify the name of the executable targets
  set(TARGET_LIST main listheader)

  # Remove target files from the source files
  foreach(TARGET_NAME ${TARGET_LIST})
    list(REMOVE_ITEM SOURCES "src/${TARGET_NAME}.cpp")
  endforeach(TARGET_NAME)

  # Build the executables and link the libraries
  foreach(TARGET_NAME ${TARGET_LIST})
  	add_executable(${TARGET_NAME} ${SOURCES} "${PROJECT_SOURCE_DIR}/src/${TARGET_NAME}.cpp")
  	target_link_libraries(${TARGET_NAME} ${CFITSIO_LIBRARIES} ${sphere_lib})
  endforeach(TARGET_NAME)

  # Set install destination
  INSTALL(TARGETS ${TARGET_LIST} DESTINATION bin)
