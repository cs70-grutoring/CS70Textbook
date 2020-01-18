/**
 * \file sheep.hpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Declares the Sheep class
 */

#ifndef MAKE_SHEEP_HPP_
#define MAKE_SHEEP_HPP_

#include <cstddef>
#include "hat.hpp"

/**
 * \class Sheep
 * \brief A simple sheep implementation with a hat
 */
class Sheep {
 public:
  Sheep();
  Sheep(size_t age, Hat hat);
  Sheep(const Sheep& other) = default;
  Sheep& operator=(const Sheep& other) = default;
  ~Sheep() = default;

  /**
   * \brief Accessor for the sheep's age
   * \return The sheep's age in years
   */
  size_t getAge() const;

  /**
   * \brief Changes the sheep's hat
   * \param hat   The new hat given to the sheep
   */
  void changeHat(Hat hat);

  /**
   * \brief Pets the sheep, which makes the sheep happy
   */
  void pet() const;

 private:
  /** \brief The sheep's age in years */
  size_t age_;

  /** \brief The hat currently worn by the sheep */
  Hat hat_;
};

#endif  // MAKE_SHEEP_HPP_
