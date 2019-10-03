# Makefile Tutorial - Part 2

This tutorial demonstrates how to link libraries using a makefile.

## Contents

1. [Source Code](#Source-Code)
1. [Makefile](#Makefile)
   * [Example 1](#Example-1)
   * [Example 2](#Example-2)

## Source Code

This tutorial makes use of the following code:

- `lib/libsphere.a`: A static library made from the sphere_trig.o and print.o object files.
- `include/sphere_trig.hpp`: The sphere_trig.cpp header.
- `include/print.hpp`: The print.cpp header.
- `src/main.cpp`: A script that calculates the angular separation between Andromeda and the Horsehead nebula.

## Makefile

### Example 1

For the first example we will look at the file `makefile`.

Rather than compiling all of library functions from source, we want to be able to link pre-compiled libraries.

We start by adding variables to specify where our libraries and headers are located. We also need to specify which libraries we want to use. For this example we want to use `libsphere.a`, hence we should specify `-lsphere`, *i.e.* `-l` in place of `lib` and without a file extension.

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

### Example 2

For the first example we will look at the file `makefile2`.

For this example we look at a case where our code depends on an external library. A common library for coding projects that use astrophysical data is [CFITSIO](https://heasarc.gsfc.nasa.gov/fitsio/).

Note to run this example you will need to have CFITSIO installed. If you are running macOS this can be easily done using [Homebrew](https://brew.sh/).

```bash
> brew install cfitsio
```

We could easily hardwire the paths to the CFITSIO installation similarly to the first example. If we want to distribute our code, however, it would be better to make it easy for the user to specify the the paths.

First, we can specify which CFITSIO libraries we want to use and pass these to the full list of libraries we need for the project.

```make
CFITSIO_LIBS = -lcfitsio

LIBS = $(CFITSIO_LIBS)
```

Then, we can define variables that provide the paths to the library and header files.

```make
CFITSIO_LIB_DIR = $(CFITSIO_ROOT)/lib
CFITSIO_INCLUDE_DIR = $(CFITSIO_ROOT)/include

LIB_DIR = $(CFITSIO_LIB_DIR)
INCLUDE_DIR = $(CFITSIO_INCLUDE_DIR)
```

Note that these variables depend on an undefined variable `CFITSIO_ROOT`. This variable can be provided as an argument to the make command (*e.g.* for a Homebrew installation):

```bash
> make -f makefile2 CFITSIO_ROOT=/usr/local/Cellar/cfitsio/3.450_1
g++ -Wall -c src2/io.cpp -o build2/io.o -I /usr/local/Cellar/cfitsio/3.450_1/include
g++ -Wall -c src2/listheader.cpp -o build2/listheader.o -I /usr/local/Cellar/cfitsio/3.450_1/include
g++ -Wall -o build2/listheader build2/io.o build2/listheader.o -L/usr/local/Cellar/cfitsio/3.450_1/lib -lcfitsio
```

This will generate the executable `listheader` in the directory `build2`, which lists the header contents of a FITS file. An example FITS file is provided in `data`.

```bash
> ./build2/listheader data/example.fits
Header listing for HDU #1:
SIMPLE  =                    T / conforms to FITS standard
BITPIX  =                   64 / array data type
NAXIS   =                    1 / number of array dimensions
NAXIS1  =                  100
EXTEND  =                    T
END

```
