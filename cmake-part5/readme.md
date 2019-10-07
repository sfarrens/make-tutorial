# CMake Tutorial - Part 3

This tutorial introduces the basic concept of CMake.

## Contents

1. [Source Code](#Source-Code)
1. [CMake Syntax](#CMake-Syntax)
1. [Makefile](#Makefile)
   * [Example](#Example)

## Source Code

This tutorial makes use of the following code:

- `include/sphere_trig.hpp`: The sphere_trig header file.
- `include/print.hpp`: The print header file.
- `include/io.hpp`: The io header file.
- `lib/libsphere.a`: A static library made from the sphere_trig.o and print.o object files.
- `src/main.cpp`: A script that calculates the angular separation between Andromeda and the Horsehead nebula.
- `src/io.cpp`: Code that handles the FITS IO of a given file.
- `src/listheader.cpp`: A script that reads the header of a given FITS file.

## CMake

### Example

For this example we will look at the file `CMakeLists.txt`.

For this example we want to build multiple target executables.

So, we begin by creating a list of targets.

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
