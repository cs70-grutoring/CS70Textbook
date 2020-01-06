/**
 * \file program.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief A command line program demonstrating the use of iterators
 */

#include <cassert>
#include <iostream>
#include <list>
#include <string>

int main() {
  std::list<std::string> list = {"alpha", "bravo", "charlie", "delta", "echo"};
  std::list<std::string> list2;
  const std::list<std::string>& clist = list;
  std::list<double> dlist = {0.0, 1.0, 2.0, 3.0, 4.0};

  /*****************************************************************************
   * Iterator Basics
   ****************************************************************************/

  std::cout << std::endl << ">> Iterator Basics" << std::endl;

  // If a data structure supports an iterator, it should have a begin method
  // which returns an iterator pointing to the first element of the data
  // structure
  std::list<std::string>::iterator i1 = list.begin();

  // operator* returns a reference to the element to which the iterator points
  std::cout << *i1 << std::endl;

  // operator-> returns a pointer to the element to which the iterator points
  std::cout << i1->size() << std::endl;

  // operator++ moves the iterator to the next element in the data structure
  ++i1;
  std::cout << *i1 << std::endl;

  // For a bidirectional iterator, operator-- moves the iterator to the previous
  // element in the data structure.  A forward iterator need not support 
  // operator--.
  --i1;
  std::cout << *i1 << std::endl;

  // It is undefined behavior to decrement an iterator equal to begin
  /**
   * --list.begin();
   */

  // If a data structure supports an iterator, it should have an end method
  // which returns an iterator pointing to the past-the-end element of the data
  // structure.  This iterator is equal to an iterator that was pointing
  // to the last element and then was incremented.
  std::cout << *(--list.end()) << std::endl;

  // It is undefined behavior to use the *, ->, or ++ operators on an iterator
  // equal to end
  /**
   * std::list<std::string>::iterator end = list.end();
   * *end;
   * end->size();
   * ++end;
   */

  // Two iterators will compare as equal if they point to the same location in
  // the data structure
  std::list<std::string>::iterator i2 = list.begin();
  std::cout << (i1 == i2) << std::endl;
  ++i2;
  std::cout << (i1 == i2) << std::endl;

  // In an empty data structure, the iterators returned by begin and end must
  // compare as equal
  assert(list2.begin() == list2.end());

  // This will cause a compile-time error because it compares iterators to
  // data structures of different types
  /**
   * list.begin() == dlist.begin();
   */

  // It is undefined behavior to compare two iterators pointing to different
  // data structures of the same type
  /**
   * list.begin() == list2.begin();
   */

  /*****************************************************************************
   * Default Iterators
   ****************************************************************************/

  // STL data structures must support a default iterator
  std::list<std::string>::iterator default1;
  std::list<std::string>::iterator default2;

  // Two default iterators must be equal
  assert(default1 == default2);

  // It is undefined behavior to use the *, ->, ++, or -- operators on a default
  // iterator
  /**
   * *default1;
   * default1->size();
   * ++default1;
   * --default1;
   */

  // Once we give a default iterator a value, we can use it as normal
  default1 = list.begin();
  ++default1;

  /*****************************************************************************
   * iterators vs. const_iterators
   ****************************************************************************/

  std::cout << std::endl << ">> iterators vs const_iterators" << std::endl;

  // If a data structure supports an iterator, it should have a cbegin method
  // which returns an const_iterator pointing to the first element of the data
  // structure
  std::list<std::string>::const_iterator c1 = list.cbegin();

  // If a data structure (or a reference to a data structure) is declared as
  // const, begin will return a const_iterator rather than an iterator
  std::list<std::string>::const_iterator c2 = clist.begin();

  // A const_iterator is identical to an iterator except that operator* returns
  // a const reference rather than a reference and operator-> returns a const
  // pointer rather than a pointer.  This means that we cannot use a
  // const_iterator to modify the elements of the data structure.
  std::cout << *c1 << std::endl;
  ++c1;
  std::cout << c2->substr(1, 3) << std::endl;

  // These would cause compile-time errors because they attempt to modify an
  // element of the data structure with a const reference/pointer
  /**
   * *c1 = "beta";
   * c1->resize(2);
   */

  // Iterators support a constructor and assignment operator which convert an
  // iterator to a const_iterator
  std::list<std::string>::const_iterator c3 = i1;
  c1 = i1;

  // These will cause compile time errors because Iterators do NOT support
  // conversion from const_iterator to iterator
  /**
   * std::list<std::string>::iterator i3 = c1;
   * i1 = c1;
   */

  // If we declare an iterator or const_iterator with the const keyword, this
  // prevents the iterator itself from being changed (such as with ++ or --).
  // This is unrelated to the iterator/const_iterator distinction.
  const std::list<std::string>::iterator i4 = list.begin();
  const std::list<std::string>::const_iterator c4 = c1;

  *i4 = "alfa";
  std::cout << *c4 << std::endl;
  std::cout << (c4 == i4) << std::endl;

  // These will cause compile-time errors because i4 and c4 were declared with
  // the const keyword so cannot be modified
  /**
   * ++i4;
   * --i4;
   * c4 = c3;
   */

  /*****************************************************************************
   * Using Iterators
   ****************************************************************************/

  std::cout << std::endl << ">> Using Iterators" << std::endl;

  // std::next creates a copy of an iterator and increments (or decrements) the
  // copy n times without changing the original
  std::list<std::string>::iterator j1 = list.begin();
  std::list<std::string>::iterator j2 = std::next(j1, 4);
  std::list<std::string>::iterator j3 = std::next(j2, -2);
  std::cout << *j1 << std::endl;
  std::cout << *j2 << std::endl;
  std::cout << *j3 << std::endl;

  // We can use an iterator to iterate through the elements of a data structure
  std::cout << std::endl << "For loop:" << std::endl;
  for (std::list<std::string>::const_iterator i = list.cbegin();
       i != list.end(); ++i) {
    std::cout << *i << std::endl;
  }
  std::cout << std::endl;

  // The range-based for loop automatically iterates through a data structure
  // using the data structure's iterator.  The following range-based for loop
  // has the exact same behavior as the previous for loop.
  std::cout << "Ranged-base for loop:" << std::endl;
  for (std::string str : list) {
    std::cout << str << std::endl;
  }
  std::cout << std::endl;

  // If a data structure implements an iterator, we can use several standard
  // library functions on the data structure.  For example, std::equal compares
  // two data structures using their iterators.
  std::cout << std::equal(list.begin(), list.end(), list2.begin(), list2.end())
            << std::endl;

  // If you are writing your own data structure with an iterator, it is often
  // easiest to use these standard library functions to implement methods of
  // your data structure, such as using std::equal for operator==

  // Sometimes, methods of a data structure will take an iterator as a parameter
  // and/or return an iterator.  For example, std::list::erase takes an iterator
  // specifying which element to erase and returns an iterator to the element
  // directly after the element that was erased.
  std::list<std::string>::iterator j4 = list.erase(j3);
  std::cout << *j4 << std::endl;

  /*****************************************************************************
   * Invalid Iterators
   ****************************************************************************/

  // Methods of a data structure may invalidate existing iterators.  For
  // example, std::list::erase invalidates any iterator pointing to the element
  // that was erased.
  std::list<std::string>::iterator k1 = list.begin();
  list.erase(list.begin());

  // k1 is now invalid.  It is undefined behavior to use an invalid iterator
  // in any way.
  /**
   * *k1;
   * ++k1;
   * --k1;
   * k1->size();
   * k1 == j1;
   * std::list<std::string>::iterator k2 = k1;
   */

  // If a method invalidates any iterators, it should explicitly specify which
  // iterators it invalidates in its documentation.  A const method cannot
  // invalidate any iterators.

  return 0;
}
