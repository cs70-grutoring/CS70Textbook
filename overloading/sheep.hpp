/**
 * \file sheep.hpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Declares the Sheep class
 */

#ifndef OVERLOADING_SHEEP_HPP_
#define OVERLOADING_SHEEP_HPP_

#include <string>
#include "hat.hpp"

/**
 * \class Sheep
 * \brief A sheep with a hat
 */
class Sheep {
 public:
  Sheep() = delete;
  Sheep(const Hat& hat);
  explicit Sheep(const std::string& name);
  Sheep(const Sheep& other) = default;
  Sheep& operator=(const Sheep& other) = default;
  ~Sheep() = default;

  void pet();
  void pet() const;

 private:
  std::string name_;
  Hat hat_;
};

#endif  // OVERLOADING_SHEEP_HPP_
