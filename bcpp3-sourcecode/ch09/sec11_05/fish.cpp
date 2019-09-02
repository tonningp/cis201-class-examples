#include <iostream>

using namespace std;

const int NOT_HUNGRY = 0;
const int SOMEWHAT_HUNGRY = 1;
const int VERY_HUNGRY = 2;  

class Fish
{  
public:
   void eat();
   void move();
private:
   int hungry = NOT_HUNGRY;
};
   
void Fish::eat()
{
   cout << "Yum!" << endl;
   hungry = NOT_HUNGRY;      
}

void Fish::move()
{
   if (hungry == VERY_HUNGRY)
   {
      cout << "Looking for food" << endl;
   }
   else
   {
      cout << "Looking for love" << endl;
      hungry++;
   }
}
