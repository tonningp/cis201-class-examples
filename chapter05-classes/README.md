# Goals
- To be able to implement your own classes
- To master the separation of interface and implementation
- To understand the concept of encapsulation
- To design and implement accessor and mutator member functions
- To understand object construction 
- To learn how to distribute a program over multiple source file
# Chapter Contents
- [05.01-discovering-classes ](05.01-discovering-classes)
- [05.02-interfaces ](05.02-interfaces)
- [05.03-encapsulation ](05.03-encapsulation)
- [05.04-member-functions ](05.04-member-functions)
- [05.05-default-constructors ](05.05-default-constructors)
- [05.06-constructors-with-parameters ](05.06-constructors-with-parameters)
- [05.07-accessing-data-fields ](05.07-accessing-data-fields)
- [05.08-comparing-member-functions-with-nonmember-function
](05.08-comparing-member-functions-with-nonmember-function)
- [05.09-separate-compilation ](05.09-separate-compilation)

# Summary
1. A class represents a concept. Instead of groups of related variables, try designing a class for the underlying concept.
2. Every class has a public interface: a collection of member functions through which the objects of the class can be manipulated.
3. A constructor is used to initialize objects when they are created. A constructor with no parameters is called a default constructor.
4. A mutator member function changes the state of the object on which it operates. 
5. An accessor member function does not modify the object. Accessors must be
tagged with const. 
6. Every class has a private implementation: data fields that store the state of an
object. 
7.	Encapsulation is the act of hiding implementation details. 
8. Encapsulation protects the integrity of object data.
9. By keeping the implementation private, we protect it from being accidentally corrupted.
10.	Encapsulation enables changes in the implementation without affecting users of a class.
11.	Use the const keyword when defining accessor member functions. 
12. The object on which a member function is applied is the implicit parameter.
Every member function has an implicit parameter.
13. Explicit parameters of a member function are listed in the function definition.
14. The purpose of a constructor is to initialize an object’s data fields.
15. A default constructor has no parameters.
16. It is particularly important to initialize all numeric fields in a constructor because they are not automatically initialized.
17.	A function name is overloaded if there are different versions of the function, distinguished by their parameter types.
18. Private data fields can only be accessed by member functions of the same class.
19. The code of complex programs is distributed over multiple files.
20. Header files contain the definitions of classes and declarations of shared con- stants, functions, and variables.
21. Source files contain the function implementations.


# Instructor Notes
- Pay attention to the Quality Tips and the Productivity Hints
