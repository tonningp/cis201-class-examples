/*
   This program demonstrates a decision tree for an animal 
   guessing game.
*/

#include <iostream>
#include <string>
#include "binary_tree.h"

using namespace std;

int main()
{
   BinaryTree question_tree(
      BinaryTree("Is it a mammal?",
         BinaryTree("Does it have stripes?",
            BinaryTree("Is it a carnivore?",
               BinaryTree("It is a tiger."),
               BinaryTree("It is a zebra.")),
            BinaryTree("It is a pig.")),
      BinaryTree("Does it fly?",
         BinaryTree("It is an eagle."),
         BinaryTree("Does it swim?",
            BinaryTree("It is a penguin."),
            BinaryTree("It is an ostrich.")))));

   bool done = false;
   
   while (!done)
   {
      BinaryTree left = question_tree.left();
      BinaryTree right = question_tree.right();
      if (left.empty() && right.empty())
      {
         cout << question_tree.data() << endl;
         done = true;
      }
      else
      {
         string response;
         do
         {
            cout << question_tree.data() << " (y/n): ";
            cin >> response;
         } 
         while (response != "y" && response != "n");

         if (response == "y")
         {
            question_tree = left;         
         }
         else
         {
            question_tree = right;         
         }         
      }
   }
}
