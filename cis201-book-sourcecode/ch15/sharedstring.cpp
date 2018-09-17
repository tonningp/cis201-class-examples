#include <iostream>

using namespace std;

class SharedString 
{
public:
   SharedString();
   SharedString(const char* right);
   SharedString(const SharedString& right);
   ~SharedString();
   SharedString& operator=(const SharedString& right);
private:
   class StringReference;
   StringReference* p;
   void reassign(StringReference*);
};

class SharedString::StringReference 
{
public:
   int count;
   char* buffer;
   StringReference(const char* right);
   ~StringReference();
};

SharedString::SharedString() : p(NULL)
{
   cout << "Entering SharedString()\n";
}

SharedString::SharedString(const char* right) : p(NULL) 
{
   cout << "Entering SharedString(const char*) ";
   reassign(new StringReference(right));
}

SharedString::SharedString(const SharedString& right) : p(NULL)
{
   cout << "Entering SharedString(const SharedString&) ";
   reassign(right.p);
}

SharedString::~SharedString()
{
   cout << "Entering ~SharedString() ";
   reassign(NULL);
}

SharedString& SharedString::operator=(const SharedString& right)
{
   cout << "Entering operator=(const SharedString&) ";
   reassign(right.p);
   return *this;
}

void SharedString::reassign(SharedString::StringReference* np)
{
   if (np == NULL) // Print old values
      cout << "value: " << p->buffer << " count: " << p->count << "\n";
   if (np != NULL) // Increment count on the new value
      np->count += 1;
   if (p != NULL)  // Decrement reference counts on old value
   {
      p->count -= 1;
      if (p->count == 0)
         delete p;
   }
   p = np;  // Change binding
   if (p != NULL) // Print new values
      cout << "value: " << p->buffer << " count: " << p->count << "\n";
}

SharedString::StringReference::StringReference(const char* right)
{
   count = 0;
   int n = 0;
   while (right[n] != '\0')
      n++;
   buffer = new char[1 + n];
   for (int i = 0; i < n; i++)
      buffer[i] = right[i];
   buffer[n] = '\0';
}

SharedString::StringReference::~StringReference()
{
   delete[] buffer;
}

SharedString g; // Global value

int main()
{
      cout << "Entering main\n";
      cout << "SharedString a = \"Fred\";\n";
   SharedString a = "Fred";
      cout << "SharedString b = \"Alice\";\n";
   SharedString b = "Alice";
      cout << "SharedString c;\n";
   SharedString c;
      cout << "c = a;\n";
   c = a;
      cout << "a = b;\n";
   a = b;
      cout << "g = b;\n";
   g = b;
      cout << "Exiting main\n";
   return 0;
}
