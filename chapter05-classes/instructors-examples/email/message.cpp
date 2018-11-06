#include "message.h"


Message::Message(std::string rec,std::string send,const Time &t)
{
    m_recipient = rec;
    m_sender = send;
    m_timestamp = t;
}

void Message::append(const std::string &line)
{
   m_message += "\n";
   m_message += line;
}

std::string Message::to_string() const
{
    std::string s;  
    s = "To: ";
    s += m_sender;
    s += "\nFrom: " + m_recipient;
    s += "\n" + m_message;
    return s;

}

void Message::print() const
{
    std::cout << to_string();
}
