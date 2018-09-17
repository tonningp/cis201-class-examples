#include "message.h"
#include "mailbox.h"

Message* Mailbox::get_current_message() const
{
   if (new_messages.size() > 0)
      return new_messages.front();
   if (kept_messages.size() > 0)
      return kept_messages.front();
   return NULL;
}

void Mailbox::remove_current_message()
{
   if (new_messages.size() > 0) 
   {
      Message* m = get_current_message();
      new_messages.pop();
      delete m;
   }
   else if (kept_messages.size() > 0)
   {
      Message* m = get_current_message();
      kept_messages.pop();
      delete m;
   }
}

void Mailbox::save_current_message()
{
   Message* m = get_current_message();
   if (m != NULL)
   {
      kept_messages.push(new Message(*m));
      remove_current_message();
   }
}
