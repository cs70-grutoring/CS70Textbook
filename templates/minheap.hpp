/**
 * \file minheap.hpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Declares the MinHeap class
 */

#ifndef TEMPLATES_MINHEAP_HPP_
#define TEMPLATES_MINHEAP_HPP_

#include <cstddef>
#include <iterator>
#include <ostream>
#include <type_traits>
#include <utility>

/**
 * \class MinHeap
 * \brief A templated binary min heap implemented as an extendable array
 * \note The template type T must support the copy constructor, operator<, and
 * operator==
 */
template <typename T>
class MinHeap {
 private:
  template <bool IS_CONST>
  class Iterator;

 public:
  // STL container type definitions
  using value_type = T;
  using size_type = size_t;
  using difference_type = ptrdiff_t;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = Iterator<false>;
  using const_iterator = Iterator<true>;

  /**
   * \brief Creates an empty MinHeap
   * \note Run time: constant
   */
  MinHeap();

  /**
   * \brief Creates a MinHeap containing a deep copy of the contents of other
   * \param other   The MinHeap to be copied
   * \note Run time: linear in the size of other
   */
  MinHeap(const MinHeap& other);

  /**
   * \brief Replaces current contents with a deep copy of the contents of other
   * \param other   The MinHeap to be copied
   * \note Run time: linear in the size of other
   */
  MinHeap& operator=(const MinHeap& other);

  /**
   * \brief Frees all memory associated with the MinHeap
   * \note Run time: linear in the size of the MinHeap
   */
  ~MinHeap();

  /**
   * \brief Exchanges the contents of the MinHeap with other
   * \param other   The MinHeap with which to exchange contents
   * \note Run time: constant
   */
  void swap(MinHeap& other);

  /**
   * \brief Compares if two MinHeaps contain the same elements
   * \param rhs   The MinHeap with which to compare
   * \return True if this MinHeap and rhs contain the exact same elements
   * \note Run time: O(nlog(n)), where n is the size of the MinHeap
   */
  bool operator==(const MinHeap& rhs) const;

  /**
   * \brief Compares if two MinHeaps contain the same elements
   * \param rhs   The MinHeap with which to compare
   * \return False if this MinHeap and rhs contain the exact same elements
   * \note Run time: worst-case quadratic in the number of elements
   */
  bool operator!=(const MinHeap& rhs) const;

  /**
   * \brief Creates an iterator to the first element of the MinHeap
   * \return An iterator pointing to the first element of the MinHeap
   * \note Run time: constant
   * \warning Using this iterator to change elements of the MinHeap is undefined
   * behavior (in practice, MinHeap should only support a const_iterator, but
   * we have implemented an iterator as an example for other data structures)
   */
  iterator begin();

  /**
   * \brief Creates an iterator to the past-the-end element of the MinHeap
   * \return An iterator pointing to the past-the-end element of the MinHeap
   * \note Run time: constant
   * \warning Using this iterator to change elements of the MinHeap is undefined
   * behavior (in practice, MinHeap should only support a const_iterator, but
   * we have implemented an iterator as an example for other data structures)
   */
  iterator end();

  /**
   * \brief Creates a const_iterator to the first element of the MinHeap
   * \return A const_iterator pointing to the first element of the MinHeap
   * \note Run time: constant
   */
  const_iterator begin() const;

  /**
   * \brief Creates a const_iterator to the past-the-end element of the MinHeap
   * \return A const_iterator to the past-the-end element of the MinHeap
   * \note Run time: constant
   */
  const_iterator end() const;

  /**
   * \brief Creates a const_iterator to the first element of the MinHeap
   * \return A const_iterator pointing to the first element of the MinHeap
   * \note Run time: constant
   */
  const_iterator cbegin() const;

  /**
   * \brief Creates a const_iterator to the past-the-end element of the MinHeap
   * \return A const_iterator to the past-the-end element of the MinHeap
   * \note Run time: constant
   */
  const_iterator cend() const;

  /**
   * \brief Returns the number of elements in the MinHeap
   * \return The number of elements in the MinHeap
   * \note Run time: constant
   */
  size_type size() const;

  /**
   * \brief Returns whether the MinHeap is empty
   * \return True if the size of the MinHeap is 0
   * \note Run time: constant
   */
  bool empty() const;

  /**
   * \brief Prints the elements of the MinHeap to an ostream
   * \param os        The ostream to which to print
   * \param complete  If true, also print the empty spaces in the array
   * \return The ostream which was passed in
   * \note Run time: linear in the size of the MinHeap
   */
  std::ostream& print(std::ostream& os, bool complete = false) const;

  /**
   * \brief Returns a reference to the smallest element of the MinHeap
   * \return A reference to the smallest element of the MinHeap
   * \note Run time: constant
   * \warning Behavior is undefined if the MinHeap is empty
   */
  const_reference peakMin() const;

