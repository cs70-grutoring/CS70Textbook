/**
 * \file bike.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Implements the Bike class
 */

#include "bike.hpp"
#include <algorithm>
#include <iostream>

const double Bike::UNIT_BRAKE = 10;

Bike::Bike() : acceleration_{5}, speed_{0}, wheelDiameter_{29} {
  std::cout << "Call to Bike default constructor" << std::endl;
}

Bike::Bike(double acceleration, double wheelDiameter)
    : acceleration_{acceleration}, speed_{0}, wheelDiameter_{wheelDiameter} {
  std::cout << "Call to Bike parameterized constructor" << std::endl;
}

Bike::Bike(const Bike& other)
    : acceleration_{other.acceleration_},
      speed_{other.speed_},
      wheelDiameter_{other.wheelDiameter_} {
  std::cout << "Call to Bike copy constructor" << std::endl;
}

Bike& Bike::operator=(const Bike& other) {
  std::cout << "Call to Bike assignment operator" << std::endl;

  acceleration_ = other.acceleration_;
  speed_ = other.speed_;
  wheelDiameter_ = other.wheelDiameter_;

  return *this;
}

Bike::~Bike() { std::cout << "Call to Bike destructor" << std::endl; }

void Bike::accelerate() {
  std::cout << "Pedal Pedal (call to Bike::accelerate)" << std::endl;
  speed_ += acceleration_;
}

void Bike::brake() {
  std::cout << "Sqeeeeeeeeeak (call to Bike::brake)" << std::endl;
  speed_ = std::max(0.0, speed_ - UNIT_BRAKE);
}

double Bike::getSpeed() { return speed_; }

void Bike::honk() {
  std::cout << "Honk Honk (call to Bike::honk)" << std::endl;
}
