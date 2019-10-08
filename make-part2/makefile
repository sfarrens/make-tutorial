##
# Makefile
#
# In this example we build on makefile5 from part 1 of the tutorial.

CXX = g++
CXXFLAG = -Wall

# Add variables specifying the library directory, the libraries used and the
# include directory.
SRC_DIR = src
SRC_EXT = cpp
LIB_DIR = lib
LIBS = -lsphere
INCLUDE_DIR = include
BUILD_DIR = build

TARGET = main

SRC = $(shell find $(SRC_DIR) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
OBJ = $(SRC:$(SRC_DIR)/%.$(SRC_EXT)=$(BUILD_DIR)/%.o)

.PHONY: all
all: $(BUILD_DIR)/$(TARGET)

# Add the libraries to the linking build
$(BUILD_DIR)/$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAG) -o $@ $^ -L$(LIB_DIR) $(LIBS)

# Add the headers to the object build
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)*
	$(CXX) $(CXXFLAG) -c $< -o $@ -I $(INCLUDE_DIR)

.PHONY: clean
clean:
	rm $(BUILD_DIR)/*.o $(BUILD_DIR)/$(TARGET)
