# Copyright 2020 Matthew Calligaro
# Makefile: A makefile for the templates case study

CXX = clang++
CXXFLAGS = -g -std=c++1z -Wall -Wextra -pedantic -Wno-literal-conversion
TARGET = program heap-test

all: $(TARGET)

# This is just a compilation command, no linking is needed
program: program.cpp minheap.hpp minheap-private.hpp
	$(CXX) -o $@ $< $(CXXFLAGS)

# This is just a compilation command, no linking is needed
heap-test: heap-test.cpp minheap.hpp minheap-private.hpp
	$(CXX) -o $@ $< $(CXXFLAGS)

clean:
	rm -rf *.o $(TARGET) documentation

# Run heap-test in valgrind to check for memory leaks and correctness
run-tests: heap-test
	valgrind --leak-check=full ./heap-test

# Generate documentation for MinHeap using doxygen
documentation: *.*pp
	doxygen doxygen.cfg
