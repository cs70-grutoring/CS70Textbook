/**
 * \file hat.hpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Declares the Hat class
 */

#ifndef INHERITANCE_HAT_HPP_
#define INHERITANCE_HAT_HPP_

#include <string>

/**
 * \class Hat
 * \brief A very simple representation of a hat
 */
class Hat {
 public:
  Hat() = delete;
  Hat(std::string type);
  Hat(const Hat& other) = default;
  Hat& operator=(const Hat& other) = default;
  ~Hat() = default;

  std::string getType();

 private:
  std::string type_;
};

#endif  // INHERITANCE_HAT_HPP_
