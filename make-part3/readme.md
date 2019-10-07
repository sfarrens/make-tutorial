# Makefile Tutorial - Part 3

This tutorial demonstrates how to link external libraries using a makefile.

## Contents

1. [Source Code](#Source-Code)
1. [Makefile](#Makefile)
   * [Example](#Example)

## Source Code

This tutorial makes use of the following code:

- `src/io.cpp`: Code that handles the FITS IO of a given file.
- `src/io.hpp`: The corresponding header file.
- `src/listheader.cpp`: A script that reads the header of a given FITS file.

## Makefile

### Example

For the first example we will look at the file `makefile`.

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
> make CFITSIO_ROOT=/usr/local/Cellar/cfitsio/3.450_1
g++ -Wall -c src2/io.cpp -o build2/io.o -I /usr/local/Cellar/cfitsio/3.450_1/include
g++ -Wall -c src2/listheader.cpp -o build2/listheader.o -I /usr/local/Cellar/cfitsio/3.450_1/include
g++ -Wall -o build2/listheader build2/io.o build2/listheader.o -L/usr/local/Cellar/cfitsio/3.450_1/lib -lcfitsio
```

This will generate the executable `listheader` in the directory `build`, which lists the header contents of a FITS file. An example FITS file is provided in `data`.

```bash
> ./build/listheader ../data/example.fits
Header listing for HDU #1:
SIMPLE  =                    T / conforms to FITS standard
BITPIX  =                   64 / array data type
NAXIS   =                    1 / number of array dimensions
NAXIS1  =                  100
EXTEND  =                    T
END

```
