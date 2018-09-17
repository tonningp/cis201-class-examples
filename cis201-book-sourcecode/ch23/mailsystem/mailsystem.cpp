#include <sstream>
#include "mailbox.h"
#include "mailsystem.h"

using namespace std;

MailSystem::MailSystem(int mailbox_count)
{
   for (int i = 0; i < mailbox_count; i++)
   {
      ostringstream passcode;
      passcode << i;
      ostringstream greeting;
      greeting << "You have reached mailbox " << i
         << ". \nPlease leave a message now.";
      mailboxes.push_back(new Mailbox(passcode.str(), greeting.str()));
   }
}

int string_to_int(string s)
{
   istringstream instr(s);
   int n;
   instr >> n;
   return n;
}

Mailbox* MailSystem::find_mailbox(string ext) const
{
   int i = string_to_int(ext);
   if (1 <= i && i <= mailboxes.size())
      return mailboxes[i];
   return NULL;
}



