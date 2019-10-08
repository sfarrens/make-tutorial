# CMake Tutorial - Part 2

This tutorial demonstrates how to automatically find source files with CMake.

## Contents

1. [Source Code](#Source-Code)
1. [Example](#Example)

## Source Code

This tutorial makes use of the following code:

- `include/sphere_trig.hpp`: The sphere_trig header file.
- `include/print.hpp`: The print header file.
- `src/sphere_trig.cpp`: Some code for calculating the angular separation between two objects.
- `src/print.cpp`: Some code for printing a given angular separation.
- `src/main.cpp`: A script that calculates the angular separation between Andromeda and the Horsehead nebula.

## Example

For this example we will look at the file `CMakeLists.txt`.

To clean up our code, we can put the header files in a separate directory,

```cmake
include_directories(include)
```

and to simplify the build, we can automatically find all of the source files in the directory `src`,

```cmake
aux_source_directory(src SOURCES)
```

which can be built as before.

---

> [Continue tutorial](../cmake-part3)

---
