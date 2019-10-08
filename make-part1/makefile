##
# Makefile 1
#
# This makefile introduces a very basic and explicit build.

# First we define the executable target "main" followed by its dependencies,
# i.e. the individual object files.
# On the second line we provide the explicit build instructions.
main:	main.o print.o sphere_trig.o
	g++ -o main main.o print.o sphere_trig.o

# Then we define the "sphere_trig" object file along with its corresponding
# source file.
# Again, this is following by the explicit build instructions.
sphere_trig.o: src/sphere_trig.cpp
	g++ -c src/sphere_trig.cpp

# We reapt the same process for "print",
print.o: src/print.cpp
	g++ -c src/print.cpp

# and for "main".
main.o: src/main.cpp
	g++ -c src/main.cpp

# Finally we define instructions to remove or "clean" the build files.
.PHONY: clean
clean:
	rm *.o main
