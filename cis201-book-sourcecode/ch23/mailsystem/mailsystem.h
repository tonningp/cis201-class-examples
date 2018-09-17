#ifndef MAILSYSTEM_H
#define MAILSYSTEM_H

#include <vector>
#include <string>

using namespace std;

class Mailbox;

/**
   A system of voice mail boxes.
*/
class MailSystem
{
public:
   /**
      Constructs a voice mail system with a given number of
      mailboxes.
      @param mailbox_count the number of mailboxes
   */
   MailSystem(int mailbox_count);

   /**
      Locates a mailbox.
      @param ext the extension number
      @return the mailbox, or NULL if not found
   */
   Mailbox* find_mailbox(string ext) const;
private:
   vector<Mailbox*> mailboxes;
};

#endif
