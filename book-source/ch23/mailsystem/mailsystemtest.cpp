#include "mailsystem.h"
#include "telephone.h"
#include "connection.h"

int main()
{
   const int MAILBOX_COUNT = 20;
   MailSystem system(MAILBOX_COUNT);
   Telephone p;
   Connection c(system, p);
   p.run(c);
   return 0;
}

