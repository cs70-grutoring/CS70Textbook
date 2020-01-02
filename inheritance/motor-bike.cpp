/**
 * \file motor-bike.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Implements the MotorBike class
 */

#include "motor-bike.hpp"
#include <algorithm>
#include <iostream>

// This constructor begins by calling the Bike default constructor to initialize
// Bike-related data members (ie acceleration_, speed_, and wheelDiameter_)
MotorBike::MotorBike()
    : Bike(), consumption_{50}, tankCapacity_{3000}, curTank_{tankCapacity_} {
  std::cout << "Call to MotorBike default constructor" << std::endl;

  // Since acceleration_ is a protected member of Bike, we can update it in the
  // use phase (but we cannot initialize it in the member initialization list)
  acceleration_ = 10;
}

// This constructor begins by calling the Bike parameterized constructor to
// initialize Bike-related data members
MotorBike::MotorBike(double acceleration, double wheelDiameter,
                     double consumption, double tankCapacity)
    : Bike(acceleration, wheelDiameter),
      consumption_{consumption},
      tankCapacity_{tankCapacity},
      curTank_{tankCapacity} {
  std::cout << "Call to MotorBike parameterized constructor" << std::endl;
}

// This constructor begins by calling the Bike copy constructor to initialize
// Bike-related data members
MotorBike::MotorBike(const MotorBike& other)
    : Bike(other),
      consumption_{other.consumption_},
      tankCapacity_{other.tankCapacity_},
      curTank_{other.curTank_} {
  std::cout << "Call to MotorBike copy constructor" << std::endl;
}

MotorBike& MotorBike::operator=(const MotorBike& other) {
  std::cout << "Call to MotorBike assignment operator" << std::endl;

  // Call the Bike assignment operator to copy bike-related data members
  Bike::operator=(other);

  consumption_ = other.consumption_;
  tankCapacity_ = other.tankCapacity_;
  curTank_ = other.curTank_;

  return *this;
}

MotorBike::~MotorBike() {
  std::cout << "Call to MotorBike destructor" << std::endl;

  // The Bike destructor is automatically called after ~MotorBike() is finished
}

void MotorBike::accelerate() {
  std::cout << "Vroom Vroom (call to MotorBike::accelerate)" << std::endl;

  tailLightOn_ = false;
  if (curTank_ >= consumption_) {
    speed_ += acceleration_;
    curTank_ -= consumption_;
  }
}

void MotorBike::brake() {
  std::cout
      << "Skrrrrrrt (call to MotorBike::brake, which will call Bike::brake)"
      << std::endl;

  tailLightOn_ = true;

  // Call the Bike version of brake
  Bike::brake();
}

void MotorBike::honk() {
  std::cout << "Beep Beep (call to MotorBike::honk)" << std::endl;
}

void MotorBike::refillTank() {
  std::cout << "Tank refilled (call to MotorBike::refillTank)" << std::endl;
  curTank_ = tankCapacity_;
}
