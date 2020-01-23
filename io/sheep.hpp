/**
 * \file sheep.hpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Declares the Sheep class
 */

#ifndef IO_SHEEP_HPP_
#define IO_SHEEP_HPP_

#include <ostream>
#include <string>

/**
 * \class Sheep
 * \brief A sheep which can be printed
 */
class Sheep {
 public:
  Sheep() = delete;
  Sheep(const std::string& name, size_t ageMonths);
  Sheep(const Sheep& other) = default;
  Sheep& operator=(const Sheep& other) = default;
  ~Sheep() = default;

  /**
   * \brief Prints a character representation of the sheep to an ostream
   * \param os  A reference to the ostream to which to print
   * \return A reference to the argument ostream
   */
  std::ostream& print(std::ostream& os) const;

  /**
   * \brief Prints information about the sheep to an ostream
   * \param os  A reference to an ostream to which to print
   * \return A reference to the argument ostream
   */
  std::ostream& printStats(std::ostream& os) const;

  /**
   * \brief Returns the sheep's name
   * \return The sheep's name
   */
  std::string getName() const;

  /**
   * \brief Returns the sheep's age in months
   * \return The sheep's age in months
   */
  size_t getAge() const;

 private:
  std::string name_;
  size_t ageMonths_;
};

/**
 * \brief Prints a sheep object to an ostream
 * \param os    A reference to the ostream to which to print
 * \param sheep A reference to the sheep to print
 * \return      A reference to the ostream the argument ostream
 */
std::ostream& operator<<(std::ostream& os, const Sheep& sheep);
// Because this is an overload of a global function and not a member method of
// Sheep, we must declare it outside of the Sheep class

#endif  // IO_SHEEP_HPP_
