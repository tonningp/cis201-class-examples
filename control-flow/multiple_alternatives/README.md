3.3 Multiple Alternatives
Up to this point, you saw how to program a two-way branch with an if/else statement.  In many situations, there are more
than two cases. Consider the task of translating a value on the Richter scale, a measurement of the strength of an
earthquake, into a description of the likely impact. You use a sequence of if/else statements, like this:

if (richter >= 8.0)
   cout << "Most structures fall"; 
else if (richter >= 7.0)
   cout << "Many buildings destroyed"; 
else if (richter >= 6.0)
   cout << "Many buildings considerably damaged, some collapse"; 
else if (richter >= 4.5)
   cout << "Damage to poorly constructed buildings"; 
else
   cout << "Generally no damage";

As soon as one of the tests succeeds, a description is displayed, and no further tests arc attempted. If none of the four cases applies, an error message is printed. Figure 4 in the text shows the flowchart for this multiple-branch statement. (See ch03/richter.cpp for program.)

Note that the order of the tests is important. Suppose we reverse the order:
if (richter >= 4.5)
   cout << "Damage to poorly constructed buildings"; 
else if (richter >= 6.0)
   cout << "Many buildings considerably damaged,"
        << "some collapse"; 
else if (richter >= 7.0)
   cout << "Many buildings destroyed"; 
else if (richter >- 8.0)
   cout << "Most structures fall";

This does not work. Suppose richter has the value 7.1. That value matches the first condition, and a wrong description is displayed.
In this example, it is also important that we use an if/else/else test, not just multiple independent if statements. Consider this sequence of independent tests:

if (richter >= 8.0) // Didn't use else 
   cout << "Most structures fall"; 
if (richter >= 7.0)
   cout << "Many buildings destroyed"; 
if (richter >= 6.0)
   cout << "Many buildings considerably damaged, some collapse"; 
if (richter >= 4.5)
   cout << "Damage to poorly constructed buildings":

Now the alternatives are no longer exclusive. If richter is 7.1, then the last three tests all match, and three messages are printed.

When using multiple if/else statements, pay attention to the order of the conditions.

Multiple if/else statements can be combined to evaluate complex decisions.


