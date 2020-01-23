/**
 * \file sheep.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Implements the Sheep class
 */

#include "sheep.hpp"
#include <fstream>
#include <ostream>
#include <string>

Sheep::Sheep(const std::string& name, size_t ageMonths)
    : name_{name}, ageMonths_{ageMonths} {}

std::ostream& Sheep::print(std::ostream& os) const {
  // Choose which file to open
  std::ifstream file(ageMonths_ < 12 ? "lamb.txt" : "sheep.txt");

  // Write every line from the file to os
  std::string line;
  while (std::getline(file, line)) {
    os << line << std::endl;
  }

  // Return a reference to the ostream argument
  return os;
}

std::ostream& Sheep::printStats(std::ostream& os) const {
  os << "Name: " << name_ << ", Age: " << ageMonths_ << " months";
  return os;
}

std::ostream& operator<<(std::ostream& os, const Sheep& sheep) {
  // operator<< can leverage the Sheep::print method
  return sheep.print(os);
}

std::string Sheep::getName() const { return name_; }

size_t Sheep::getAge() const { return ageMonths_; }
