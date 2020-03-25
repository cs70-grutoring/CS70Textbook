/**
 * \file safepointer-private.hpp
 * \copyright Matthew Calligaro
 * \date March 2020
 * \brief Provides the template implementation for the SafePointer class
 */

// The following line tells cpplint that we don't need a header guard for this
// file, since minheap.hpp already has a header guard:
// NOLINT(build/header_guard)

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
