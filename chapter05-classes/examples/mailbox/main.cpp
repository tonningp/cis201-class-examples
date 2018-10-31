#include<iostream>
#include "ccc_time.h"
#include "message.h"
#include "mailbox.h"

int main()
{

    Message m("Paul Tonning","John Doe",Time());
    m.append("This is the first line of the message");

    MailBox mb;    
    mb.add_message(m);
    mb.add_message(m);
    mb.add_message(m);
    Message m2 = mb.get_message(3);
    mb.remove_message(3);

    return 0;
}
