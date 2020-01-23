/**
 * \file program.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief A command line program demonstrating the use of inherited classes
 */

#include <iostream>
#include "bike.hpp"
#include "motor-bike.hpp"
#include "sheep.hpp"

void inheritance() {
  std::cout << ">> Example 1: Basic inheritance" << std::endl;
  std::cout << std::endl << "Creating bike1:" << std::endl;
  Bike bike1;

  std::cout << std::endl << "Creating motor1:" << std::endl;
  MotorBike motor1;

  std::cout << std::endl << "Creating bike2:" << std::endl;
  Bike bike2(8, 26);

  std::cout << std::endl << "Creating motor2:" << std::endl;
  MotorBike motor2(12, 29, 80, 2500);

  std::cout << std::endl << "Creating bike3:" << std::endl;
  Bike* bike3 = new Bike(bike2);

  std::cout << std::endl << "Creating motor3:" << std::endl;
  MotorBike* motor3 = new MotorBike(motor2);

  std::cout << std::endl << "Creating motor4:" << std::endl;
  Bike motor4 = MotorBike();

  std::cout << std::endl << "Creating motor5:" << std::endl;
  Bike* motor5 = new MotorBike();

  // These would cause compile-time errors because Bike does not support the
  // entire MotorBike interface
  /**
   * MotorBike bad1 = Bike();
   * MotorBike* bad2 = new Bike();
   */

  std::cout << std::endl << "Using bike1:" << std::endl;
  bike1.accelerate();
  bike1.honk();
  bike1.brake();

  std::cout << std::endl << "Using motor1:" << std::endl;
  motor1.accelerate();
  motor1.honk();
  motor1.brake();
  motor1.refillTank();

  std::cout << std::endl << "Using motor4:" << std::endl;
  motor4.accelerate();
  motor4.honk();
  motor4.brake();

  std::cout << std::endl << "Using motor5:" << std::endl;
  motor5->accelerate();
  motor5->honk();
  motor5->brake();

  // In order to call refillTank on motor5, we need to cast the pointer from a
  // Bike* to a MotorBike*
  static_cast<MotorBike*>(motor5)->refillTank();

  // Since honk is not virtual, we need to cast motor5 to a MotorBike* in order
  // to call the MotorBike version of honk
  static_cast<MotorBike*>(motor5)->honk();

  // These would cause compile-time errors because the Bike interface does
  // not know about the "refillTank" method, which is only declared in MotorBike
  /**
   * bike1.refillTank();
   * motor4.refillTank();
   * motor5->refillTank();
   */

  // This will cause a run-time error (a segfault) because bike3 points to a
  // Bike, not a MotorBike, so we cannot call refillTank on it even if we cast
  // the pointer to a MotorBike*
  /**
   * static_cast<MotorBike*>(bike3)->refillTank();
   */

  std::cout << std::endl << "Calling destructors:" << std::endl;
  delete bike3;
  delete motor3;
  delete motor5;
}

void abstractClasses() {
  std::cout << std::endl
            << std::endl
            << ">> Example 2: Abstract classes" << std::endl;

  Sheep shawn;
  Sheep elliot(new Hat("Top"));
  Animal* timmy = new Sheep(new Hat("Cowboy"));
  Animal* dolly = new Sheep(shawn);

  // These would cause compile-time errors because Animal is an abstract class
  /**
   * Animal bitzer;
   * Animal* pidsley = new Animal(4);
   */

  elliot.feed();
  timmy->sayHello();
  shawn.giveHat(new Hat("Bowler"));
  std::cout << "Dolly has " << dolly->getNumLegs() << " legs" << std::endl;

  // This would cause a compile-time error because the Animal interface does
  // not know about the "giveHat" method, which is only declared in Sheep
  /**
   * timmy->giveHat(new Hat("Beanie"));
   */

  delete timmy;
  delete dolly;
}

void user() {
  std::cout << std::endl << ">> User experiments" << std::endl;

  // Add your own experiments here
}

int main() {
  // To make the output easier to understand, it may help to run one example at
  // a time by commenting out all other examples
  inheritance();
  abstractClasses();
  user();

  return 0;
}
