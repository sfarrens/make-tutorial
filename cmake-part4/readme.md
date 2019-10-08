# CMake Tutorial - Part 4

This tutorial demonstrates how to find an external module using CMake.

## Contents

1. [Source Code](#Source-Code)
1. [Example](#Example)

## Source Code

This tutorial makes use of the following code:

- `include/io.hpp`: The io header file.
- `src/io.cpp`: Code that handles the FITS IO of a given file.
- `src/listheader.cpp`: A script that reads the header of a given FITS file.

## Example

For this example we will look at the file `CMakeLists.txt`.

Here we automatically locate the CFITSIO installation

```cmake
pkg_check_modules(CFITSIO REQUIRED cfitsio)
```

and then make use of the variables that are defined.

```cmake
include_directories(include ${CFITSIO_INCLUDE_DIRS})

link_directories(${CFITSIO_LIBRARY_DIRS})

add_executable(listheader ${SOURCES})

target_link_libraries(listheader ${CFITSIO_LIBRARIES})
```

To build:

```bash
> cd build
> cmake ..
-- Found PkgConfig: /usr/local/bin/pkg-config (found version "0.29.2")
-- The C compiler identification is AppleClang 11.0.0.11000033
-- The CXX compiler identification is AppleClang 11.0.0.11000033
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Checking for module 'cfitsio'
--   Found cfitsio, version 3.45
-- Configuring done
-- Generating done
-- Build files have been written to: .../make-tutorial/cmake-part4/build
> make
[ 33%] Building CXX object CMakeFiles/listheader.dir/src/io.cpp.o
[ 66%] Building CXX object CMakeFiles/listheader.dir/src/listheader.cpp.o
[100%] Linking CXX executable listheader
[100%] Built target listheader
```

> Note that CMake found version 3.45 of CFITSIO. If you have a local installation of CFITIO it may be necessary to specify the path to the `.pc` file with the `PKG_CONFIG_PATH` system variable.

This will build the executable `listheader`, which can be run as follows:

```bash
> ./listheader ../../data/example.fits
Header listing for HDU #1:
SIMPLE  =                    T / conforms to FITS standard
BITPIX  =                   64 / array data type
NAXIS   =                    1 / number of array dimensions
NAXIS1  =                  100
EXTEND  =                    T
END
```

---

> [Continue tutorial](../cmake-part5)

---
