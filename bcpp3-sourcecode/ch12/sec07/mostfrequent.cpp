#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
   This program shows how a more efficient algorithm can greatly speed up
   the task of finding the most frequent element in a vector.
*/

/**
   Counts how often a value occurs in a vector.
   @param a the vector
   @param value the value to count
   @return the number of occurrences of value in a
*/
int count(vector<int> a, int value)
{
   int count = 0;
   for (int i = 0; i < a.size(); i++)
   {
      if (a[i] == value) { count++; }
   }
   return count;
}

/**
   Computes the largest value of a vector.
   @param a the vector
   @return the largest value in a
*/
int max(vector<int> values)
{
   int largest = values[0];
   for (int i = 1; i < values.size(); i++)
   {
      if (values[i] > largest)
      {
         largest = values[i];
      }
   }
   return largest;
}

/**
   Finds a value in a vector, using the linear search 
   algorithm.
   @param a the vector to search
   @param value the value to find
   @return the index at which the value occurs, or -1
   if it does not occur in the vector
*/
int search(vector<int> a, int value)
{  
   for (int i = 0; i < a.size(); i++)
   {  
      if (a[i] == value) { return i; }
   }
   return -1;
}

/**
   Returns the most frequently occurring value in a vector.
   @param a a vector
   @return the most frequently occurring value in a
*/
int most_frequent1(vector<int> a)
{
   vector<int> counts(a.size());
   for (int i = 0; i < a.size(); i++) // O(n*n)
   {
      counts[i] = count(a, a[i]); // O(n) in each iteration
   }
      
   int highest_frequency = max(counts); // O(n)
   int highest_frequency_index = search(counts, highest_frequency); // O(n)
   return a[highest_frequency_index];      
}

/**
   Returns the most frequently occurring value in a vector.
   @param a a vector
   @return the most frequently occurring value in a
*/
int most_frequent2(vector<int> a)
{
   sort(a.begin(), a.end()); // O(n log(n))
   vector<int> counts(a.size());
   
   int count = 0;
   for (int i = 0; i < a.size(); i++) // O(n)
   {
      count++;
      if (i == a.size() - 1 || a[i] != a[i + 1])
      {
         counts[i] = count;
         count = 0;
      }
   }
   
   int highest_frequency = max(counts); // O(n)
   int highest_frequency_index = search(counts, highest_frequency); // O(n)
   return a[highest_frequency_index];
}

int main()
{
   srand(time(0));
   vector<int> values;
   int k = 400;
   // Adds one times 1, two times 2, three times 3, ... , k times k
   for (int i = 1; i <= k; i++)
   {
      for (int j = 1; j <= i; j++)
      {
         values.push_back(i);
      }
   }
   // This function shuffles the vector randomly
   random_shuffle(values.begin(), values.end());

   // Copies the values into a vector and runs the first version
   // of the algorithm
   vector<int> a = values;
   int before = time(0);
   int result = most_frequent1(a);
   int after = time(0);
   cout << result << endl;
   cout << "Expected: " << k << endl;      
   cout << "Elapsed time: " << after - before << " seconds" << endl;

   // Copies the same values and runs the second version
   vector<int> b = values;
   before = time(0);
   result = most_frequent2(b);
   after = time(0);
   cout << result << endl;
   cout << "Expected: " << k << endl;      
   cout << "Elapsed time: " << after - before << " seconds" << endl;

   return 0;
}
