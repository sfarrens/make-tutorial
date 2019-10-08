# Makefile Tutorial - Part 2

This tutorial demonstrates how to link libraries using a makefile.

## Contents

1. [Source Code](#Source-Code)
1. [Example](#Example)

## Source Code

This tutorial makes use of the following code:

- `lib/libsphere.a`: A static library made from the sphere_trig.o and print.o object files.
- `include/sphere_trig.hpp`: The sphere_trig.cpp header.
- `include/print.hpp`: The print.cpp header.
- `src/main.cpp`: A script that calculates the angular separation between Andromeda and the Horsehead nebula.

## Example

For this example we will look at the file `makefile`.

Rather than compiling all the functionality our code uses, we want to be able to link pre-compiled libraries.

To begin, we need to generate a static library. We will pre-compile the functionality of `sphere_trig.cpp` and `print.cpp` from the previous example into a single static library called `libsphere.a`. To do so simply run the script `make_static_lib.sh`,

```bash
> make_static_lib.sh
```

which simply contains the following:

```bash
g++ -c ../make-part1/src/sphere_trig.cpp
g++ -c ../make-part1/src/print.cpp
ar rcs lib/libsphere.a sphere_trig.o print.o
ln -s $PWD/lib/libsphere.a ../cmake-part3/lib/libsphere.a
ln -s $PWD/lib/libsphere.a ../cmake-part5/lib/libsphere.a
rm sphere_trig.o print.o
```

Then we can add variables to our makefile that specify where our libraries and headers are located. We also need to specify which libraries we want to use. For this example we want to use `libsphere.a`, hence we should specify `-lsphere`, *i.e.* `-l` in place of `lib` and without a file extension.

```make
LIB_DIR = lib
LIBS = -lsphere
INCLUDE_DIR = include
```

Next, we add the library to our executable target compilation command.

```make
$(BUILD_DIR)/$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAG) -o $@ $^ -L$(LIB_DIR) $(LIBS)
```

Finally, we make sure to include the headers when building the `main.o` object.

```make
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)*
	$(CXX) $(CXXFLAG) -c $< -o $@ -I $(INCLUDE_DIR)
```

To run:

```bash
> make
g++ -Wall -c src/main.cpp -o build/main.o -I include
g++ -Wall -o build/main build/main.o -Llib -lsphere
```

and, as before:

```bash
> ./build/main
Hello there!
The angular separation between Andromeda and the Horsehead nebula is 80.1194 degrees.
```

---

> [Continue tutorial](../make-part3)

---
