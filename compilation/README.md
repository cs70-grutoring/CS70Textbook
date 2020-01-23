# Compilation and Make
This example explores separate compilation and make.  `program.cpp` is a simple command line program using the `Sheep` class, which is declared in `sheep.hpp` and implemented in `sheep.cpp`.  The `Sheep` class uses the `Hat` enum, which is defined in `hat.hpp`.  

`Makefile-simple` and `Makefile-advanced` are two makefiles which perform the necessary compilation and linking steps to generate the `program` executable.  **To use either of these makefiles, you must rename them to `Makefile`**, and you can only use one at a time.

## Exercise 1: Simple Makefile
Rename `Makefile-simple` to `Makefile` and open it in a text editor.  You will find rules to make `program`, `program.o`, and `sheep.o`, as well as two dummy targets `all` and `clean`.  For each rule, thinking about why each dependency was needed and what the command will do.  

On the command line, navigate to this directory and run `make all`.  This will perform all of the linking and compilation steps necessary to generate the executable `program` (specifically, tvo compilation commands and one linking command).  You can delete these generated files by running `make clean`.  

Next, try running each command separately by running `make program.o`, `make sheep.o`, and `make program`.  Think about what each of these commands did, and why running `make all` on its own accomplishes all three tasks at once. 

## Exercise 2: Advanced Makefile
Rename `Makefile` back to `Makefile-simple` and rename `Makefile-advanced` to `Makefile`.  Open the two make files side-by-side in a text editor, and you will find that the advanced makefile has the following differences:
* The compiler, compiler flags, and target executable name are stored as variables, which makes it easy to change them in once place.
* The commands use the special macros `$@` (target), `$^` (all dependencies), and `$<` (first dependency) to avoid repetition. 
* There are three new rules: `lint`, `format`, and `documentation`. 

First, try running the same commands as before, such as `make all`, `make clean`, etc.  You should find that these have the exact same effects.  

The `lint` rule uses `cpplint` to automatically identify any style mistakes.  Right now, it will not identify any mistakes.  Try opening `program.cpp` and adding extra whitespace at the end of line 16.  If you run `make lint` again, it should raise an error. 

The `format` rule uses `clang-format` to automatically fix some style mistakes.  Run `make format`, and it will automatically fix the mistake you introduced in the previous step.  If you run `make lint` again, it should no longer raise an error. 

The `documentation` rule uses `doxygen` to automatically create documentation.  Run `make documentation`, and you will find a new directory called `documentation`.  Open `documentation/html/index.html` in a web browser to explore this generated documentation.  

## Exercises 3: Exploring Compilation
First, `make clean` and `make all` so that `program` is fully up to date.  For `program.cpp`, `sheep.cpp`, `sheep.hpp`, and `hat.hpp`, do the following:
1. Make a small change to the file and save it.  
2. Thinking about which compilation and/or linking steps will be needed to update `program` with this change. 
3. Run `make all` and carefully watch which compilation and/or linking steps are run.  Did this match your expectation?

## Reflection Questions
Use what you learned from these exercises to answer the following questions.
1. How can we determine the proper dependencies for a Makefile rule?
2. What is a phoney target and why is it useful?
3. How does Make determine whether a rule needs to be executed?
4. What is the difference between a compilation command and a linking command?
5. If we change a particular file, how can we determine which compilation and linking steps need to be executed?
6. What is the purpose of the `make all` command?
7. What is the purpose of the `make clean` command?
8. What is an advantage of using Makefile variables?
