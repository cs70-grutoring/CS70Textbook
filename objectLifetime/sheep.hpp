/**
 * \file sheep.hpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Declares the Sheep class
 */

#ifndef OBJECTLIFETIME_SHEEP_HPP_
#define OBJECTLIFETIME_SHEEP_HPP_

#include <cstddef>
#include <string>

/**
 * \class Sheep
 * \brief A sheep which tracks when each constructor/destructor is called
 */
class Sheep {
 public:
  Sheep();
  Sheep(std::string name);
  Sheep(const Sheep& other);
  Sheep& operator=(const Sheep& other);
  ~Sheep();

  std::string getName() const;

  /**
   * \brief Prints the number of times each Sheep method has been called
   */
  static void printStatistics();

  /**
   * \brief Resets all statistics back to 0
   */
  static void clearStatistics();

 private:
  /** \brief The name of the sheep */
  std::string name_;

  /** \brief The total number of calls to the Sheep default constructor */
  static size_t dConstructorCount_;

  /** \brief The total number of calls to the Sheep parameterized constructor */
  static size_t paramConstructorCount_;

  /** \brief The total number of calls to the Sheep copy constructor */
  static size_t copyConstructorCount_;

  /** \brief The total number of calls to the Sheep assignment operator */
  static size_t assignmentOpCount_;

  /** \brief The total number of calls to the Sheep destructor */
  static size_t destructorCount_;
};

#endif  // OBJECTLIFETIME_SHEEP_HPP_
