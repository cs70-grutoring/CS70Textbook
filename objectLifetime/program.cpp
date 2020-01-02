/**
 * \file program.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief A command line program demonstrating principles of object lifetime
 */

#include <iostream>
#include <list>
#include <vector>
#include "sheep.hpp"

Sheep pet(Sheep sheep) {
  std::cout << sheep.getName() << " was pet (via a call to pet())" << std::endl;
  return sheep;
}

const Sheep& petRef(const Sheep& sheep) {
  std::cout << sheep.getName() << " was pet (via a call to petRef())"
            << std::endl;
  return sheep;
}

void singletons() {
  Sheep::clearStatistics();
  std::cout << ">> Example 1: Singletons" << std::endl;

  Sheep shawn;
  Sheep elliot(std::string("Elliot"));
  Sheep dolly = elliot;
  Sheep* benjamin = new Sheep(std::string("Benjamin"));
  Sheep& ref = shawn;

  dolly = shawn;
  ref = *benjamin;

  delete benjamin;

  std::cout << std::endl;
  Sheep::printStatistics();
  std::cout << std::endl;
}

void arrays() {
  Sheep::clearStatistics();
  std::cout << std::endl << ">> Example 2: Arrays" << std::endl;

  Sheep static1[3];
  Sheep static2[2] = {std::string("Timmy"), std::string("Shirley")};
  Sheep static3[3] = {static2[0], std::string("Lola")};
  Sheep* dynamic1 = new Sheep[2];
  Sheep* dynamic2 = new Sheep[3]{std::string("Nuts"), static2[1]};

  static1[1] = dynamic2[0];

  delete[] dynamic1;
  delete[] dynamic2;

  std::cout << std::endl;
  Sheep::printStatistics();
  std::cout << std::endl;
}

void lists() {
  Sheep::clearStatistics();
  std::cout << std::endl << ">> Example 3: Lists" << std::endl;

  std::list<Sheep> l1;
  std::list<Sheep> l2 = {Sheep(std::string("Wilma")), std::string("Buttercup")};

  l1.push_back(Sheep(std::string("Luna")));
  l2.emplace_back(std::string("Lambo"));
  l2.emplace_back();
  l1.back() = l2.front();

  std::cout << std::endl;
  Sheep::printStatistics();
  std::cout << std::endl;
}

void vectors() {
  Sheep::clearStatistics();
  std::cout << std::endl << ">> Example 4: Vectors" << std::endl;

  std::vector<Sheep> v;
  for (size_t i = 0; i < 6; ++i) {
    v.emplace_back();
  }

  std::cout << std::endl;
  Sheep::printStatistics();
  std::cout << std::endl;
}

void functions() {
  Sheep::clearStatistics();
  std::cout << std::endl << ">> Example 5: Functions" << std::endl;
  Sheep lambert(std::string("Lambert"));

  Sheep petReturn = pet(lambert);
  pet(Sheep(std::string("Casper")));

  Sheep petRefReturn;
  petRefReturn = petRef(lambert);
  petRef(Sheep(std::string("Jasper")));

  std::cout << std::endl;
  Sheep::printStatistics();
  std::cout << std::endl;
}

void user() {
  Sheep::clearStatistics();
  std::cout << std::endl << ">> User Experiments" << std::endl;

  // Add your own experiments here

  std::cout << std::endl;
  Sheep::printStatistics();
  std::cout << std::endl;
}

int main() {
  // To make the output easier to understand, it may help to run one example at
  // a time by commenting out all other examples
  singletons();
  arrays();
  lists();
  vectors();
  functions();
  user();

  return 0;
}
