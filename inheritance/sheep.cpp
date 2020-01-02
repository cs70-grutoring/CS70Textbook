/**
 * \file sheep.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Implements the Sheep class
 */

#include "sheep.hpp"
#include <iostream>

// The Sheep default and parameterized constructors call the Animal
// parameterized constructor to specify that Sheep is an Animal with 4 legs
Sheep::Sheep() : Animal(4), hat_{nullptr} {
  std::cout << "Call to Sheep default constructor" << std::endl;
}

Sheep::Sheep(Hat* hat) : Animal(4), hat_{hat} {
  std::cout << "Call to Sheep parameterized constructor" << std::endl;
}

// The Sheep copy constructor calls the Animal copy constructor to copy
// animal-related members (ie numLegs_)
Sheep::Sheep(const Sheep& other)
    : Animal(other),
      hat_{other.hat_ == nullptr ? nullptr : new Hat(*other.hat_)} {
  std::cout << "Call to Sheep copy constructor" << std::endl;
}

Sheep& Sheep::operator=(const Sheep& other) {
  std::cout << "Call to Sheep assignment operator" << std::endl;

  // Call the Animal assignment operator to copy animal-related members
  // (ie numLegs_)
  Animal::operator=(other);

  // Delete our current hat and make a copy of other's hat
  if (hat_ != nullptr) {
    delete hat_;
  }
  hat_ = new Hat(*other.hat_);

  return *this;
}

Sheep::~Sheep() {
  std::cout << "Call to Sheep destructor" << std::endl;

  if (hat_ != nullptr) {
    delete hat_;
  }

  // The Animal destructor is automatically called after ~Sheep() is finished
}

void Sheep::feed() { std::cout << "Sheep was fed" << std::endl; }

void Sheep::sayHello() { std::cout << "baaa" << std::endl; }

void Sheep::giveHat(Hat* hat) {
  if (hat_ != nullptr) {
    delete hat_;
  }

  hat_ = hat;
  std::cout << "Sheep was given " << hat->getType() << " hat" << std::endl;
}
