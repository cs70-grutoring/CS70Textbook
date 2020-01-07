/**
 * \file sheep.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Implements the Sheep class
 */

#include "sheep.hpp"
#include <iostream>

Sheep::Sheep(const Hat& hat) : name_{"shawn"}, hat_{hat} {}

Sheep::Sheep(const std::string& name) : name_{name} {}

void Sheep::pet() { std::cout << "baaaaa (non-const version)" << std::endl; }

void Sheep::pet() const { std::cout << "baaa (const version)" << std::endl; }
