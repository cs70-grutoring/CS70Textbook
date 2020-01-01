/**
 * \file sheep.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Implements the Sheep class
 */

#include "sheep.hpp"
#include <iostream>

size_t Sheep::dConstructorCount_ = 0;
size_t Sheep::paramConstructorCount_ = 0;
size_t Sheep::copyConstructorCount_ = 0;
size_t Sheep::assignmentOpCount_ = 0;
size_t Sheep::destructorCount_ = 0;

Sheep::Sheep()
    : name_{"Default_Sheep_" + std::to_string(dConstructorCount_ + 1)} {
  ++dConstructorCount_;
  std::cout << "Call to Sheep default constructor: name = " << name_
            << ", number = " << dConstructorCount_ << std::endl;
}

Sheep::Sheep(std::string name) : name_{name} {
  ++paramConstructorCount_;
  std::cout << "Call to Sheep parameterized constructor: name = " << name_
            << ", number = " << paramConstructorCount_ << std::endl;
}

Sheep::Sheep(const Sheep& other) : name_{other.name_ + "_copy"} {
  ++copyConstructorCount_;
  std::cout << "Call to Sheep copy constructor: name = " << name_
            << ", other = " << other.name_
            << ", number = " << copyConstructorCount_ << std::endl;
}

Sheep& Sheep::operator=(const Sheep& other) {
  name_ = other.name_ + "_assigned";
  ++assignmentOpCount_;
  std::cout << "Call to Sheep assignment operator: name = " << name_
            << ", other = " << other.name_
            << ", number = " << assignmentOpCount_ << std::endl;
  return *this;
}

Sheep::~Sheep() {
  ++destructorCount_;
  std::cout << "Call to Sheep destructor: name = " << name_
            << ", number = " << destructorCount_ << std::endl;
}

std::string Sheep::getName() const { return name_; }

void Sheep::printStatistics() {
  std::cout << "Total calls to default constructor: " << dConstructorCount_
            << std::endl
            << "Total calls to parameterized constructor: "
            << paramConstructorCount_ << std::endl
            << "Total calls to copy constructor: " << copyConstructorCount_
            << std::endl
            << "Total calls to assignment operator: " << assignmentOpCount_
            << std::endl
            << "Total calls to destructor: " << destructorCount_ << std::endl;
}

void Sheep::clearStatistics() {
  dConstructorCount_ = 0;
  paramConstructorCount_ = 0;
  copyConstructorCount_ = 0;
  assignmentOpCount_ = 0;
  destructorCount_ = 0;
}
