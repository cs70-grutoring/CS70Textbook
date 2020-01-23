
/**
 * \file echo-even.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief A command line program which echos the input to standard input
 */

#include <iostream>
#include <string>

int main() {
  // Read input from standard input
  std::string input;
  std::cout << "Please enter your input: ";
  std::getline(std::cin, input);
  std::cout << std::endl;

  if (input.length() % 2 == 1) {
    // Write output to standard error
    std::cerr << "Error: output had an odd number of characters" << std::endl;
  }

  // Write output to standard output
  std::cout << "Your input was: " << input << std::endl;
  return 0;
}
