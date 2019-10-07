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
- `lib/libsphere.a`: A static library made from the sphere_trig.o and print.o object files.
- `src/main.cpp`: A script that calculates the angular separation between Andromeda and the Horsehead nebula.

## CMake

### Example

For this example we will look at the file `CMakeLists.txt`.

Here we locate the `libsphere.a` library.

```cmake
find_library(sphere_lib NAMES sphere PATHS "${PROJECT_SOURCE_DIR}/lib")
```

Then we link that library to the `main` executable.

```cmake
target_link_libraries(main ${sphere_lib})
```
