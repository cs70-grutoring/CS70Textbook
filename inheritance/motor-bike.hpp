/**
 * \file motor-bike.hpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Declares the MotorBike class
 */

#ifndef INHERITANCE_MOTOR_BIKE_HPP_
#define INHERITANCE_MOTOR_BIKE_HPP_

#include "bike.hpp"

/**
 * \class MotorBike
 * \brief A gas-powered bike which inherits from Bike
 */
class MotorBike : public Bike {
 public:
  MotorBike();
  MotorBike(double acceleration, double wheelDiameter, double consumption,
            double tankCapacity);
  MotorBike(const MotorBike& other);
  MotorBike& operator=(const MotorBike& other);
  virtual ~MotorBike();

  // These methods are marked override to tell the compiler that we are
  // overriding a dynamic method, but the override keyword is purely optional
  void accelerate() override;
  void brake() override;

  // Although Bike also has a honk method, because it is not marked as virtual,
  // the version of honk will be chosen through static dispatch
  void honk();
  void refillTank();

 private:
  double consumption_;
  double tankCapacity_;
  double curTank_;
  bool tailLightOn_;
};

#endif  // INHERITANCE_MOTOR_BIKE_HPP_
