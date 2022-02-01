# gtest examples

## Motivations for unit testing
 - Verify that your work is done correctly,
 - It is a necessary step for CI,
 - Refactorisations come with lower Risk,
 - They're (execution) low cost,  
 - Writing testable code improves your design.
 - [...]

## Do's and dont's in testing **WIP**
 - Test public interfaces,
 - Try to reduce the "stuff" your testing depends on,
 - [...]

## Test doubles
 - **Dummies** are objects are passed around but never actually used. 
               Usually they are just used to fill parameter lists.
 - **Fakes** are objects that actually have working implementations, 
             but usually take some shortcut which makes them not 
             suitable for production 
 - **Mocks** are pre-programmed with expectations which form a 
             specification of the calls they are expected to receive. 
             They can throw an exception if they receive a call they 
             don't expect and are checked during verification to ensure 
             they got all the calls they were expecting.
 - **Stubs** provide canned answers to calls made during the test, usually not 
             responding at all to anything outside what's programmed in 
             for the test.
 - **Spies** are stubs that also record some information based on how they 
             were called.   

## Happy path examples
This repository shows some happy path examples:
 - Provides examples of test doubles: dummy, fake, mock, stub, spy.
 - Provides examples of parameterized tests, in value and in type 

**Note** that this repository is very very far from exploiting the power
of gtest-gmock. [Read the docs](http://google.github.io/googletest/).

## Problematic stuff and workarounds
   Work in progress, but we can at least list them (note that 
   the word Mock will be used in ), 
- Mocking a function not in a class
- Mocking an external library with no virtual functions
- Testing stuff without refactoring the existing code

## References
 - [Everything about gtest/gmock](http://google.github.io/googletest/)
 - [Google test code and docs (v1.8.1)](https://github.com/google/googletest/blob/release-1.8.1)  
 - [More docu from ElectricRCAircraftGuy](https://github.com/ElectricRCAircraftGuy/eRCaGuy_dotfiles/tree/master/googletest)  
 - [Martin Fowler on test doubles](https://martinfowler.com/bliki/TestDouble.html)
 - [Why testing and how (blog)](https://blog.devgenius.io/why-testing-and-how-d7cf96c7223f)  
 - [Unittest (blog)](https://blog.devgenius.io/unit-tests-c70618dc1e25)  
 - [Dobles de tests (blog)](https://javi-kata.medium.com/dobles-de-tests-66dd6a6fdb7f)