#ifndef MAILBOX_H
#define MAILBOX_H

#include <string>
#include <queue>

using namespace std;

class Message;

/**
   A mailbox contains messages that can be listed, kept, or discarded.
*/
class Mailbox
{
public:
   /**
      Creates a mailbox object.
      @param a_passcode passcode number
      @param a_greeting greeting string
   */
   Mailbox(string a_passcode, string a_greeting);

   /**
      Checks if the passcode is correct.
      @param a_passcode a passcode to check
   */
   bool check_passcode(string a_passcode) const; 

   /**
      Adds a message to the mailbox.
      @param a_message the message to be added
   */
   void add_message(Message* a_message);

   /**
      Gets the current message.
      @return the current message
   */
   Message* get_current_message() const;

   /**
      Removes the current message from the mailbox.
   */
   void remove_current_message();

   /**
      Saves the current message.
   */
   void save_current_message();

   /**
      Changes the mailbox's greeting.
      @param new_greeting the new greeting string
   */
   void set_greeting(string new_greeting);

   /**
      Changes mailbox's passcode.
      @param new_passcode the new passcode
   */
   void set_passcode(string new_passcode);

   /**
      Gets the mailbox's greeting.
      @return the greeting
   */
   string get_greeting() const;
private:
   queue<Message*> new_messages;
   queue<Message*> kept_messages;
   string passcode;
   string greeting;
};

inline Mailbox::Mailbox(string a_passcode, string a_greeting)
   : passcode(a_passcode), greeting(a_greeting)
{
}

inline bool Mailbox::check_passcode(string a_passcode) const
{
   return passcode == a_passcode;
}

inline void Mailbox::add_message(Message* a_message)
{
   new_messages.push(a_message);
}

inline void Mailbox::set_greeting(string new_greeting)
{
   greeting = new_greeting;
}

inline void Mailbox::set_passcode(string new_passcode)
{
   passcode = new_passcode;
}

inline string Mailbox::get_greeting() const
{
   return greeting;
}

#endif
