/**
 * \file program.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief A command line program using the Sheep class
 */

#include <iostream>
#include "sheep.hpp"

int main() {
  Sheep shawn;
  std::cout << "Shawn's age: " << shawn.getAge() << std::endl;
  shawn.pet();

  Sheep elliot(5, Cowboy);

  return 0;
}
