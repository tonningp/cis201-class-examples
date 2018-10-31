#include "mailbox.h"

MailBox::MailBox()
{
    m_messages = "";
}

void MailBox::add_message(Message &m)
{
    m_messages += "\n";
    m_messages += m.to_string();
}

Message MailBox::get_message(int i) const
{
    std::size_t found;
    for(int msg=0;msg < i;msg++)
    {
		  found = m_messages.find("From:",found+1);
    }
    if (found!=std::string::npos)
        std::cout << "From found at: " << found << '\n';
    return Message();
}

void MailBox::remove_message(int i)
{
}
