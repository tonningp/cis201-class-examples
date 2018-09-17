#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

class SequenceGenerator
{
public:
   SequenceGenerator(int sv); // Can set starting value
   int operator()();
private:
   int current;
};

SequenceGenerator::SequenceGenerator(int sv)
{
   current = sv;
}

inline int SequenceGenerator::operator()()
{
   int r = current;
   current++;
   return r;
}

class DivisibleBy
{
public:
   DivisibleBy(int in);
   bool operator()(int x);
private:
   int n;
};

DivisibleBy::DivisibleBy(int in) : n(in) {}
inline bool DivisibleBy::operator()(int x)
{
   return 0 == x % n;
}

void sieve(deque<int>& numbers)
{
   if (numbers.empty())
      return;
   int n = numbers.front();
   numbers.pop_front();
   deque<int>::iterator p =
      remove_if(numbers.begin(), numbers.end(), DivisibleBy(n));
   numbers.erase(p, numbers.end());
   sieve(numbers);
   numbers.push_front(n);
}

int main()
{
   deque<int> a(100);
   generate_n(a.begin(), 100, SequenceGenerator(2));
   sieve(a);
   for (deque<int>::iterator p = a.begin(); p != a.end(); ++p)
      cout << *p << " ";
   cout << endl;
   return 0;
}
