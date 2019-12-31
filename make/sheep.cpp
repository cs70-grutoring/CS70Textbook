/**
 * \file sheep.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Implements the Sheep class
 */

#include "sheep.hpp"
#include <iostream>

Sheep::Sheep() : age_{1}, hat_{Top} {}

Sheep::Sheep(size_t age, Hat hat) : age_{age}, hat_{hat} {}

size_t Sheep::getAge() { return age_; }

void Sheep::changeHat(Hat hat) { hat_ = hat; }

void Sheep::pet() { std::cout << "baaa" << std::endl; }
