#ifndef TELEPHONE_H
#define TELEPHONE_H

#include <iostream>
#include <string>

using namespace std;

class Connection;

/**
   A telephone that takes simulated keystrokes and voice input
   from the user and simulates spoken text.
*/
class Telephone
{
public:
   /**
      Speak a message to standard output.
      @param output the text that will be spoken
   */
   void speak(string output);

   /**
      Loops reading user input and passes the input
      to the Connection object's functions dial, record,
      or hangup. 
      @param c the connection that connects this phone
      to the voice mail system
   */
   void run(Connection& c);
};

inline void Telephone::speak(string output)
{
   cout << output;
}

#endif
