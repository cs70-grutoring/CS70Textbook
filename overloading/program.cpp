/**
 * \file program.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief A command line program demonstrating transformations and overloading
 */

#include <iostream>
#include <string>
#include "sheep.hpp"

void foo(int i) {
  std::cout << "foo(int i) called with argument " << i << std::endl;
}

// This will cause a compile-time error because we cannot overload a function
// based on the return type alone
/**
 * int foo(int i) {
 *   std::cout << "This is an invalid overload" << std::endl;
 * }
 */

void foo(int i1, int i2) {
  std::cout << "foo(int i1, int i2) called with arguments " << i1 << " and "
            << i2 << std::endl;
}

void foo(short s) {
  std::cout << "foo(short s) called with argument " << s << std::endl;
}

void foo(unsigned long ul) {
  std::cout << "foo(unsigned long ul) called with argument " << ul << std::endl;
}

void foo(double d) {
  std::cout << "foo(double d) called with argument " << d << std::endl;
}

void bar(int i, double d) {
  std::cout << "bar(int i, double d) called with arguments " << i << " and "
            << d << std::endl;
}

void bar(double d, int i) {
  std::cout << "bar(double d, int i) called with arguments " << d << " and "
            << i << std::endl;
}

void bax(int i, Hat h) {
  std::cout << "bax(int i, Hat h) called with arguments " << i << " and " << h
            << std::endl;
}

void bax(int i, double d) {
  std::cout << "bax(int i, double d) called with arguments " << i << " and "
            << d << std::endl;
}

void petSheep(Sheep sheep) { sheep.pet(); }

void transformations() {
  std::cout << ">> Example 1: Type transformations" << std::endl;

  // Explict transformations
  int i1 = static_cast<int>(99.9);
  int i2 = (int)95.7;  // NOLINT(readability/casting)

  // Implicit transformations
  char c = 1;
  int i = c;
  long l = 2.0;
  double d = 14;
  unsigned int u = -2;

  double exp1 = 3 / 5;
  double exp2 = 3.0 / 5;
  double exp3 = true + false + 3.5;
  double exp4 = (true || true) + true;
  std::cout << "exp1: " << exp1 << std::endl;
  std::cout << "exp2: " << exp2 << std::endl;
  std::cout << "exp3: " << exp3 << std::endl;
  std::cout << "exp4: " << exp4 << std::endl;

  unsigned int u2 = 1;
  unsigned short s2 = 1;
  int i3 = -1;
  std::cout << "Condition 1 is: " << (i3 < u2 ? "true" : "false") << std::endl;
  std::cout << "Condition 2 is: " << (i3 < s2 ? "true" : "false") << std::endl;

  double d2 = 2.1;
  int i4 = 2;
  std::cout << "Condition 3 is: " << (d2 == i4 ? "true" : "false") << std::endl;

  // Implicit transformations with user-defined conversions
  Sheep shawn = Hat(2);
  Sheep elliot = Hat(2.5);
  petSheep(Hat());

  // These will cause compile-time errors because they requires two user-defined
  // conversions (int -> Hat, and Hat -> Sheep)
  /**
   * Sheep timmy = 1;
   * petSheep(2);
   */

  // These will cause compile-time errors because the Sheep(const std::string&)
  // constructor was marked with the explicit keyword
  /**
   * Sheep shirley = std::string("shirley");
   * petSheep(std::string("benjamin"));
   */
}

void overloading() {
  std::cout << std::endl << ">> Example 2: Function overloading" << std::endl;

  std::cout << "Foo:" << std::endl;

  int i = 0;
  unsigned short s = 1;
  char c = 2;
  unsigned int u = 3;
  float f = 4.0;
  double d = 5.0;

  foo(i);
  foo(s);
  foo(c);
  foo(f);
  foo(d);
  foo(d, d);
  foo(1.0 + 2);

  // This will cause a compile-time error because multiple overloads of foo
  // are equally preferred
  /**
   * foo(u)
   */

  // These will cause compile-time errors because viable overload of foo
  // supports these arguments
  /**
   * foo("hello");
   * foo(Hat());
   */

  std::cout << std::endl << "Bar:" << std::endl;

  bar(i, d);
  bar(f, s);
  bar(u, f);

  // These will cause compile-time errors because the two overloads of bar are
  // equally preferred
  /**
   * bar(i, s);
   * bar(d, f);
   * bar(d, d);
   * bar(u, u);
   */

  std::cout << std::endl << "Bax:" << std::endl;

  bax(i, i);

  std::cout << std::endl << "Overloading on const-ness:" << std::endl;

  Sheep shawn(std::string("shawn"));
  const Sheep elliot(std::string("elliot"));
  Sheep* timmy = new Sheep("timmy");

  Sheep& shawnRef = shawn;
  const Sheep& shawnCref = shawn;
  const Sheep* timmyC = timmy;

  shawn.pet();
  elliot.pet();
  timmy->pet();
  shawnRef.pet();
  shawnCref.pet();
  timmyC->pet();

  delete timmy;
}

void user() {
  std::cout << std::endl << ">> User Experiments" << std::endl;

  // Add your own experiments here
}

int main() {
  // To make the output easier to understand, it may help to run one example at
  // a time by commenting out all other examples
  transformations();
  overloading();
  user();
  return 0;
}
