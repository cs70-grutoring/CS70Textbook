/**
 * \file hat.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Implements the Hat class
 */

#include "hat.hpp"
#include <string>

Hat::Hat(std::string type) : type_{type} {}

std::string Hat::getType() { return type_; }
