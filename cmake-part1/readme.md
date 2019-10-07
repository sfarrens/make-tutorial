# CMake Tutorial - Part 1

This tutorial introduces the basic concept of CMake.

## Contents

1. [Source Code](#Source-Code)
1. [CMake Syntax](#CMake-Syntax)
1. [Makefile](#Makefile)
   * [Example](#Example)

## CMake Syntax

This tutorial makes use of the following CMake tools:

- [`cmake_minimum_required`](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html): Set minimum CMake version number.
- [`project`](https://cmake.org/cmake/help/v3.15/command/project.html): Set project name.
- [`include_directories`](https://cmake.org/cmake/help/latest/command/include_directories.html): Specify path to header files.
- [`add_executable`](https://cmake.org/cmake/help/latest/command/add_executable.html): Specify executable target.
- [`set`](https://cmake.org/cmake/help/latest/command/set.html): Define a variable.
- [`aux_source_directory`](https://cmake.org/cmake/help/latest/command/aux_source_directory.html): Find all source files in a directory.
- [`find_library`](https://cmake.org/cmake/help/latest/command/find_library.html): Find a library.
- [`target_link_libraries`](https://cmake.org/cmake/help/latest/command/target_link_libraries.html): Link libraries to executable.
- [`pkg_check_modules`](https://cmake.org/cmake/help/v3.15/module/FindPkgConfig.html): Look for a CMake module.
- [`foreach`/`endforeach`](https://cmake.org/cmake/help/latest/command/foreach.html): Loop through a list.
- [`list`](https://cmake.org/cmake/help/latest/command/list.html): Perform list operations.
- [`install`](https://cmake.org/cmake/help/latest/command/install.html): Install executables to given destination.


> More information on [CMake Syntax](https://cmake.org/cmake/help/v3.0/manual/cmake-language.7.html)

## Source Code

This tutorial makes use of the following code:

- `src/sphere_trig.cpp`: Some code for calculating the angular separation between two objects.
- `src/sphere_trig.hpp`: The corresponding header file.
- `src/print.cpp`: Some code for printing a given angular separation.
- `src/print.hpp`: The corresponding header file.
- `src/main.cpp`: A script that calculates the angular separation between Andromeda and the Horsehead nebula.

## CMake

### Example

For the first example we will look at the file `CMakeLists.txt`.

We start by specifying a minimum version of `3.0.0` for CMake

```cmake
cmake_minimum_required(VERSION 3.0.0)
```

and a name for the project.

```cmake
project(cmake_part1)
```

Next, we specify that header files are located in `src`.

```cmake
include_directories(src)
```

Then, we explicitly list the source files.

```cmake
set(SOURCES src/main.cpp src/print.cpp src/sphere_trig.cpp)
```

Finally, we build the executable `main` from these source files.

```cmake
add_executable(main ${SOURCES})
```
