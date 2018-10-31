#include "message.h"


Message::Message()
{
}

Message::Message(const std::string &rec,const std::string &send,const Time &t)
{
    m_recipient = rec;
    m_sender = send;
    m_timestamp = t;
}

void Message::append(const std::string &line)
{
}

std::string Message::to_string()
{
    return "From: Harry Hacker\nTo: Rudolf Reindeer\n ...";
}

void Message::print() const
{
}
