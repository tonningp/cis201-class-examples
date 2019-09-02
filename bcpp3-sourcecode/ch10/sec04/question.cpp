#include <iostream>

#include "question.h"

Question::Question() 
{
}

void Question::set_text(string question_text)   
{
   text = question_text;
}

void Question::set_answer(string correct_response)
{
   answer = correct_response;
}

bool Question::check_answer(string response) const
{
   return response == answer;
}

void Question::display() const
{
   cout << text << endl;
}
