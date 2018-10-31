#ifndef MESSAGE_H
#define MESSAGE_H
#include<iostream>
#include<string>
#include "ccc_time.h"
/*
 Exercise P5.12. Design a class Message that models an e-mail message. A message has
 a recipient, a sender, and a message text. Support the following member functions:
 •  A constructor that takes the sender and recipient and sets the time stamp to the current time
 •  A member function append that appends a line of text to the message body 
 •  A member function to_string that makes the message into one long string like
 this: "From: Harry Hacker\nTo: Rudolf Reindeer\n ..." 
 •    A member function print that prints the message text. Hint: Use to_string.
 Write a program that uses this class to make a message and print it.
*/

class Message
{
    std::string m_recipient,m_sender,m_message;
    Time m_timestamp;

public:
    Message();
    Message(const std::string &recipient,const std::string &sender,const Time &timestamp);
    void append(const std::string &line);
    std::string to_string();
    void print() const;
};

#endif
