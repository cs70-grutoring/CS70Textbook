/**
 * \file hat.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Implements the Hat class
 */

#include "hat.hpp"
#include <string>

Hat::Hat() : numFeathers_{0} {}

Hat::Hat(int numFeathers) : numFeathers_{static_cast<size_t>(numFeathers)} {}

size_t Hat::getNumFeathers() const { return numFeathers_; }

void Hat::setNumFeathers(size_t numFeathers) { numFeathers_ = numFeathers; }

std::ostream& Hat::print(std::ostream& os) const {
  os << "_|";
  for (size_t i = 0; i < numFeathers_; ++i) {
    os << "`";
  }
  os << "|_";
  return os;
}

std::ostream& operator<<(std::ostream& os, const Hat& hat) {
  return hat.print(os);
}
