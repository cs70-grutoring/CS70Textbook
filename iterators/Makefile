# Copyright 2020 Matthew Calligaro
# Makefile: A makefile for the iterators case study

CXX = clang++
CXXFLAGS = -g -std=c++1z -Wall -Wextra -pedantic -Wno-unused-variable
TARGET = program

all: $(TARGET)

# This is just a compilation command, no linking command is needed
program: program.cpp
	$(CXX) -o $@ $< $(CXXFLAGS)

clean:
	rm -rf *.o $(TARGET)
