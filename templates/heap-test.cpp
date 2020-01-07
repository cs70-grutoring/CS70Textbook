/**
 * \file heap-test.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief An assortment of ad hoc tests for the MinHeap class
 * \note These tests are not comprehensive and are NOT a good example of unit
 * testing
 */

#include <array>
#include <cassert>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include "minheap.hpp"

/**
 * \brief Performs a MinHeap::insert and checks for consistency
 * \param heap    The heap upon which insert is called
 * \param val     The value to insert into heap
 */
template <typename T>
void insertTestHelper(MinHeap<T>& heap, const T& val) {
  size_t size = heap.size();
  assert(!heap.exists(val));

  heap.insert(val);
  assert(heap.size() == size + 1);
  assert(heap.exists(val));
}

/**
 * \brief Performs a MinHeap::deleteMin and checks for consistency
 * \param heap    The heap upon which deleteMin is called
 */
template <typename T>
void deleteTestHelper(MinHeap<T>& heap) {
  size_t size = heap.size();
  assert(size > 0);
  T min = heap.peakMin();
  assert(heap.exists(min));

  heap.deleteMin();
  assert(!heap.exists(min));
  assert(heap.size() == size - 1);
}

/**
 * \brief Runs several ad hoc tests of MinHeap methods
 */
void coreTest() {
  std::stringstream ss;

  // Default constructor
  MinHeap<std::string> h1;
  assert(h1.size() == 0);
  h1.print(ss);
  assert(ss.str() == "[]");
  ss.str(std::string());
  h1.print(ss, true);
  assert(ss.str() == "[x,_]");

  // Insert
  insertTestHelper(h1, std::string("orange"));
  assert(h1.peakMin() == "orange");
  ss.str(std::string());
  h1.print(ss);
  assert(ss.str() == "[orange]");
  ss.str(std::string());
  h1.print(ss, true);
  assert(ss.str() == "[x,orange]");

  insertTestHelper(h1, std::string("blue"));
  assert(h1.peakMin() == "blue");
  ss.str(std::string());
  h1.print(ss);
  assert(ss.str() == "[blue,orange]");
  ss.str(std::string());
  h1.print(ss, true);
  assert(ss.str() == "[x,blue,orange,_]");

  insertTestHelper(h1, std::string("yellow"));
  assert(h1.peakMin() == "blue");
  ss.str(std::string());
  ss << h1;
  assert(ss.str() == "[blue,orange,yellow]");
  ss.str(std::string());
  h1.print(ss, true);
  assert(ss.str() == "[x,blue,orange,yellow]");

  insertTestHelper(h1, std::string("green"));
  assert(h1.peakMin() == "blue");
  ss.str(std::string());
  h1.print(ss);
  assert(ss.str() == "[blue,green,yellow,orange]");
  ss.str(std::string());
  h1.print(ss, true);
  assert(ss.str() == "[x,blue,green,yellow,orange,_,_,_]");

  insertTestHelper(h1, std::string("red"));
  assert(h1.peakMin() == "blue");
  ss.str(std::string());
  ss << h1;
  assert(ss.str() == "[blue,green,yellow,orange,red]");
  ss.str(std::string());
  h1.print(ss, true);
  assert(ss.str() == "[x,blue,green,yellow,orange,red,_,_]");

  // Copy Constructor
  MinHeap<std::string> h2 = h1;
  assert(h1 == h2);
  assert(std::equal(h1.begin(), h1.end(), h2.begin(), h2.end()));
  insertTestHelper(h2, std::string("aquamarine"));
  assert(h2.peakMin() == "aquamarine");
  assert(h1.peakMin() == "blue");
  assert(h1 != h2);
  assert(!std::equal(h1.begin(), h1.end(), h2.begin(), h2.end()));

  // Assignment Operator
  MinHeap<std::string> h3;
  assert(h1 != h3);
  h3 = h1;
  assert(h1 == h3);
  assert(std::equal(h1.begin(), h1.end(), h3.begin(), h3.end()));
  insertTestHelper(h1, std::string("purple"));
  insertTestHelper(h3, std::string("violet"));
  assert(h1 != h3);
  assert(!std::equal(h1.begin(), h1.end(), h3.begin(), h3.end()));

  // Swap
  MinHeap<std::string> h4;
  insertTestHelper(h4, std::string("white"));
  insertTestHelper(h4, std::string("black"));
  swap(h2, h4);

  assert(h2.peakMin() == "black");
  assert(h2.exists("white"));
  assert(h2.size() == 2);
  ss.str(std::string());
  h2.print(ss, true);
  assert(ss.str() == "[x,black,white,_]");

  assert(h4.peakMin() == "aquamarine");
  assert(h4.exists("green"));
  assert(h4.size() == 6);
  ss.str(std::string());
  h4.print(ss, true);
  assert(ss.str() == "[x,aquamarine,green,blue,orange,red,yellow,_]");

  // Operator==
  const std::array<std::string, 6> COLORS = {"blue",   "green", "orange",
                                             "purple", "red",   "yellow"};
  MinHeap<std::string> h5;
  for (std::string color : COLORS) {
    h5.insert(color);
  }
  assert(h1 == h5);

  // DeleteMin
  deleteTestHelper(h1);
  assert(h1.peakMin() == "green");
  ss.str(std::string());
  h1.print(ss, true);
  assert(ss.str() == "[x,green,orange,purple,yellow,red,_,_]");

  deleteTestHelper(h1);
  assert(h1.peakMin() == "orange");
  ss.str(std::string());
  h1.print(ss, true);
  assert(ss.str() == "[x,orange,red,purple,yellow,_,_,_]");

  deleteTestHelper(h1);
  assert(h1.peakMin() == "purple");
  ss.str(std::string());
  h1.print(ss, true);
  assert(ss.str() == "[x,purple,red,yellow,_,_,_,_]");

  deleteTestHelper(h1);
  assert(h1.peakMin() == "red");
  ss.str(std::string());
  h1.print(ss, true);
  assert(ss.str() == "[x,red,yellow,_]");

  deleteTestHelper(h1);
  assert(h1.peakMin() == "yellow");
  ss.str(std::string());
  h1.print(ss, true);
  assert(ss.str() == "[x,yellow]");

  deleteTestHelper(h1);
  assert(h1.size() == 0);
  ss.str(std::string());
  h1.print(ss, true);
  assert(ss.str() == "[x,_]");
}

