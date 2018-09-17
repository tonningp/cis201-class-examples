#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

using namespace std;

/**
   A message left by a caller.
*/
class Message 
{
public:
   /**
      Constructs a message object.
      @param message_text the message text
   */
   Message(string message_text);

   /**
      Gets the message text.
      @ return message text
   */
   string get_text() const;
private:
   string text;
};

inline Message::Message(string message_text) 
      : text(message_text) {}

inline string Message::get_text() const
{
   return text;
}

#endif
