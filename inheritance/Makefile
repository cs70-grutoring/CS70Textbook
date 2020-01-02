# Copyright 2020 Matthew Calligaro
# Makefile: A makefile for the inheritance case study

CXX = clang++
CXXFLAGS = -g -std=c++1z -Wall -Wextra -pedantic
TARGET = program

all: $(TARGET)

program: animal.o bike.o hat.o motor-bike.o program.o sheep.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

animal.o: animal.cpp animal.hpp
	$(CXX) $< -c $(CXXFLAGS)

bike.o: bike.cpp bike.hpp
	$(CXX) $< -c $(CXXFLAGS)

hat.o: hat.cpp hat.hpp
	$(CXX) $< -c $(CXXFLAGS)

motor-bike.o: motor-bike.cpp bike.hpp motor-bike.hpp
	$(CXX) $< -c $(CXXFLAGS)

program.o: program.cpp animal.hpp bike.hpp hat.hpp motor-bike.hpp sheep.hpp
	$(CXX) $< -c $(CXXFLAGS)

sheep.o: sheep.cpp animal.hpp hat.hpp sheep.hpp
	$(CXX) $< -c $(CXXFLAGS)

clean:
	rm -rf *.o $(TARGET)
