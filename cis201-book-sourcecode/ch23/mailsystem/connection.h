#ifndef CONNECTION_H
#define CONNECTION_H

#include "mailsystem.h"
#include "telephone.h"
#include "mailbox.h"

using namespace std;

/**
   Connects a phone to the voice mail system. 
   The purpose of this class is to keep track 
   of the state of a connection, because the phone 
   itself is only the source of individual key presses.
*/
class Connection
{
public:
   /**
      Constructs a Connection object.
      @param s a MailSystemn object
      @param p a Telephone object
   */
   Connection(MailSystem& s, Telephone& p);

   /**
      Responds to the user's pressing a key
      on the phone touchpad.
      @param key the phone key pressed by the user
   */
   void dial(string key);

   /**
      Records voice.
      @param voice voice spoken by the user
   */
   void record(string voice);

   /**
      The user hangs up the phone.
   */
   void hangup();

private:
   /**
      Resets the connection to the initial state 
      and prompt for mailbox number.
   */
   void reset_connection();

   /**
      Tries to connect the user with the specified mailbox.
      @param key the phone key pressed by the user
   */
   void connect(string key);

   /**
      Tries to log in the user.
      @param key the phone key pressed by the user
   */
   void login(string key);

   /**
      Changes the passcode.
      @param key the phone key pressed by the user
   */
   void change_passcode(string key);

   /**
      Changes the greeting.
      @param key the phone key presed by the user
   */
   void change_greeting(string key);

   /**
      Responds to the users selection from mailbox menu.
      @param key the phone key pressed by the user
   */
   void mailbox_menu(string key);

   /**
      Responds to the user's selection from message menu.
      @param key the phone key pressed by the user
   */
   void message_menu(string key);

   MailSystem& system;
   Mailbox* current_mailbox;
   string current_recording;
   string accumulated_keys;
   Telephone& phone;

   enum states {DISCONNECTED, CONNECTED, RECORDING, 
      MAILBOX_MENU, MESSAGE_MENU, 
      CHANGE_PASSCODE, CHANGE_GREETING};
   enum states state;

   const string INITIAL_PROMPT;
   const string MAILBOX_MENU_TEXT;
   const string MESSAGE_MENU_TEXT;
};

#endif
