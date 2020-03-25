/**
 * \file safepointer.hpp
 * \copyright Matthew Calligaro
 * \date March 2020
 * \brief Declares the SafePointer class
 */

// Remember to include a header guard to protect against including multiple
// copies of this file
#ifndef TEMPLATES_SAFEPOINTER_HPP_
#define TEMPLATES_SAFEPOINTER_HPP_

/**
 * \class SafePointer
 * \brief A wrapper for a pointer which helps protect against memory leaks
 * \note This is a simplified version of the std::unique_ptr class
 */
template <typename T>  // The template parameter for this class template
class SafePointer {
  // Just like in a traditional class declaration, we declare all of the
  // class methods and data members as either private or public
 public:
  SafePointer();
  SafePointer(T* pointer);
  SafePointer(const SafePointer& other) = delete;
  SafePointer& operator=(const SafePointer& other) = delete;
  ~SafePointer();

  T& operator*();
  T* get();

 private:
  T* pointer_;
};

// During preprocessing, this will paste the contents of safepointer-private.hpp
// at this point, which effectively combines safepointer.hpp and
// safepointer-private.hpp into a single file.  We divide them into two files to
// separate the interface and implementation of SafePointer, but as far as the
// compiler is concerned, they are one file.
#include "safepointer-private.hpp"

#endif  // TEMPLATES_SAFEPOINTER_HPP_
