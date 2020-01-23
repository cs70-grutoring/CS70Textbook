# Input and Output
This example explores input and output using the C++ standard library.  `Sheep` is a user defined class which implements a `print` function and overloads `operator<<`. `program.cpp` contains four example functions which demonstrate different types of IO.
* `standard IO`: Uses standard input, standard output, and standard error.
* `fileIO`: Reads and writes from text files.
* `printingSheep`: Prints a user-defined object.
* `stringStream`: Uses the `stringstream` class.

Finally, the `user` function provides a sandbox in which you can write and run additional experiments.

`echo-even.cpp` contains a program which takes a line of input from standard input, prints an error if the input has an odd number of characters, and prints the input back to standard output.  This program serves as a tool for testing input and output redirection.

To compile this code, navigate to this directory and run `make all`.  You can then execute the two programs with `./program` and `./echo-even`.  

## Exercise 1: Basic IO
Read through the four example functions in `program.cpp`.  Predict what will be printed to standard output by each example.  Compile and run `./program` and check if the output aligns with your prediction.  If it does not, revisit the code and identify your mistake.  You may find it helpful to add additional print statements.

After running `program` once, you should see that the files `append.txt` and `output.txt` have been added to this directory.  Open these files and check if their contents aligns with your prediction.

Run `program` again and see if `append.txt` and/or `output.txt` have changed.  Can you explain why this happened?

## Exercise 2: Implementing printing
Read through the `Sheep` interface and implementation in `sheep.hpp` and `sheep.cpp`, paying close attention to the `print`, `printStats`, and `operator<<` functions.  Revisit the `printingSheep` example function in `program.cpp` and make sure that you understand how these functions are being called and why they produce the output that they do.

## Exercise 3: Redirecting standard input and output
Read through `echo-even.cpp` and run it with `./echo-even`.  Try giving it both an even-length and an odd-length input and identify the difference in output.

Try running the following commands.  After each command, check the contents of `out.txt` and `error.txt` if they exist and run `rm out.txt error.txt` to remove them.
* `./echo-even < hello.txt`
* `./echo-even < loremIpsum.txt`
* `./echo-even < hello.txt > out.txt`
* `./echo-even < loremIpsum.txt > out.txt`
* `./echo-even < loremIpsum.txt 2> error.txt`
* `./echo-even < loremIpsum.txt > out.txt 2> error.txt`

## Reflection Questions
Use what you learned from these exercises to answer the following questions.
1. By default, where do standard input, standard output, and standard error read or write data?
2. In the `standardIO` example, what happens if we provide a string with multiple words?  Why does this happen?
3. What does `std::endl` represent and why is it useful?
4. What does `std::getline` do and how is this different from `operator>>`
5. What is the best way to read all of the lines of text in a file?
6. What is the difference between writing to a file and appending to a file?
7. What is a `stringstream` capable of and why is it useful?
8. What is the difference between the `Sheep::print` method and the overload of `operator<<` implemented in `sheep.cpp`?  Why did we implement both?
9. How can we redirect standard input, output, and error for a program?  Why is this useful?