/**
 * \brief Runs several ad hoc tests of MinHeap::Iterator methods
 */
void iteratorTest() {
  // Default Iterators
  MinHeap<double>::iterator d1;
  MinHeap<double>::iterator d2;
  assert(d1 == d2);

  // Other Iterator Constructors
  MinHeap<char> h1;
  h1.insert('f');
  h1.insert('g');
  MinHeap<char>::iterator i1 = h1.begin();
  MinHeap<char>::iterator i2 = i1;
  assert(i1 == i2);
  assert(*i1 == *i2);
  ++i1;
  assert(i1 != i2);

  MinHeap<char>::const_iterator i3 = h1.cbegin();
  ++i3;
  MinHeap<char>::const_iterator i4 = i1;
  assert(i3 == i4);
  assert(*i3 == *i4);

  // Create a heap with strings "a" through "z" in order
  MinHeap<std::string> heap;
  assert(heap.begin() == heap.end());
  for (char c = 'a'; c <= 'z'; ++c) {
    heap.insert(std::string(1, c));
  }

  // Iterate forward
  char c = 'a';
  MinHeap<std::string>::const_iterator j = heap.begin();
  for (MinHeap<std::string>::const_iterator i = heap.begin(); i != heap.end();
       ++i) {
    assert(*i == std::string(1, c));
    assert(i->size() == 1);
    assert(i == j);
    ++j;
    assert(i != j);
    ++c;
  }

  // Iterate backward
  c = 'z';
  j = heap.end();
  for (MinHeap<std::string>::const_iterator i = --heap.end(); i != heap.begin();
       --i) {
    assert(*i == std::string(1, c));
    assert(i->size() == 1);
    assert(i != j);
    --j;
    assert(i == j);
    --c;
  }
}

/**
 * \brief Use MinHeap to perform heap sort on size_t's
 */
void heapSortTest() {
  const size_t TEST_SIZE = 1000;
  const size_t SEED = 1985;
  const size_t NUM_SHUFFLES = 16;

  // Create a shuffled array of the numbers [0, TEST_SIZE)
  std::array<size_t, TEST_SIZE> numbers;
  for (size_t i = 0; i < TEST_SIZE; ++i) {
    numbers[i] = i;
  }
  for (size_t i = 0; i < NUM_SHUFFLES; ++i) {
    std::shuffle(numbers.begin(), numbers.end(),
                 std::default_random_engine(SEED * SEED << i));
  }

  // Insert the shuffled numbers into a MinHeap
  MinHeap<size_t> heap;
  for (size_t i = 0; i < TEST_SIZE; ++i) {
    heap.insert(numbers[i]);
  }

  // Verify that the numbers are removed in sorted order
  for (size_t i = 0; i < TEST_SIZE; ++i) {
    assert(heap.peakMin() == i);
    heap.deleteMin();
  }
}

int main() {
  coreTest();
  iteratorTest();
  heapSortTest();

  std::cout << "All tests passed" << std::endl;
  return 0;
}
