/**
 * \file minheap.cpp
 * \copyright Matthew Calligaro
 * \date January 2020
 * \brief Provides the template implementation for the MinHeap class
 */

// The following line tells cpplint that we don't need a header guard for this
// file, since minheap.hpp already has a header guard:
// NOLINT(build/header_guard)

#include <algorithm>
#include <ostream>
#include <queue>
#include <utility>

/*******************************************************************************
 * MinHeap implementation
 ******************************************************************************/

template <typename T>
MinHeap<T>::MinHeap() : arraySize_{2}, size_{0}, array_{new T*[arraySize_]} {}

template <typename T>
MinHeap<T>::MinHeap(const MinHeap& other)
    : arraySize_{other.arraySize_},
      size_{other.size_},
      array_{new T*[arraySize_]} {
  // We must manually copy each element in order to make a deep copy
  for (size_t i = 1; i <= size_; ++i) {
    array_[i] = new T(*other.array_[i]);
  }
}

template <typename T>
MinHeap<T>& MinHeap<T>::operator=(const MinHeap& other) {
  // It is idiomatic to implement operator= by leveraging the copy constructor
  // and swap
  MinHeap copy = other;
  swap(copy);
  return *this;
}

template <typename T>
MinHeap<T>::~MinHeap() {
  // We must manually delete each element and array_ itself
  for (size_t i = 1; i <= size_; ++i) {
    delete array_[i];
  }
  delete[] array_;
}

template <typename T>
void MinHeap<T>::swap(MinHeap& other) {
  // We only need to swap the pointers (which takes constant time); there is no
  // need to move the objects on the heap
  std::swap(arraySize_, other.arraySize_);
  std::swap(size_, other.size_);
  std::swap(array_, other.array_);
}

template <typename T>
bool MinHeap<T>::operator==(const MinHeap& rhs) const {
  // If two MinHeap's have a different number of elements, they cannot be equal
  if (size_ != rhs.size_) {
    return false;
  }

  // We cannot simply iterate through the two MinHeaps or use std::equal, since
  // two MinHeaps may have the exact same elements but in different orders.
  // Instead, we copy each MinHeap and compare and remove the min element until
  // both are empty
  for (MinHeap<T> lcopy(*this), rcopy(rhs); !lcopy.empty();
       lcopy.deleteMin(), rcopy.deleteMin()) {
    if (lcopy.peakMin() != rcopy.peakMin()) {
      return false;
    }
  }

  return true;
}

template <typename T>
bool MinHeap<T>::operator!=(const MinHeap& rhs) const {
  // It is idiomatic to implement operator!= by leveraging operator==
  return !(*this == rhs);
}

template <typename T>
// Due to templating, the compiler does not realize that "MinHeap<T>::iterator"
// is a typename, so we must explicitly add the typename keyword before the
// return type of this method
typename MinHeap<T>::iterator MinHeap<T>::begin() {
  // Because array_ is a 1-indexed array, array_[1] is always a pointer to the
  // first element
  return iterator(array_ + 1);
}

template <typename T>
typename MinHeap<T>::iterator MinHeap<T>::end() {
  // array_[size_] points to the last element, so array_[size_ + 1] points to
  // the past-the-end element
  return iterator(array_ + size_ + 1);
}

template <typename T>
typename MinHeap<T>::const_iterator MinHeap<T>::begin() const {
  // The const version of begin can leverage cbegin
  return cbegin();
}

template <typename T>
typename MinHeap<T>::const_iterator MinHeap<T>::end() const {
  // The const version of end can leverage cend
  return cend();
}

template <typename T>
typename MinHeap<T>::const_iterator MinHeap<T>::cbegin() const {
  return const_iterator(array_ + 1);
}

template <typename T>
typename MinHeap<T>::const_iterator MinHeap<T>::cend() const {
  return const_iterator(array_ + size_ + 1);
}

template <typename T>
typename MinHeap<T>::size_type MinHeap<T>::size() const {
  return size_;
}

template <typename T>
bool MinHeap<T>::empty() const {
  return size_ == 0;
}

template <typename T>
std::ostream& MinHeap<T>::print(std::ostream& os, bool complete) const {
  os << "[";

  // In complete mode, print the unused index 0
  if (complete) {
    os << "x";
  }

  // Print the elements in array_ seperated by commas
  size_t startIndex = 1;
  if (!complete && size_ > 0) {
    os << *array_[1];
    startIndex = 2;
  }
  for (size_t i = startIndex; i <= size_; ++i) {
    os << "," << *array_[i];
  }

  // In complete mode, print the empty spaces at the end of array_
  if (complete) {
    for (size_t i = size_ + 1; i < arraySize_; ++i) {
      os << ",_";
    }
  }

  os << "]";
  return os;
}

template <typename T>
typename MinHeap<T>::const_reference MinHeap<T>::peakMin() const {
  // By construction, the first element of array_ is always the smallest
  return *array_[1];
}

