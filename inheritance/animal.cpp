/**
 * \file animal.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Implements the Animal abstract class
 */

#include "animal.hpp"
#include <iostream>

Animal::Animal() : numLegs_{4} {
  std::cout << "Call to Animal default constructor" << std::endl;
}

Animal::Animal(size_t numLegs) : numLegs_{numLegs} {
  std::cout << "Call to Animal parameterized constructor" << std::endl;
}

Animal::Animal(const Animal& other) : numLegs_{other.numLegs_} {
  std::cout << "Call to Animal copy constructor" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  numLegs_ = other.numLegs_;
  std::cout << "Call to Animal assignment operator" << std::endl;
  return *this;
}

Animal::~Animal() { std::cout << "Call to Animal destructor" << std::endl; }

size_t Animal::getNumLegs() { return numLegs_; }

void Animal::feed() { std::cout << "Animal was fed" << std::endl; }
