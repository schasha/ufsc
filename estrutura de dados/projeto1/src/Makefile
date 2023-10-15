# Makefile for compiling a C++ program

# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11 -Wall

# Source files
SRCS := main.cpp parser.cpp getTagContent.cpp vacuumArea.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Executable name
TARGET := main

# Build target
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation step
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -g -c -o $@ $<

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets (targets that are not actual files)
.PHONY: all clean
