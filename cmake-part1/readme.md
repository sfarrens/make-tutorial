# CMake Tutorial - Part 1

This tutorial introduces the basic concept of CMake.

Now that you are familiar with makefiles, you can start using software that builds them for you!

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

Instead of directly writing a makefile, for a CMake project you will create a file called `CMakeLists.txt`, which is run using the command `cmake`. This in turn will generate a makefile for your project that is run in the usually way with `make`.

Unlike make, which is native to most UNIX environments, CMake needs to be installed.

*e.g.* for Ubuntu:

```bash
> sudo apt-get -y install cmake
```

*e.g.* for macOS using [Homebrew](https://brew.sh/):

```bash
> brew install cmake
```


### Example

For this example we will look at the file `CMakeLists.txt`.

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

To build the project run (*e.g.* with macOS output):

```bash
> cd build
> cmake ..
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
-- Configuring done
-- Generating done
-- Build files have been written to: .../make-tutorial/cmake-part1/build
```

then:

```bash
> make
Scanning dependencies of target main
[ 25%] Building CXX object CMakeFiles/main.dir/src/main.cpp.o
[ 50%] Building CXX object CMakeFiles/main.dir/src/print.cpp.o
[ 75%] Building CXX object CMakeFiles/main.dir/src/sphere_trig.cpp.o
[100%] Linking CXX executable main
[100%] Built target main
```

which will produce the executable `main` that can be run as follows:

```bash
> ./main
Hello there!
The angular separation between Andromeda and the Horsehead nebula is 80.1194 degrees.
```

As with standard make, CMake tracks updates to individual source files, *e.g.*

```bash
> touch ../src/print.cpp
> make
Scanning dependencies of target main
[ 25%] Building CXX object CMakeFiles/main.dir/src/print.cpp.o
[ 50%] Linking CXX executable main
[100%] Built target main
```

and build files can be removed with `clean`.

```bash
> make clean
```

---

> [Continue tutorial](../cmake-part2)

---
