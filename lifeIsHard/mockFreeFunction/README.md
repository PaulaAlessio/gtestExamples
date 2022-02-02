# Problem

You want to test a function that internally
calls a free function of an external library.
You do not even have access to the body of the 
function. 

## Possible solutions

### Suggested by googletest documentation

Add an interface It is not possible to directly mock a free 
function (i.e. a C-style function or a static method). 
If you need to, you can rewrite your code to use an interface 
(abstract class).

Instead of calling a free function (say, `OpenFile`) directly, 
introduce an interface for it and have a concrete subclass that 
calls the free function:

Your code should talk to the Interface to open a file. Now it is
easy to mock out the function.

This may seem like a lot of hassle, but in practice you often 
have multiple related functions that you can put in the same interface, so the per-function syntactic overhead will be much lower.

If you are concerned about the performance overhead incurred by 
virtual functions, and profiling confirms your concern, 
you can combine this with the recipe for mocking non-virtual methods.

See OpenFile -- mockFreeFunctionInterfaceUnitTest

### You cannot change the already existing test 

We present one solution which use linking time replacement 
and Google Mock framework.

See CaesarDeciphering -- mockFreeFunctionUnitTest 