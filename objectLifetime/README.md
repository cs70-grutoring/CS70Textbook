# Object Lifetime
This example explores when an object's constructors, assignment operator, and destructor are called.  The `Sheep` class has been modified to print a message every time the default constructor, parameterized constructor, copy constructor, assignment operator, or destructor is called.  `Sheep::printStatistics` prints the total number of times each method has been called since the last call to `Sheep::clearStatistics`.  

`program.cpp` contains five example functions which use the `Sheep` class in different contexts.
* `singletons`: Uses individual `Sheep`, references, and pointers.
* `arrays`: Uses `Sheep` in static and dynamic arrays.
* `lists`: Uses `Sheep` in `std::list`s. 
* `vectors`: Uses `Sheep` in an `std::vector`. 
* `functions`: Passes `Sheep` as a parameter to functions.

Finally, the `user` function provides a sandbox in which you can write and run additional experiments.

To compile this code, navigate to this directory and run `make all`.  You can then execute the program with `./program`.  

## Important Note about Strings
In C++, the literal `"hello"` is a character array (also known as a C-style string), not an `std::string`.  Because the Sheep parameterized constructor expects an `std::string` rather than a C-style string, we have made all of the sheep names `std::strings` by calling the `std::string` constructor explicitly.  For example, on line 29 of `program.cpp`, we call the `Sheep` parameterized constructor with an `std::string` by using the following syntax: 

```C++
Sheep elliot(std::string("Elliot"));
```

## Exercises
Predict how many times the `Sheep` default constructor, parameterized constructor, copy constructor, assignment operator, and destructor are called in each of the five examples.  Then, compile and run `./program` and check if the output aligns with your prediction.  If it does not, revisit the code and identify your mistake.  You may find it helpful to add additional print statements.  

In the `user` function, create additional examples using the `Sheep` class based on any concepts you find confusing.  Run `./program` to see the results of your experiment.

Finally, run `valgrind --leak-check=full ./program` to check for memory leaks.  

## Reflection Questions
Use what you learned from these exercises to answer the following questions.
1. After the call to `Sheep::printStatistics` at the end of each example, the `Sheep` destructor is called several more times before the start of the next example.  Why does this happen?
2. What is the difference between `emplace_back` and `push_back`?  In what situation might we prefer `emplace_back` over `push_back`?
3. Why does the first `Sheep` inserted into the `std::vector` get copied several times, while the last `Sheep` inserted into the `std::vector` never get copied?
4. What is the key difference between `pet` and `petRef`?  Which is more efficient?  In practice, which likely has the desired behavior?
5. Does this code leak any `Sheep`?  How can we answer this question only from the output of `program` without looking at `program.cpp` itself?
