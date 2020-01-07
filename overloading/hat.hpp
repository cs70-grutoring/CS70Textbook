/**
 * \file hat.hpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Declares the Hat class
 */

#ifndef OVERLOADING_HAT_HPP_
#define OVERLOADING_HAT_HPP_

#include <ostream>
#include <string>

/**
 * \class Hat
 * \brief A simple representation of a hat with feathers
 */
class Hat {
 public:
  Hat();
  Hat(int numFeathers);
  Hat(const Hat& other) = default;
  Hat& operator=(const Hat& other) = default;
  ~Hat() = default;

  size_t getNumFeathers() const;
  void setNumFeathers(size_t numFeathers);

  std::ostream& print(std::ostream& os) const;

 private:
  size_t numFeathers_;
};

std::ostream& operator<<(std::ostream& os, const Hat& hat);

#endif  // OVERLOADING_HAT_HPP_
