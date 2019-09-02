#include <iostream>
#include <string>
#include <vector>
#include "question.h"

class ChoiceQuestion : public Question
{
public:
   /**
      Constructs a choice question with no choices.
   */
   ChoiceQuestion();

   /**
      Adds an answer choice to this question.
      @param choice the choice to add
      @param correct true if this is the correct choice, false otherwise
   */
   void add_choice(string choice, bool correct);

   void display() const;
private:
   vector<string> choices;
};

ChoiceQuestion::ChoiceQuestion()
{
}

void ChoiceQuestion::add_choice(string choice, bool correct)
{
   choices.push_back(choice);
   if (correct)
   {
      // Convert choices.size() to string  
      string num_str = to_string(choices.size());
      set_answer(num_str);
   }
}

void ChoiceQuestion::display() const
{
   // Display the question text
   Question::display();
   // Display the answer choices
   for (int i = 0; i < choices.size(); i++)
   {
      cout << i + 1 << ": " << choices[i] << endl;      
   }
}

int main()
{
   string response;
   cout << boolalpha;

   // Ask a basic question

   Question q1;
   q1.set_text("Who was the inventor of C++?");
   q1.set_answer("Bjarne Stroustrup");

   q1.display();
   cout << "Your answer: ";
   getline(cin, response);
   cout << q1.check_answer(response) << endl;

   // Ask a choice question

   ChoiceQuestion q2;
   q2.set_text("In which country was the inventor of C++ born?");
   q2.add_choice("Australia", false);
   q2.add_choice("Denmark", true);
   q2.add_choice("Korea", false);
   q2.add_choice("United States", false);

   q2.display();
   cout << "Your answer: ";
   getline(cin, response);
   cout << q2.check_answer(response) << endl;   

   return 0;
}

