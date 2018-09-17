# Functions

# Goals
- To be able to program functions and procedures
- To become familiar with the concept of parameter passing
- To recognize when to use value and reference parameters
- To appreciate the importance of function comments
- To be able to determine the scope of variables
- To minimize the use of side effects and global variables
- To develop strategies for decomposing complex tasks into simpler ones
- To document the responsibilities of functions and their callers with preconditions
- To learn the fundamental principles of testing and debugging

# Chapter Contents

- [4.01-functions-as-black-boxes]( 4.01-functions-as-black-boxes)
- [4.02-implementing-functions]( 4.02-implementing-functions)
- [4.03-function-comments]( 4.03-function-comments)
- [4.04-return-values]( 4.04-return-values)
- [4.05-parameters]( 4.05-parameters)
- [4.06-side-effects]( 4.06-side-effects)
- [4.07-procedures]( 4.07-procedures)
- [4.08-reference-parameters]( 4.08-reference-parameters)
- [4.09-variable-scope-and-global-variables]( 4.09-variable-scope-and-global-variables)
- [4.10-stepwise-refinement]( 4.10-stepwise-refinement)
- [4.11-case-study-from-pseudocode-to-code]( 4.11-case-study-from-pseudocode-to-code)
- [4.12-walkthroughs]( 4.12-walkthroughs)
- [4.13-preconditions]( 4.13-preconditions)
- [4.14-unit-testing]( 4.14-unit-testing)
- [4.15-the-debugger]( 4.15-the-debugger)

# Summary
1.	A function receives input parameters and computes a result that depends on those inputs.
2.	Parameter values are supplied in the function call. The return value is the result that the function computes.
3.	When defining a function, you provide a name and type for each parameter and a type for the result.
4.	Turn computations that can be reused into functions. 
5.	Function comments explain the purpose of the function and the meaning of the
parameters and return value, as well as any special requirements. 
6.	The return statement terminates a function call and yields the function result.
7.	A predicate function returns a Boolean value.
8.	Parameter variables hold the parameter values supplied in the function call.
9.	A side effect is an externally observable effect caused by a function call, other than the returning of a result.
10. A procedure is a sequence of actions that depends on parameters and does not yield a result.
11.	Use a return type of void to indicate that a function does not return a value. 
12. A reference parameter denotes a reference to a variable that is supplied in a
function call.
13. The scope of a variable is the part of the program in which it is visible.
14.	A local variable is defined inside a function. A global variable is defined outside a function.
15. Use the process of stepwise refinement to decompose complex tasks into simpler ones.
16. Pseudocode is a mixture of English and source code that is used in the early stages of implementing complex code.
17.	A walkthrough is a manual simulation of program code.
18. Preconditions are documented restrictions on the function parameters.
19. A black-box test does not consider the internal structure of a program; a white-box test does.
20. A unit test checks a function in isolation. 
21. A unit test framework allows you to organize your unit tests. 
22. A boundary case is a test case that is at the boundary of valid input

# Instructor Notes
- Pay attention to the Quality Tips and the Productivity Hints
