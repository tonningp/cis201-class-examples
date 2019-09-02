#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
   A menu that is displayed on a console.
*/
class Menu
{
public:
   /**
      Constructs a menu with no options.
   */
   Menu();

   /**
      Adds an option to the end of this menu.
      @param option the option to add
   */
   void add_option(string option);

   /**
      Displays the menu, with options numbered starting with 1,
      and prompts the user for input. Repeats until a valid input 
      is supplied.
      @return the number that the user supplied
   */
   int get_input() const;
private:
   void display() const;

   vector<string> options;
};

Menu::Menu()
{
}

void Menu::add_option(string option)
{
   options.push_back(option);
}

void Menu::display() const
{
   for (int i = 0; i < options.size(); i++)
   {
      cout << i + 1 << ") " << options[i] << endl; 
   }
}

int Menu::get_input() const
{
   int input;
   do
   {
      display();
      cin >> input;
   }
   while (input < 1 || input > options.size());
   return input;
}

int main()
{
   Menu main_menu;
   main_menu.add_option("Open new account");
   main_menu.add_option("Log into existing account");
   main_menu.add_option("Help");
   main_menu.add_option("Quit");
   int input = main_menu.get_input();
   cout << "Input: " << input << endl;
   return 0;
}
