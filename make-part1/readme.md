# Makefile Tutorial - Part 1

This tutorial introduces the basic concept of a makefile and slowly adds complexity to make it more generic and automatic.

## Contents

1. [Source Code](#Source-Code)
1. [Makefile Syntax](#Makefile-Syntax)
1. [Standard Compilation](#Standard-Compilation)
1. [Simple Shell Script](#Simple-Shell-Script)
1. [Makefile](#Makefile)
   * [Example 1](#Example-1)
   * [Example 2](#Example-2)
   * [Example 3](#Example-3)
   * [Example 4](#Example-4)
   * [Example 5](#Example-5)

## Source Code

This tutorial makes use of the following code:

- `src/sphere_trig.cpp`: Some code for calculating the angular separation between two objects.
- `src/sphere_trig.hpp`: The corresponding header file.
- `src/print.cpp`: Some code for printing a given angular separation.
- `src/print.hpp`: The corresponding header file.
- `src/main.cpp`: A script that calculates the angular separation between Andromeda and the Horsehead nebula.

## Makefile Syntax

This tutorial make use of some of the following markdown symbols:

- `$@`: the target filename.
- `$*`: the target filename without the file extension.
- `$<`: the first prerequisite filename.
- `$^`: the filenames of all the prerequisites, separated by spaces, discard duplicates.
- `$+`: similar to $^, but includes duplicates.
- `$?`: the names of all prerequisites that are newer than the target, separated by spaces.
- `$(...)`: custom variable
- `'%'`: pattern matching

> See [here](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html) for more details.

## Standard Compilation

There are many ways to build a C/C++ code, but for the purposes of this tutorial we will only look at two very standard methods.

The simplest way to build the source code provided would be to directly build the executable `main` as follows:

```bash
> g++ -o main src/main.cpp src/print.cpp src/sphere_trig.cpp
```

which can be easily run as follows:

```bash
> ./main
Hello there!
The angular separation between Andromeda and the Horsehead nebula is 80.1194 degrees.
```

We could also split this compilation into two steps:

1. First, build object files from each of the source files:

```bash
> g++ -c src/sphere_trig.cpp
> g++ -c src/print.cpp
> g++ -c src/main.cpp
```

which will produces the object files `sphere_trig.o`, `print.o` and `main.o`.

2. Second, link these object files to the executable:

```bash
> g++ -o main main.o print.o sphere_trig.o
```

which will produce the same executable `main`.

The benefit of this two-step process is that if we were to modify just one of the source files we would only need to regenerate its corresponding object file and update the executable. For a larger project this would save a lot of time as we would not need to recompile everything from scratch.

## Simple Shell Script

If you were developing a project like this it is pretty clear that it would be a pain to have to type out each of these compilation commands each time you want to recompile the code.

To save yourself some time and effort you could store these commands in a simple shell script. See for example the file `compile_script.sh`, which can be run as follows:

```bash
> ./compile_script.sh
```

and produces the same output as before.

The limitation of this approach is that we lose the benefit or producing the object files as the script recompiles the entire code each time it is run.

## Makefile

Makefiles provide the same advantage as the shell script in that we can automatically run all of the compilation commands. They also retain the benefit of generating object files in that only modified source codes will be recompiled during development.

Makefiles are usually files with the name `Makefile` or `makefile` and are run using the command `make`.

### Example 1

For the first example we will look at the file `makefile`.

This file is composed of five "targets". Targets are defined by a variable followed by a colon `:`.

The first target is for the executable `main` and is followed by its dependencies, *i.e.* the object files. The second line specifies the explicit build instructions.

```make
main:	main.o print.o sphere_trig.o
  g++ -o main main.o print.o sphere_trig.o
```

The second target is for the object file `sphere_trig.o` and is followed by its dependency, *i.e.* the source file `sphere_trig.cpp`.

```make
sphere_trig.o: src/sphere_trig.cpp
	g++ -c src/sphere_trig.cpp
```

This logic is repeated for the remaining objects.

```make
print.o: src/print.cpp
	g++ -c src/print.cpp

main.o: src/main.cpp
	g++ -c src/main.cpp
```

Finally, the target `clean` is defined, which specifies how the build files should be removed.

```make
.PHONY: clean
clean:
	rm *.o main
```

Note that here `.PHONY` specifies that `clean` is not a real target in the sense that there is no corresponding file with the target.

The makefile can be run as follows:

```bash
> make
g++ -c src/main.cpp
g++ -c src/print.cpp
g++ -c src/sphere_trig.cpp
g++ -o main main.o print.o sphere_trig.o
```

which will generate the executable `main`, and the command

```bash
> make clean
rm *.o main
```

will remove the build files.

To see the true power of this process we can modify one of the source files and rerun make. *e.g*

```bash
> touch src/print.cpp
> make
g++ -c src/print.cpp
g++ -o main main.o print.o sphere_trig.o
```

We can see that only `print.cpp` was recompiled!

### Example 2

For the second example we will look at the file `makefile2`.

We can start making our makefile more general by making use of some makefile tools.

First, we update the compilation command for the `main` target.

```make
main:	main.o print.o sphere_trig.o
	g++ -o $@ $^
```

Here we replace the explicit target `main` with `$@` and we replace the dependencies (*i.e.* the object files) with `$^`. These rather ugly symbols allow us to have a much more generic compilation command, which is essentially independent of the target to be built.

We can do something similar for the object files.

```make
sphere_trig.o: src/sphere_trig.cpp
	g++ -c $<
```

where we replace the explicit source file with `$<`.

Note that the command `make` will by default look for a files with the name `makefile`. As this example is called `makefile2` we need to run:

```bash
> make -f makefile2
g++ -c src/main.cpp
g++ -c src/print.cpp
g++ -c src/sphere_trig.cpp
g++ -o main main.o print.o sphere_trig.o
```

The output is identifcal to the previous example.

### Example 3

For the third example we will look at the file `makefile3`.

We will continue to make our makefile more generic.

Let's start by defining a variable called `OBJ` that corresponds to the object files

```make
OBJ = main.o print.o sphere_trig.o
```

Then we can replace the `main` target dependencies with a reference to this variable.

```make
main:	$(OBJ)
	g++ -o $@ $^
```

Next, rather than writing explicit targets for each of the object files, we can write something more generic.

```make
%.o: src/%.cpp*
	g++ -c $<
```

Here `%.o` specifies all files that end with `.o` and `%.cpp*` looks for the corresponding source file.

To run:

```bash
> make -f makefile3
g++ -c src/main.cpp
g++ -c src/print.cpp
g++ -c src/sphere_trig.cpp
g++ -o main main.o print.o sphere_trig.o
```

Now we can easily add more source files to our project and we simply need to specify the corresponding object files for them to be incorporated into the build.

### Example 4

For the forth example we will look at the file `makefile4`.

Let's add some more flexibility to our makefile.

We can specify the compiler and corresponding flags we want to use.

```make
CXX = g++
CXXFLAG = -Wall
```

We can specify where to find the source files and what extensions they should have.

```make
SRC_DIR = src
SRC_EXT = cpp
```

We can also create a variable for our target name.

```make
TARGET = main
```

This allows us to have a very flexible and generic set of build commands.

```make
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAG) -o $@ $^

%.o: $(SRC_DIR)/%.$(SRC_EXT)*
	$(CXX) $(CXXFLAG) -c $<
```

We can even make the `clean` target more generic.

```make
clean:
	rm *.o $(TARGET)
```

To run:

```bash
> make -f makefile4
g++ -c src/main.cpp
g++ -c src/print.cpp
g++ -c src/sphere_trig.cpp
g++ -o main main.o print.o sphere_trig.o
```

Now we have something that we can easily adapt to most projects, however we could make things even easier for ourselves.

### Example 5

For the fifth example we will look at the file `makefile5`.

For this last example we will make our build a bit more tidy by placing the build files in a build directory.

```make
BUILD_DIR = build
```

Now, to make our makefile automate some of the work for us we can make it provide the list of object files for us. To do so, we write a script to search the source directory for files matching the specified file extension.

```make
SRC = $(shell find $(SRC_DIR) -name '*.$(SRC_EXT)')
```

Then we specify that the object files should have the same names but with the extension ".o".

```make
OBJ = $(SRC:$(SRC_DIR)/%.$(SRC_EXT)=$(BUILD_DIR)/%.o)
```

Now we update our build and clean commands to use the build directory.

```make
.PHONY: all
all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAG) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)*
	$(CXX) $(CXXFLAG) -c $< -o $@

clean:
	rm $(BUILD_DIR)/*.o $(BUILD_DIR)/$(TARGET)
```

Note that we have added a target called `all`, which is a default for most projects. This would allow us to add more than one target executable to our project.

To run:

```bash
> make -f makefile5
g++ -Wall -c src/main.cpp -o build/main.o
g++ -Wall -c src/print.cpp -o build/print.o
g++ -Wall -c src/sphere_trig.cpp -o build/sphere_trig.o
g++ -Wall -o build/main build/main.o build/print.o build/sphere_trig.o
```

Note that the build files will be placed in the directory `build`.

```bash
> ./build/main
Hello there!
The angular separation between Andromeda and the Horsehead nebula is 80.1194 degrees.
```

---

> [Continue tutorial](../make-part2)

---
