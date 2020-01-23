/**
 * \file program.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief A command line program demonstrating input and output
 */

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "sheep.hpp"

void standardIO() {
  std::cout << ">> Example 1: Standard input, output, and error" << std::endl;

  // Write a string to standard output, ending with a newline character
  std::cout << "example string" << std::endl;

  // Write an int to standard output, ending with a newline character
  std::cout << 1 << std::endl;

  char c = 'c';
  int i = 2;
  double d = 3.0;
  std::string s = std::string("winter") + std::string(" storm");

  // Write a sequence of several objects to standard output
  std::cout << c << i << std::endl << d << s << std::endl;

  // Read an int from standard input
  int input1;
  std::cout << "Please enter an integer: ";
  std::cin >> input1;

  // Read a double from standard input
  double input2;
  std::cout << "Please enter a double: ";
  std::cin >> input2;

  // Read a single word as a string from standard input
  std::string input3;
  std::cout << "Please enter a string: ";
  std::cin >> input3;

  // Reads an entire line as a string from standard input
  std::string input4;
  std::cout << "Please enter a string: ";
  std::getline(std::cin, input4);

  // Print the inputs to standard output
  std::cout << "Input 1: " << input1 << std::endl
            << "Input 2: " << input2 << std::endl
            << "Input 3: " << input3 << std::endl
            << "Input 4: " << input4 << std::endl;

  // Write a string to standard error, ending with a newline character
  std::cerr << "Writing to cerr is just like writing to cout" << std::endl;
}

void fileIO() {
  std::cout << std::endl << ">> Example 2: File input and output" << std::endl;

  // Open an input filestream to a file named loremIpusum.txt
  std::ifstream loremFile("loremIpsum.txt");

  // Read the first word of loremIpsum.txt as an std::string
  std::string loremContents;
  loremFile >> loremContents;
  std::cout << "loremContents = " << loremContents << std::endl;

  // Read the rest of the entire first line of loremIpusm.txt as an std::string
  std::getline(loremFile, loremContents);
  std::cout << "loremContents = " << loremContents << std::endl;

  // Close loremIpsum.txt
  loremFile.close();

  // Open an input filestream to a file named numbers.txt
  std::ifstream numberFile("numbers.txt");

  // Read each number in numbers.txt as an int to calculate the sum.  The
  // while condition uses the fact that "numberFile >> number" will evaluate to
  // false when it reaches the end of the file.
  int number;
  int sum = 0;
  while (numberFile >> number) {
    sum += number;
  }
  std::cout << "sum = " << sum << std::endl;

  // Close numbers.txt
  numberFile.close();

  // Open an output filestream to a file named output.txt for writing, which
  // removes all content currently in the file
  std::ofstream outputFile("output.txt", std::ofstream::out);

  // Write some lines to output.txt
  outputFile << "This will be the first line of output.txt" << std::endl;
  outputFile << "The calculated sum was " << sum << std::endl;

  // Close output.txt
  outputFile.close();

  // Open an output filestream to a file named append.txt for appending,
  // which adds new content without modifying the existing content in the file
  std::ofstream appendFile("append.txt", std::ofstream::app);

  // Write a new line to append.txt
  appendFile << "This will be added to the end of append.txt" << std::endl;

  // Close append.txt
  appendFile.close();
}

void printingSheep() {
  std::cout << std::endl << ">> Example 3: Printing sheep" << std::endl;

  Sheep shawn("shawn", 97);
  Sheep timmy("timmy", 6);

  // Print shawn to standard output using the Sheep::print method
  shawn.print(std::cout);

  // Print timmy to standard output using operator<<
  std::cout << timmy << std::endl;

  // Print shawn's stats to standard error using the Sheep::printStats method
  shawn.printStats(std::cerr);
  std::cerr << std::endl;
}

void stringstream() {
  std::cout << std::endl << ">> Example 4: Stringstream" << std::endl;

  Sheep elliot("elliot", 91);

  // Create a stringstream directly from an std::string
  std::string str1 = "hello world!";
  std::stringstream ss1(str1);

  // We can write to a stringstream just like an ostream
  std::stringstream ss2;
  ss2 << "2 + 3 = " << 2 + 3 << std::endl;
  ss2 << "elliot is " << elliot.getAge() / 12 << " years old" << std::endl;

  // We can then convert the contents of the stringstream to an std::string
  std::string str2 = ss2.str();
  std::cout << str2;

  // This clears a stringstream
  ss2.str(std::string());

  // Stringstreams are useful for printing an object to an std::string
  ss2 << elliot;
  std::string str3 = ss2.str();
  std::cout << str3;

  // Stringstreams are also helpful for testing methods which need to
  // print to an ostream
  std::stringstream ss3;
  elliot.printStats(ss3);
  assert(ss3.str() == "Name: elliot, Age: 91 months");
}

void user() {
  std::cout << std::endl << ">> User experiments" << std::endl;

  // Add your own experiments here
}

int main() {
  // To make the output easier to understand, it may help to run one example at
  // a time by commenting out all other examples
  standardIO();
  fileIO();
  printingSheep();
  stringstream();
  user();

  return 0;
}
