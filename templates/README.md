# Templates and MinHeap
This example explores function and class templates, and also provides a complete implementation of the binary min heap data structure.  `minheap.hpp` and `minheap-private.hpp` declare and implement the `MinHeap` class, a templated binary min heap.  `MinHeap` provides both an `iterator` and a `const_iterator`, which are implemented as a single `MinHeap::Iterator` class templated on a `bool`.  `heap-test.cpp` contains a collection of ad hoc tests of the `MinHeap` class.

`program.cpp` contains three function templates: `print`, `d20`, and `uniqueInsert`.  It also contains five example functions which demonstrate different uses of templates.
1. Using `print`, a function templated on parameter type.
2. Using `d20`, a function templated on an `int`.
3. Using `MinHeap`, a data structure templated on element type.
4. Using the `MinHeap` Iterator, an bidirectional iterator templated on a `bool`.
5. Using `uniqueInsert`, a function templated on the type of two parameters.

Finally, the `user` function provides a sandbox in which you can write and run additional experiments.

To compile this code, navigate to this directory and run `make all`.  You can then execute program with `./program` and heap-test with `make run-tests`.  You can generate documentation for the `MinHeap` class with `make documentation`.

## MinHeap
`MinHeap` is a binary min heap implemented as an extendable array.  Specifically, it is a class template templated on the type of the elements stored in the heap.  This data structure returns the smallest element in constant time and can insert new elements or delete the smallest element in `O(log n)` time.  While the data structure theoretically operates as a binary tree, we have implemented it as a contiguous array to increase efficiency.  This array will double and halve its size as needed to accommodate new or deleted elements.

`MinHeap` also provides an `iterator` and a `const_iterator`, both of which are implemented through the `Iterator` class, which is templated on the `bool IS_CONST`.  This allows us to only write the iterator implementation once, since the only difference between an `iterator` and a `const_iterator` is the return type of `operator*` and `operator->`.  This is included as an example of the idiomatic way to implement an `iterator` and `const_iterator` with a single class.  **However, in reality, `MinHeap` should only support a const_iterator** since an iterator allows users to change elements without the knowledge of the `MinHeap`, which could result in elements being out of place.  

To generate the complete documentation for this class, run `make documentation`, which will generate a `documentation` directory.  Open `documentation/html/classMinHeap.html` in a web browser to read the complete documentation for this class.

`heap-test.cpp` provides a small set of ad hoc correctness tests for the `MinHeap` class.  **These tests are not comprehensive and are not an example of good unit testing.**

The `MinHeap` data structure addresses several of the implementation and design details common to many data structures.  If you are interested in implementing your own data structure in C++, `minheap.hpp` and `minheap-private.hpp` may provide helpful examples.

## Exercises
Read through `minheap.hpp` and `minheap-private.hpp`, paying careful attention to the use of the template type `T` and the template bool `IS_CONST`.  Make sure that you understand the role that these template parameters play in the interface and implementation.  What assumptions are made about the template type `T`?

Read through the function templates `print`, `d20`, and `uniqueInsert` in `program.cpp`.  Make sure that you understand the role that the template parameter plays in each function.  What assumptions are made about the template type `T` in `print` and `uniqueInsert`?

Read through examples 1 through 5 in `program.cpp`.  Make sure you understand why the commented out code will cause compile-time errors.  For each example, determine how many versions of each function and class template are created during compilation.  Predict what will be printed to standard output by each example.  Then, compile and run `./program` and check if the output aligns with your prediction.  If it does not, revisit the code and identify your mistake.  You may find it helpful to add additional print statements.

## Reflection Questions
Use what you learned from these exercises to answer the following questions.
1. How does the `minheap.hpp + minheap-private.hpp` combination differ from the more traditional `minheap.hpp + minheap.cpp` combination?  Why did we use the former in this case?
2. In the `Makefile`, why is there no rule to compile `minheap.o`?  Why is there no linking step?
3. What assumptions are made about the template type parameter `T` in `MinHeap`, `print`, and `uniqueInsert`?  In other words, what methods must this type support in each case?
4. How many versions of each template function and template class are created during compilation?
5. Why did we pass `ITERATIONS` to `d20` as a template parameter rather than a normal parameter?
6. What types of compile-time errors should we watch out for when using template functions and classes?
