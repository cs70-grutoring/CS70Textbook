# Iterators
This example explores several capabilities of C++ iterators.  `program.cpp` contains a `main` function which uses the `std::list` iterator in several ways.  It is divided into five sections.
* Iterator Basics
* Default Iterators
* iterators vs. const_iterators
* Using Iterators
* Invalid Iterators

Each section also contains relevant commented-out examples of undefined behavior and compile-time errors.  While compile-time errors will always create an error during compilation, undefined behavior could theoretically cause any behavior during compilation or run time, and will not necessarily create an error.

To compile this code, navigate to this directory and run `make all`.  You can then execute the program with `./program`.  

## Exercises
Read through the five sections and make sure that you understand what each line of code does.  Predict what will be printed to standard output by each example.  Compile and run `./program` and check if the output aligns with your prediction.  If it does not, revisit the code and identify your mistake.  You may find it helpful to add additional print statements.

Pay careful attention to the commented-out examples of compile-time errors and undefined behavior.  Make sure that you understand the problem with each example and can differentiate between compile-time errors and undefined behavior.

## Reflection Questions
Use what you learned from these exercises to answer the following questions.
1. What operators must an iterator support?  What does each operator do?
2. What is the difference between `operator*` and `operator->`, and when might we use each?
3. What does `end` point to, and why is it useful?
4. What is a default iterator and how are we allowed to use it?
5. What is the difference between an `iterator` and a `const_iterator`?  How do we get access to either?
6. When does `begin` return an `iterator` and when does it return a `const_iterator`?  What type of overloading is being used?
7. What is a range-based for loop and what does it do?  What must be true of an object to use it in a range-based for loop?
8. What does it mean to invalidate an iterator?
9. What compile-time errors should we be careful of with iterators?
10. What undefined behavior should we be careful of with iterators?
