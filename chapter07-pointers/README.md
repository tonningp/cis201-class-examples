# Goals

- To learn how to declare, initialize, and use pointers 
- To become familiar with dynamic memory allocation and deallocation
- To use pointers in common programming situations that involve optional and shared objects
- To avoid the common errors of dangling pointers and memory leaks
- To understand the relationship between arrays and pointers 
- To be able to convert between string objects and character pointers 
- To learn about function pointers and how they are used

# Chapter Contents
- [7.01-pointers-and-memory-allocation ](7.01-pointers-and-memory-allocation)
- [7.02-deallocating-dynamic-memory ](7.02-deallocating-dynamic-memory)
- [7.03-common-uses-for-pointers ](7.03-common-uses-for-pointers)
- [7.04-arrays-and-pointers ](7.04-arrays-and-pointers)
- [7.05-pointers-to-character-strings ](7.05-pointers-to-character-strings)
- [7.06-pointers-to-functions ](7.06-pointers-to-functions)

# Summary

1.	Use dynamic memory allocation if you do not know in advance how many objects you need.
2.	The new operator allocates an object from the heap. 
3.	Dynamically allocated objects live until they are explicitly reclaimed. 
4.	A pointer denotes the location of a value in memory. 
5.	The * operator locates the value to which a pointer points. 
6.	Finding the value to which a pointer points is called dereferencing.
7.	Use the -> operator to access a data member or a member function through an object pointer.
8.	The NULL pointer does not point to any object.
9.	It is an error to dereference an uninitialized pointer or the NULL pointer.
10. In a member function, the this pointer points to the implicit parameter.
11. You must reclaim dynamically allocated objects with the delete operator.
12. Using a dangling pointer (a pointer that has not been initialized or has been deleted) is a serious programming error.
13. Every call to new should have a matching call to delete. 
14. Pointers can be used to model optional values (by using a NULL pointer when the
value is not present). 
15. Pointers can be used to provide shared access to a common value. 
16. The value of an array variable is a pointer to the starting element of the array.
17.	Pointer arithmetic means adding an integer offset to an array pointer, yielding a pointer that skips past the given number of elements.
18. The array/pointer duality law states that a[n] is identical to *(a + n), where a is a pointer into an array and n is an integer offset.
19. When passing an array to a function, only the starting address is passed.
20. Low-level string manipulation functions use pointers of type char*.
21. You can construct string variables from char* pointers.
22. You can use the c_str member function to obtain a char* pointer from a string object.
23. The name of a function without () denotes a function pointer. 
24. Use typedef to make function pointer types easier to read.

# Instructor Notes
- Pay attention to the Quality Tips and the Productivity Hints
