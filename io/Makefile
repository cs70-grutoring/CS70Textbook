# Copyright 2020 Matthew Calligaro
# Makefile: A makefile for the templates case study

CXX = clang++
CXXFLAGS = -g -std=c++1z -Wall -Wextra -pedantic
TARGET = program echo-even

# A list of generated text files to remove with clean
GENERATED = output.txt append.txt

all: $(TARGET)

program: program.o sheep.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

program.o: program.cpp sheep.hpp
	$(CXX) $< -c $(CXXFLAGS)

sheep.o: sheep.cpp sheep.hpp
	$(CXX) $< -c $(CXXFLAGS)

# This is just a compilation command, no linking command is needed
echo-even: echo-even.cpp
	$(CXX) -o $@ $< $(CXXFLAGS)

clean:
	rm -rf *.o $(TARGET) $(GENERATED)
