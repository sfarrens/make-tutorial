# CMake Tutorial - Part 5

This tutorial demonstrates how to build multiple executables with CMake.

## Contents

1. [Source Code](#Source-Code)
1. [Example](#Example)

## Source Code

This tutorial makes use of the following code:

- `include/sphere_trig.hpp`: The sphere_trig header file.
- `include/print.hpp`: The print header file.
- `include/io.hpp`: The io header file.
- `lib/libsphere.a`: A static library made from the sphere_trig.o and print.o object files.
- `src/main.cpp`: A script that calculates the angular separation between Andromeda and the Horsehead nebula.
- `src/io.cpp`: Code that handles the FITS IO of a given file.
- `src/listheader.cpp`: A script that reads the header of a given FITS file.

## Example

For this example we will look at the file `CMakeLists.txt`.

Here we want to build multiple target executables. So, we begin by creating a list of targets.

```cmake
set(TARGET_LIST main listheader)
```

Since, both `main.cpp` and `listheader.cpp` have `main` methods, we need to
handle the building of the source files independently.

So, we can remove these files from the full list of source files.

```cmake
foreach(TARGET_NAME ${TARGET_LIST})
  list(REMOVE_ITEM SOURCES "src/${TARGET_NAME}.cpp")
endforeach(TARGET_NAME)
```

Then we can build each of the targets.

```cmake
foreach(TARGET_NAME ${TARGET_LIST})
  add_executable(${TARGET_NAME} ${SOURCES} "${PROJECT_SOURCE_DIR}/src/${TARGET_NAME}.cpp")
  target_link_libraries(${TARGET_NAME} ${CFITSIO_LIBRARIES} ${sphere_lib})
endforeach(TARGET_NAME)
```

Finally, we can specify that the executables be installed to `bin`.

```cmake
INSTALL(TARGETS ${TARGET_LIST} DESTINATION bin)
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
-- Build files have been written to: .../make-tutorial/cmake-part5/build
> make
Scanning dependencies of target listheader
[ 16%] Building CXX object CMakeFiles/listheader.dir/src/io.cpp.o
[ 33%] Building CXX object CMakeFiles/listheader.dir/src/listheader.cpp.o
[ 50%] Linking CXX executable listheader
[ 50%] Built target listheader
Scanning dependencies of target main
[ 66%] Building CXX object CMakeFiles/main.dir/src/io.cpp.o
[ 83%] Building CXX object CMakeFiles/main.dir/src/main.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
```

This will generate both the `main` and `listheader` executables.
