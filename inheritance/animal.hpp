/**
 * \file animal.hpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Declares the Animal abstract class
 */

#ifndef INHERITANCE_ANIMAL_HPP_
#define INHERITANCE_ANIMAL_HPP_

#include <cstddef>

/**
 * \class Animal
 * \brief
 */
class Animal {
 public:
  Animal();
  Animal(size_t numLegs);
  Animal(const Animal& other);
  Animal& operator=(const Animal& other);
  virtual ~Animal();

  size_t getNumLegs();
  virtual void feed();

  // sayHello is an abstract method, which makes Animal an abstract class
  virtual void sayHello() = 0;

 private:
  size_t numLegs_;
};

#endif  // INHERITANCE_ANIMAL_HPP_
