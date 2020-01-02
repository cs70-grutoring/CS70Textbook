# Inheritance
This example explores single inheritance from a class and single inheritance from an abstract class.  The `Bike` class defines a human-powered bike, and `MotorBike` inherits from `Bike` to add the additional functionality of a gas-powered motor.  `Bike` contains virtual functions `accelerate` and `brake` and the non-virtual function `honk`, all of which are also implemented in the `MotorBike` class.

`Animal` is an abstract class with the abstract method `sayHello`.  `Sheep` inherits from `Animal` and implements `sayHello`.  The methods of all four classes print to `std::cout`, allowing the user to easily follow when each method is called.

`program.cpp` contains two example functions.  `inheritance` explores several examples using the `Bike` and `MotorBike` classes, and `abstractClasses` explores several examples using the `Sheep` and `Animal` classes.  The `user` function provides a sandbox in which you can write and run additional experiments.

To compile this code, navigate to this directory and run `make all`.  You can then execute the program with `./program`.

## Exercises
First, carefully read through the interface and implementation of `Bike`, `MotorBike`, `Animal`, and `Sheep`.  These files contain several comments highlighting important inheritance-related behavior.  Pay special attention to the use of the `virtual`, `protected`, and `override` keywords, as well as examples in which the derived class call a method from the base class.

Next, read through the `inheritance` and `abstractClasses` functions in `program.cpp` and predict which methods will be called by each line.  Then, compile and run `./program` and check if the output aligns with your prediction.  If it does not, revisit the code and identify your mistake.  You may find it helpful to add additional print statements.

Both of the examples contain commented out code which will either cause compile-time or run-time errors.  Make sure that you understand why this code causes that type of error.  Uncomment the code and verify that it does in fact cause an error.

In the `user` function, create additional examples using these classes based on any concepts you find confusing.  Run `./program` to see the results of your experiment. 

## Reflection Questions
Use what you learned from these exercises to answer the following questions.
1. What is the role of the `virtual` keyword, and when should we use it?
2. What is the role of the `override` keyword, and when should we use it?  Does it change a program's behavior?
3. What is the difference between `public`, `protected`, and `private`?  When should we use each?
4. How can we tell if a method is abstract, and what does this mean?
5. How can we tell if a class is abstract, and what does this mean?
6. What is the difference between static and dynamic dispatch?  When might we prefer each?
7. What is happening in the line `Bike b = MotorBike()`?  Will `b` act like a `Bike` or a `MotorBike`?
8. In the `inheritance` example, there are some cases in which we needed to cast a `Bike*` to a `MotorBike*`, and other cases when we did not.  What is this cast doing, and when is it necessary?
9. When can inheritance-related behavior cause a compile-time error?
10. When can inheritance-related behavior cause a run-time error?