template <typename T>
bool MinHeap<T>::exists(const_reference val) const {
  std::queue<size_t> q;
  q.push(1);

  // We perform a breadth first traversal of the heap and abandon any branch
  // if its value is greater than val
  while (!q.empty() && q.front() <= size_) {
    size_t index = q.front();
    q.pop();
    if (*array_[index] == val) {
      return true;
    } else if (*array_[index] < val) {
      q.push(2 * index);
      q.push(2 * index + 1);
    }
  }

  return false;
}

template <typename T>
void MinHeap<T>::insert(const_reference val) {
  // If array_ is full, double its size
  if (size_ >= arraySize_ - 1) {
    resize(true);
  }

  // Insert val at the end of array_
  ++size_;
  array_[size_] = new T(val);

  // Bubble up val while it is smaller than its parent
  for (size_t index = size_; index > 1 && *array_[index] < *array_[index / 2];
       index /= 2) {
    std::swap(array_[index], array_[index / 2]);
  }
}

template <typename T>
void MinHeap<T>::deleteMin() {
  // Delete the top element and move the last element to the top
  delete array_[1];
  array_[1] = array_[size_];
  --size_;

  // Bubble down the top element by switching with its smaller child until it
  // is smaller than both of its children
  size_t index = 1;
  while ((2 * index <= size_ && *array_[2 * index] < *array_[index]) ||
         (2 * index + 1 <= size_ && *array_[2 * index + 1] < *array_[index])) {
    size_t smallerChildIndex =
        *array_[2 * index] < *array_[2 * index + 1] ? 2 * index : 2 * index + 1;
    std::swap(array_[index], array_[smallerChildIndex]);
    index = smallerChildIndex;
  }

  // If array_ is 1/4 full or less, cut the size in half
  if (size_ > 0 && size_ <= arraySize_ / 4) {
    resize(false);
  }
}

template <typename T>
void MinHeap<T>::resize(bool upsize) {
  T** oldArray = array_;

  // Create a new array_ with the updated size
  if (upsize) {
    arraySize_ *= 2;
  } else {
    arraySize_ /= 2;
  }
  array_ = new T*[arraySize_];

  // Copy over the pointers from oldArray to the new array_, without touching
  // any of the elements themselves
  for (size_t i = 1; i <= size_; ++i) {
    array_[i] = oldArray[i];
  }

  delete[] oldArray;
}

/*******************************************************************************
 * MinHeap::Iterator implementation
 ******************************************************************************/

// Two default constructed Iterators must be equal, so we cannot used the
// synthesized default constructor, which could give pointer_ any value.
// Instead, we initialize pointer_ to the deterministic value nullptr (ie 0).
template <typename T>
template <bool IS_CONST>
// In some cases, the compiler does not realize that
// "MinHeap<T>::Iterator<IS_CONST>" is a class name due to the double
// templating, so we must add the template keyword as seen below
MinHeap<T>::template Iterator<IS_CONST>::Iterator() : pointer_{nullptr} {}

template <typename T>
template <bool IS_CONST>
MinHeap<T>::Iterator<IS_CONST>::Iterator(T** pointer) : pointer_{pointer} {}

template <typename T>
template <bool IS_CONST>
MinHeap<T>::Iterator<IS_CONST>::Iterator(const Iterator<false>& other)
    : pointer_{other.pointer_} {}

template <typename T>
template <bool IS_CONST>
bool MinHeap<T>::Iterator<IS_CONST>::operator==(const Iterator& rhs) const {
  return pointer_ == rhs.pointer_;
}

template <typename T>
template <bool IS_CONST>
bool MinHeap<T>::Iterator<IS_CONST>::operator!=(const Iterator& rhs) const {
  return !(*this == rhs);
}

template <typename T>
template <bool IS_CONST>
typename MinHeap<T>::template Iterator<IS_CONST>::reference
    MinHeap<T>::Iterator<IS_CONST>::operator*() const {
  return **pointer_;
}

template <typename T>
template <bool IS_CONST>
typename MinHeap<T>::template Iterator<IS_CONST>::pointer
    MinHeap<T>::Iterator<IS_CONST>::operator->() const {
  return *pointer_;
}

template <typename T>
template <bool IS_CONST>
typename MinHeap<T>::template Iterator<IS_CONST>&
MinHeap<T>::Iterator<IS_CONST>::operator++() {
  ++pointer_;
  return *this;
}

template <typename T>
template <bool IS_CONST>
typename MinHeap<T>::template Iterator<IS_CONST>&
MinHeap<T>::Iterator<IS_CONST>::operator--() {
  --pointer_;
  return *this;
}

/*******************************************************************************
 * Overloading global functions
 ******************************************************************************/

// We overload the global operator<< to call MinHeap::print, which allows us to
// write things such as "std::cout << heap << std::endl;"
template <typename T>
std::ostream& operator<<(std::ostream& os, const MinHeap<T>& heap) {
  return heap.print(os);
}

// We overload the global swap function to call the MinHeap::swap, which allows
// us to write "swap(h1, h2)" rather than just "h1.swap(h2)"
template <typename T>
void swap(MinHeap<T>& first, MinHeap<T>& second) {
  first.swap(second);
}
