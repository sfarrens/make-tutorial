# CMake Tutorial - Part 2

This tutorial introduces the basic concept of CMake.

## Contents

1. [Source Code](#Source-Code)
1. [CMake Syntax](#CMake-Syntax)
1. [Makefile](#Makefile)
   * [Example](#Example)

## Source Code

This tutorial makes use of the following code:

- `src/sphere_trig.cpp`: Some code for calculating the angular separation between two objects.
- `include/sphere_trig.hpp`: The corresponding header file.
- `src/print.cpp`: Some code for printing a given angular separation.
- `include/print.hpp`: The corresponding header file.
- `src/main.cpp`: A script that calculates the angular separation between Andromeda and the Horsehead nebula.

## CMake

### Example

For this example we will look at the file `CMakeLists.txt`.

To simplify the build, we can automatically find all of the source files in the directory `src`.

```cmake
aux_source_directory(src SOURCES)
```
