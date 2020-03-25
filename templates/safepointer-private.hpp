/**
 * \file safepointer-private.hpp
 * \copyright Matthew Calligaro
 * \date March 2020
 * \brief Provides the template implementation for the SafePointer class
 */

// This file does not need a headerguard because its contents will be included
// within the header guard of safepointer.hpp.
// NOLINT(build/header_guard)

// All of the SafePointer method templates are found below

template <typename T>
SafePointer<T>::SafePointer() : pointer_{nullptr} {}

template <typename T>
SafePointer<T>::SafePointer(T* pointer) : pointer_{pointer} {}

template <typename T>
SafePointer<T>::~SafePointer() {
  if (pointer_ != nullptr) {
    delete pointer_;
  }
}

template <typename T>
T& SafePointer<T>::operator*() {
  return *pointer_;
}

template <typename T>
T* SafePointer<T>::get() {
  return pointer_;
}
