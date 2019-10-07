# CMake Tutorial - Part 3

This tutorial introduces the basic concept of CMake.

## Contents

1. [Source Code](#Source-Code)
1. [CMake Syntax](#CMake-Syntax)
1. [Makefile](#Makefile)
   * [Example](#Example)

## Source Code

This tutorial makes use of the following code:

- `src/io.cpp`: Code that handles the FITS IO of a given file.
- `src/io.hpp`: The corresponding header file.
- `src/listheader.cpp`: A script that reads the header of a given FITS file.

## CMake

### Example

For this example we will look at the file `CMakeLists.txt`.

Here we automatically locate the CFITSIO installation

```cmake
pkg_check_modules(CFITSIO REQUIRED cfitsio)
```

and then make use of the variables that are defined.

```cmake
include_directories(${CFITSIO_INCLUDE_DIRS})

add_executable(listheader ${SOURCES})

target_link_libraries(listheader ${CFITSIO_LIBRARIES})
```
