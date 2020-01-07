# Type Transformations and Function Overloading
This example explores type transformation* and function overloading.  `Sheep` and `Hat` (declared in `sheep.hpp` and `hat.hpp` respectively) are two user-defined classes with parameterized constructors.  `program.cpp` contains two examples functions: `transformations` contains implicit and explicit type transformations, and `overloading` contains examples of choosing between multiple overloads of a function.  The `user` function provides a sandbox in which you can write and run additional experiments.

To compile this code, navigate to this directory and run `make all`.  You can then execute the program with `./program`.

*I use the term "type transformation" to refer to both type conversions and type promotions. In other literature, you may find that the term "conversion" is used instead to (somewhat confusingly) encompass both type conversions and promotions. 

## Exercises
Read through the definitions of `foo`, `bar`, and `bax` at the beginning of `program.cpp`.  Make sure you understand why these overloads can be distinguished by the compiler.  In `sheep.hpp`, make sure you understand the difference between the two `pet` methods and why the overload is valid.

Read through the `transformations` example in `program.cpp`.  Categorize each transformation as a promotion or a conversion, and predict the value assigned to each variable and the output printed to standard output.  Compile and run `./program` and check if the output aligns with your prediction.  If it does not, revisit the code and identify your mistake.  Also make sure that you understand the compile-time errors identified at the end of the example. 

Read through the `overloading` example in `program.cpp`.  For each function call, predict which overload will be called.  Compile and run `./program` and check if the output aligns with your prediction.  If it does not, revisit the code and identify your mistake.  Also make sure that you understand the compile-time errors identified for `foo` and `bar`.

The variable `IGNORE` in the `Makefile` tells the compiler to suppress certain warnings.  Replace the variable definition with `IGNORE =` to stop suppressing these warnings.  run `make clean` and `make all` and identify the meaning of the new compiler warnings.

## Reflection Questions
Use what you learned from these exercises to answer the following questions.
1. What is the difference between an implicit and explicit type transformation?
2. How can we tell if a transformation is a promotion or a conversion?  Why does this matter?
3. What is the difference between *Condition 1* and *Condition 2* in `transformations`?
4. What must be true about two overloads of a function for the compiler to distinguish between them?
5. How does the compiler determine if an overload is viable?
6. How does the compiler choose between multiple viable overloads?
7. In `overloads`, why is `bar(u, f)` a valid function call while `bar(d, f)` causes a compile-time error?
8. If a function is overloaded on const-ness, how does the compiler determine which version to call?
9. After you remove the `IGNORE` variable from the `Makefile`, how could you address the `-Wliteral-conversion` and `-Wsign-compare` warnings without suppressing them?
