/**
 * \file sheep.hpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Declares the Sheep class
 */

#ifndef INHERITANCE_SHEEP_HPP_
#define INHERITANCE_SHEEP_HPP_

#include "animal.hpp"
#include "hat.hpp"

/**
 * \class Sheep
 * \brief
 */
class Sheep : public Animal {
 public:
  Sheep();
  Sheep(Hat* hat);
  Sheep(const Sheep& other);
  Sheep& operator=(const Sheep& other);
  virtual ~Sheep();

  void feed() override;
  void sayHello() override;
  void giveHat(Hat* hat);

 private:
  Hat* hat_;
};

#endif  // INHERITANCE_SHEEP_HPP_
