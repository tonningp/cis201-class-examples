#include "message.h"


Message::Message(std::string rec,std::string send,Time t)
{
    m_recipient = rec;
    m_sender = send;
    m_timestamp = t;
}
