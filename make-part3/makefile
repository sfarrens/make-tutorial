##
# Makefile
#
# In this example we build on makefile5 from part 1 of the tutorial.

CXX = g++
CXXFLAG = -Wall

CFITSIO_LIBS = -lcfitsio
CFITSIO_LIB_DIR = $(CFITSIO_ROOT)/lib
CFITSIO_INCLUDE_DIR = $(CFITSIO_ROOT)/include

SRC_DIR = src
SRC_EXT = cpp
LIB_DIR = $(CFITSIO_LIB_DIR)
LIBS = $(CFITSIO_LIBS)
INCLUDE_DIR = $(CFITSIO_INCLUDE_DIR)
BUILD_DIR = build

TARGET = listheader

SRC = $(shell find $(SRC_DIR) -name '*.$(SRC_EXT)')
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
