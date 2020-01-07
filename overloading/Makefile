# Copyright 2020 Matthew Calligaro
# Makefile: A makefile for the overloading case study

CXX = clang++
CXXFLAGS = -g -std=c++1z -Wall -Wextra -pedantic
TARGET = program

# Specifies compiler warnings to supress
IGNORE = -Wno-unused-variable -Wno-literal-conversion -Wno-sign-compare

all: $(TARGET)

program: hat.o program.o sheep.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(IGNORE)

hat.o: hat.cpp hat.hpp
	$(CXX) $< -c $(CXXFLAGS) $(IGNORE)

program.o: program.cpp sheep.hpp
	$(CXX) $< -c $(CXXFLAGS) $(IGNORE)

sheep.o: sheep.cpp sheep.hpp
	$(CXX) $< -c $(CXXFLAGS) $(IGNORE)

clean:
	rm -rf *.o $(TARGET)
