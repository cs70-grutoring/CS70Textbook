# Copyright 2020 Matthew Calligaro
# Makefile: A makefile for the objectLifetime case study

CXX = clang++
CXXFLAGS = -g -std=c++1z -Wall -Wextra -pedantic
TARGET = program

all: $(TARGET)

program: program.o sheep.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

program.o: program.cpp sheep.hpp
	$(CXX) $< -c $(CXXFLAGS)

sheep.o: sheep.cpp sheep.hpp
	$(CXX) $< -c $(CXXFLAGS)

clean:
	rm -rf *.o $(TARGET)