  /**
   * \brief Determines whether a value is contained in the MinHeap
   * \param val   The value for which to search in the MinHeap
   * \return True if val is contained in the MinHeap
   * \note Run time: worst-case linear in the size of the MinHeap
   */
  bool exists(const_reference val) const;

  /**
   * \brief Adds a new value to the MinHeap
   * \param val   The value to insert into the MinHeap
   * \note Run time: amortized logarithmic in the size of the MinHeap
   * \warning Invalidates all iterators pointing to this MinHeap
   */
  void insert(const_reference val);

  /**
   * \brief Removes the smallest value from the MinHeap
   * \note Run time: amortized logarithmic in the size of the MinHeap
   * \warning Invalidates all iterators pointing to this MinHeap
   * \warning Behavior is undefined if the MinHeap is empty
   */
  void deleteMin();

 private:
  /** \brief The size of array_ */
  size_t arraySize_;

  /** \brief The number of elements in the MinHeap */
  size_t size_;

  /** \brief A 1-indexed array of pointers to the elements of the MinHeap */
  T** array_;

  /**
   * \brief Either double or halve the size of array_
   * \param upsize  If true, double array_, if false, halve array_
   * \note Run time: linear in the size of the MinHeap
   */
  void resize(bool upsize);

  /**
   * \class Iterator
   * \brief A bidirectional iterator pointing to an element of a MinHeap
   * \details This iterator will perform a breadth-first traversal of the
   * MinHeap, which will not necessarily visit the elements from smallest
   * to largest.
   *
   * \note Iterator is templated on the bool IS_CONST, allowing it to implement
   * both iterator and const_iterator.  This is used as an example for the
   * reader, but in practice, MinHeap should not provide an iterator since it
   * allows users to change elements after the have been inserted, which can
   * create an out-of-place element.
   */
  template <bool IS_CONST>
  class Iterator {
   public:
    // STL iterator type definitions
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using const_reference = const value_type&;

    // At compile-time this evaluates to "const T&" if IS_CONST is true
    // and "T&" if IS_CONST is false
    using reference = typename std::conditional<IS_CONST, const value_type&,
                                                value_type&>::type;

    // At compile-time this evaluates to "const T*" if IS_CONST is true
    // and "T*"" if IS_CONST is false
    using pointer = typename std::conditional<IS_CONST, const value_type*,
                                              value_type*>::type;

    /**
     * \brief Creates a default Iterator which does not point to any MinHeap
     * \note Run time: constant
     * \warning It is undefined behavior to dereference, ++, or -- this iterator
     */
    Iterator();

    /**
     * \brief Creates an Iterator pointing to the same element as other
     * \param other   The Iterator to be copied
     * \note Run time: constant
     */
    Iterator(const Iterator<false>& other);

    /**
     * \brief Frees all memory associated with the Iterator
     * \note Run time: constant
     */
    ~Iterator() = default;

    /**
     * \brief Compares if two Iterators are pointing to the same element
     * \param rhs   The Iterator with which to copmare
     * \return True if this Iterator and rhs point to the same element
     * \note Run time: constant
     */
    bool operator==(const Iterator& rhs) const;

    /**
     * \brief Compares if two Iterators are pointing to the same element
     * \param rhs   The Iterator with which to copmare
     * \return False if this Iterator and rhs point to the same element
     * \note Run time: constant
     */
    bool operator!=(const Iterator& rhs) const;

    /**
     * \brief Returns a reference to the element to which the Iterator points
     * \return A reference to the element to which the Iterator points
     * \note Run time: constant
     */
    reference operator*() const;

    /**
     * \brief Returns a reference to the element to which the Iterator points
     * \return A reference to the element to which the Iterator points
     * \note Run time: constant
     */
    pointer operator->() const;

    /**
     * \brief Moves the Iterator to the next element in the MinHeap
     * \return A reference to the Iterator after it was moved
     * \note Run time: constant
     */
    Iterator& operator++();

    /**
     * \brief Moves the Iterator to the previous element in the MinHeap
     * \return A reference to the Iterator after it was moved
     * \note Run time: constant
     */
    Iterator& operator--();

   private:
    // We declare MinHeap as a friend so that it can access our private members
    // This also allows Iterator<true> to access the private members of
    // Iterator<false> and vice versa
    friend class MinHeap<T>;

    /** \brief A pointer to a pointer to the current element in the MinHeap */
    T** pointer_;

    /**
     * \brief Creates an Iterator pointing to a particular element of a MinHeap
     * \param pointer   A ** to the element of the MinHeap to which to point
     * \note Run time: constant
     */
    Iterator(T** pointer);
  };
};

// This copy-pastes the entirety of minheap-private.hpp at this point, which
// effectively combines minheap.hpp and minheap-private.hpp into a single file.
// We divide them into two files simply to help us mentally divide the interface
// and implementation of MinHeap, but as far as the compiler is concerned, they
// are one file.
#include "minheap-private.hpp"

#endif  // TEMPLATES_MINHEAP_HPP_
