/**
 * \file program.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief A command line program demonstrating the use of templates
 */

#include <iostream>
#include <list>
#include <string>
#include "minheap.hpp"

/**
 * \brief Prints an object to standard out
 * \param T         (template) The type of element
 * \param element   The object to print to standard out
 * \warning The template type T must support operator<<
 */
template <typename T>
void print(T element) {
  std::cout << element << std::endl;
}

/**
 * \brief Generates a pseudo-random integer from 1 to 20
 * \param ITERATIONS  (template) The number of stages used by the generator
 * \param seed        A value used to begin the random generation process
 * \return A pseudo-random integer between 1 and 20 inclusive
 * \warning The template parameter ITERATIONS must be greater than 0
 * \note This is a very poor pseudo-random number generator and makes no
 * promises about distribution or repeated patterns
 */
template <int ITERATIONS>
size_t d20(size_t seed) {
  // We need to know ITERATIONS at compile time since this is a static array
  size_t array[ITERATIONS];

  // A very poor pseudo-random number generator
  array[0] = seed != 0 ? seed : 101;
  for (size_t i = 1; i < ITERATIONS; ++i) {
    array[i] = array[i - 1];
    for (size_t j = 0; j < i; ++j) {
      array[i] ^= array[j] << (array[j + 1] % 31);
    }
  }

  return array[ITERATIONS - 1] % 20 + 1;
}

/**
 * \brief Inserts an element into a MinHeap if it is not already in the MinHeap
 * \param T         (template) the type of element and the template type of heap
 * \param heap      The MinHeap in which to insert element
 * \param element   The element to insert into MinHeap
 * \warning The type of element must exactly match the type on which MinHeap is
 * templated
 */
template <typename T>
void uniqueInsert(MinHeap<T>& heap, const T& element) {
  if (!heap.exists(element)) {
    heap.insert(element);
  }
}

void example1() {
  std::cout << ">> Example 1: Using print" << std::endl;

  // In these examples, the template type is inferred from the type of the
  // parameter element
  print(3.14);
  print(1998);

  std::string str = "foo";
  print(str);
  print(std::string("bar"));

  print(MinHeap<int>());

  // In these examples, the template type is explicitly specified
  print<int>(2011);
  print<int>(0.5);
  print<std::string>("bax");

  // This will cause a compile-time error because std::list does not support
  // operator<<, which is used in the implementation of print (see above)
  /**
   * print(std::list<int>());
   */

  // These will cause compile-time errors because the type of the parameter
  // element cannot be transformed into the requested template type
  /**
   * print<std::string>(64);
   * print<double>("twelve");
   */
}

void example2() {
  std::cout << std::endl << ">> Example 2: Using d20" << std::endl;

  std::cout << d20<32>(9059) << std::endl;
  std::cout << d20<32>(101483) << std::endl;
  std::cout << d20<64>(4621) << std::endl;
  std::cout << d20<2 + 4>(14449) << std::endl;
  std::cout << d20<static_cast<int>(64.0)>(55259) << std::endl;

  // This will cause a compile-time error because the value of iterations is
  // not known at compile-time
  /**
   * int iterations = 12;
   * std::cout << d20<iterations>(21107) << std::endl;
   */

  // This will cause a compile-time error because "hello" cannot be transformed
  // into an int
  /**
   * std::cout << d20<"hello">(18119)
   */
}

void example3() {
  std::cout << std::endl << ">> Example 3: Using MinHeap" << std::endl;

  MinHeap<std::string> h1;
  h1.insert("apple");
  h1.insert("orange");
  std::cout << h1.peakMin() << std::endl;
  h1.deleteMin();
  std::cout << h1.peakMin() << std::endl;

  MinHeap<double> h2;
  h2.insert(2.72);
  h2.insert(1.62);
  MinHeap<double> h3(h2);
  h3.insert(1.41);
  h2 = h3;
  std::cout << h2.peakMin() << std::endl;
  std::cout << (h2 == h3) << std::endl;
  std::cout << h2 << std::endl;

  // These will cause compile-time errors because h1 and h2 are templated on
  // different types
  /**
   * h1 = h2;
   * h1 == h2;
   */
}

void example4() {
  std::cout << std::endl
            << ">> Example 4: Using the MinHeap Iterator" << std::endl;

  MinHeap<std::string> heap;
  heap.insert("blueberry");
  heap.insert("pear");
  heap.insert("mango");

  MinHeap<std::string>::iterator i1 = heap.begin();
  MinHeap<std::string>::const_iterator i2 = heap.begin();
  MinHeap<std::string>::const_iterator i3 = heap.cbegin();

  std::cout << *i2 << std::endl;
  std::cout << i3->size() << std::endl;

  *i1 = "blackberry";
  i1->resize(6);
  std::cout << *i1 << std::endl;

  // These will cause compile-time errors because i2 and i3 are const_iterators,
  // so cannot modify elements of the MinHeap
  /**
   * *i2 = "strawberry";
   * i3->resize(5);
   */

  // This will cause a compile-time error because there is no way to convert
  // from a const_iterator (Iterator<true>) to an iterator (Iterator<false>)
  /**
   * MinHeap<std::string>::iterator bad1 = heap.cbegin();
   */

  // This will cause a compile-time error because heap is templated on
  // std::string, while bad2 is an iterator to a MinHeap templated on double
  /**
   * MinHeap<double>::iterator bad2 = heap.begin();
   */
}

void example5() {
  std::cout << std::endl << ">> Example 5: Using uniqueInsert" << std::endl;

  MinHeap<std::string> h1;
  uniqueInsert(h1, std::string("peach"));
  std::string str = "pine";
  uniqueInsert(h1, str + "apple");
  std::cout << h1 << std::endl;

  MinHeap<double> h2;
  uniqueInsert(h2, 0.0);
  uniqueInsert(h2, 1.0);
  uniqueInsert(h2, 4.0 / 2.0 - 1.0);
  uniqueInsert(h2, static_cast<double>(3));
  uniqueInsert<double>(h2, 4);
  std::cout << h2 << std::endl;

  // These will cause compile-time errors because the template type T refers to
  // two different types in a single call to uniqueInsert
  /**
   * uniqueInsert(h1, 2.0);
   * uniqueInsert(h2, std::string("cherry"));
   * uniqueInsert(h2, 2);
   */
}

void user() {
  std::cout << std::endl << ">> User Experiments" << std::endl;

  // Add your own experiments here
}

int main() {
  // To make the output easier to understand, it may help to run one example at
  // a time by commenting out all other examples
  example1();
  example2();
  example3();
  example4();
  example5();
  user();

  return 0;
}
