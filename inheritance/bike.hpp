/**
 * \file bike.hpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Declares the Bike class
 */

#ifndef INHERITANCE_BIKE_HPP_
#define INHERITANCE_BIKE_HPP_

/**
 * \class Bike
 * \brief A human-powered bike
 */
class Bike {
 public:
  Bike();
  Bike(double acceleration, double wheelDiameter);
  Bike(const Bike& other);
  Bike& operator=(const Bike& other);
  virtual ~Bike();

  // These methods are marked virtual so can be called with dynamic dispatch
  virtual void accelerate();
  virtual void brake();

  // These methods are not marked virtual so will always be called with
  // static dispatch
  double getSpeed();
  void honk();

 protected:
  // Protected data members can be accessed by derived classes
  double acceleration_;
  double speed_;

 private:
  // Private data members cannot be accessed by derived classes
  static const double UNIT_BRAKE;
  double wheelDiameter_;
};

#endif  // INHERITANCE_BIKE_HPP_
