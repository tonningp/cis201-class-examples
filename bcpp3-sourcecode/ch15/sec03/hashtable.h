#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>

using namespace std;

/**
   Computes the hash code for a string.
   @param str a string
   @return the hash code
*/
int hash_code(const string& str);

class HashTable;
class Iterator;

class Node
{
private:
   string data;
   Node* next;

friend class HashTable;
friend class Iterator;
};

class Iterator
{
public:
   /**  
      Looks up the value at a position.
      @return the value of the node to which the iterator points
   */
   string get() const;
   /**
      Advances the iterator to the next node.
   */
   void next();
   /**
      Compares two iterators.
      @param other the iterator to compare with this iterator
      @return true if this iterator and other are equal
   */
   bool equals(const Iterator& other) const;
private:
   const HashTable* container;
   int bucket_index;
   Node* current;
   
friend class HashTable;
};

/**
   This class implements a hash table using separate chaining.
*/
class HashTable
{
public:
   /**
      Constructs a hash table.
      @param nbuckets the number of buckets
   */
   HashTable(int nbuckets);

   /**
      Tests for set membership.
      @param x the potential element to test
      @return 1 if x is an element of this set, 0 otherwise
   */
   int count(const string& x);

   /**
      Adds an element to this hash table if it is not already present.
      @param x the element to add
   */
   void insert(const string& x);

   /**
      Removes an element from this hash table if it is present.
      @param x the potential element to remove
   */
   void erase(const string& x);

   /**
      Returns an iterator to the beginning of this hash table.
      @return a hash table iterator to the beginning
   */
   Iterator begin() const;

   /**
      Returns an iterator past the end of this hash table.
      @return a hash table iterator past the end
   */
   Iterator end() const;

   /**
      Gets the number of elements in this set.
      @return the number of elements
   */
   int size() const;

private:
   vector<Node*> buckets;
   int current_size;   

friend class Iterator;
};

#endif
