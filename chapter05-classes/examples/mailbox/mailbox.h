#ifndef MAILBOX_H
#define MAILBOX_H
#include "message.h"

/*
Design a class Mailbox that stores e-mail messages, using the Message class of Exercise P5.12. You don’t yet know how to store a collection of message objects. Instead, use the following brute force approach: The mailbox contains one very long string, which is the concatenation of all messages. You can tell where a new message starts by searching for a From: at the beginning of a line. This may sound like a dumb strategy, but surprisingly, many e-mail systems do just that.

Implement the following member functions:
    void Mailbox::add_message(Message m); 
    Message Mailbox::get_message(int i) const; 
    void remove_message(int i);

What do you do if the message body happens to have a line starting with "From: "? Then the to_string function of the Message class should really insert a > in front of the From: so that it reads >From:	. Again, this sounds dumb, but it is a strategy used by real e-mail systems. Extra credit if you implement this enhancement.
*/

class MailBox
{
    std::string m_messages;
public:
    MailBox();
    void add_message(Message &m);
    Message get_message(int i) const;
    void remove_message(int i);
};


#endif
