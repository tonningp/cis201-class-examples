#include "message.h"
#include "mailbox.h"
#include "mailsystem.h"
#include "connection.h"
#include "telephone.h"

Connection::Connection(MailSystem& s, Telephone& p)
   : system(s), phone(p),
   INITIAL_PROMPT("Enter mailbox number followed by #\n"),
   MAILBOX_MENU_TEXT("Enter 1 to listen to your messages\n"
   "Enter 2 to change your passcode\n"
   "Enter 3 to change your greeting\n"),
   MESSAGE_MENU_TEXT("Enter 1 to listen to the current message\n"
   "Enter 2 to save the current message\n"
   "Enter 3 to delete the current message\n"
   "Enter 4 to return to the main menu\n")
{
   reset_connection();
}

void Connection::dial(string key)
{
   if (state == CONNECTED)
      connect(key);
   else if (state == RECORDING)
      login(key);
   else if (state == CHANGE_PASSCODE)
      change_passcode(key);
   else if (state == CHANGE_GREETING)
      change_greeting(key);
   else if (state == MAILBOX_MENU)
      mailbox_menu(key);
   else if (state == MESSAGE_MENU)
      message_menu(key);
}

void Connection::record(string voice)
{
   if (state == RECORDING || state == CHANGE_GREETING)
      current_recording += voice;
}

void Connection::hangup()
{
   if (state == RECORDING)
      current_mailbox->add_message(new Message(current_recording));
   reset_connection();
}

void Connection::reset_connection()
{
   current_recording = "";
   accumulated_keys = "";
   state = CONNECTED;
   phone.speak(INITIAL_PROMPT);
}

void Connection::connect(string key)
{
   if (key == "#")
   {
      current_mailbox = system.find_mailbox(accumulated_keys);
      if (current_mailbox != NULL)
      {
         state = RECORDING;
         phone.speak(current_mailbox->get_greeting());
      }
      else
         phone.speak("Incorrect mailbox number. Try again!");
      accumulated_keys = "";
   }
   else
      accumulated_keys += key;
}

void Connection::login(string key)
{
   if (key == "#")
   {
      if (current_mailbox->check_passcode(accumulated_keys))
      {
         state = MAILBOX_MENU;
         phone.speak(MAILBOX_MENU_TEXT);
      }
      else
         phone.speak("Incorrect passcode. Try again!");
      accumulated_keys = "";
   }
   else
      accumulated_keys += key;
}

void Connection::change_passcode(string key)
{
   if (key == "#")
   {
      current_mailbox->set_passcode(accumulated_keys);
      state = MAILBOX_MENU;
      phone.speak(MAILBOX_MENU_TEXT);
      accumulated_keys = "";
   }
   else
      accumulated_keys += key;
}

void Connection::change_greeting(string key)
{
   if (key == "#")
   {
      current_mailbox->set_greeting(current_recording);
      current_recording = "";
      state = MAILBOX_MENU;
      phone.speak(MAILBOX_MENU_TEXT);
   }
}

void Connection::mailbox_menu(string key)
{
   if (key == "1")
   {
      state = MESSAGE_MENU;
      phone.speak(MESSAGE_MENU_TEXT);
   }
   else if (key == "2")
   {
      state = CHANGE_PASSCODE;
      phone.speak("Enter new passcode followed by the # key");
   }
   else if (key == "3")
   {
      state = CHANGE_GREETING;
      phone.speak("Record your greeting, then press the # key");
   }
}

void Connection::message_menu(string key)
{
   if (key == "1")
   {
      string output = "";
      Message* m = current_mailbox->get_current_message();
      if (m == NULL) output += "No messages.\n";
      else output += m->get_text() + "\n";
      output += MESSAGE_MENU_TEXT;
      phone.speak(output);
   }
   else if (key == "2")
   {
      current_mailbox->save_current_message();
      phone.speak(MESSAGE_MENU_TEXT);
   }
   else if (key == "3")
   {
      current_mailbox->remove_current_message();
      phone.speak(MESSAGE_MENU_TEXT);
   }
   else if (key == "4")
   {
      state = MAILBOX_MENU;
      phone.speak(MAILBOX_MENU_TEXT);
   }
}


