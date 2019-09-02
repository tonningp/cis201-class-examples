#ifndef LIST_H
#define LIST_H

using namespace std;

template <typename T>
class List
{
private:   
   class Node
   {
   public:
      /** 
          Constructs a node with a given data value.
          @param element the data to store in this node
      */
      Node(const T& element);
      T data;
      Node* previous;
      Node* next;
   };
public:      
   class Iterator
   {
   public:
      /**
         Constructs an iterator that does not point into any list.
      */
      Iterator();
      /**  
           Looks up the value at a position.
           @return the value of the node to which the iterator points
      */
      const T& operator*() const;
      /**
         Advances the iterator to the next node.
      */
      void operator++(); 
      void operator++(int dummy);
      /**
         Moves the iterator to the previous node.
      */
      void operator--(); 
      void operator--(int dummy);

      bool operator==(const Iterator& other) const;
      bool operator!=(const Iterator& other) const;
   private:
      Node* position;
      List* container;
   friend class List;
   };
 
   /**
      Constructs an empty list.
   */
   List();

   List(const List& other);
   ~List();
   List& operator=(const List& other);
   
   /**
      Appends an element to the list.
      @param element the value to append
   */
   void push_back(const T& element);
   /**
      Inserts an element into the list.
      @param iter the position before which to insert
      @param element the value to append
   */
   void insert(const Iterator& iter, const T& element);
   /**
      Removes an element from the list.
      @param iter the position to remove
      @return an iterator pointing to the element after the
      erased element
   */
   Iterator erase(const Iterator& iter);
   /**
      Gets the beginning position of the list.
      @return an iterator pointing to the beginning of the list
   */
   Iterator begin();
   /**
      Gets the past-the-end position of the list.
      @return an iterator pointing past the end of the list
   */
   Iterator end();
private:
   void copy(const List& other);
   void free();
   
   Node* first;
   Node* last;
friend class Iterator;
};

template <typename T>
List<T>::Node::Node(const T& element)
{  
   data = element;
   previous = nullptr;
   next = nullptr;
}

template <typename T>
List<T>::List()
{  
   first = nullptr;
   last = nullptr;
}

template <typename T>
void List<T>::push_back(const T& element)
{  
   Node* new_node = new Node(element);
   if (last == nullptr) // List is empty
   {  
      first = new_node;
      last = new_node;
   }
   else
   {  
      new_node->previous = last;
      last->next = new_node;
      last = new_node;
   }
}

template <typename T>
void List<T>::insert(const Iterator& iter, const T& element)
{  
   if (iter.position == nullptr)
   {  
      push_back(element);
      return;
   }

   Node* after = iter.position;
   Node* before = after->previous;
   Node* new_node = new Node(element);
   new_node->previous = before;
   new_node->next = after;
   after->previous = new_node;
   if (before == nullptr) // Insert at beginning
   {
      first = new_node;
   }
   else
   {
      before->next = new_node;
   }
}

template <typename T>
typename List<T>::Iterator List<T>::erase(const Iterator& iter)
{  
   Node* remove = iter.position;
   Node* before = remove->previous;
   Node* after = remove->next;
   if (remove == first)
   {
      first = after;
   }
   else
   {
      before->next = after;
   }
   if (remove == last)
   {
      last = before;
   }
   else
   {
      after->previous = before;
   }
   delete remove;
   Iterator r;
   r.position = after;
   r.container = this;
   return r;
}

template <typename T>
typename List<T>::Iterator List<T>::begin()
{  
   Iterator iter;
   iter.position = first;
   iter.container = this;
   return iter;
}

template <typename T>
typename List<T>::Iterator List<T>::end()
{  
   Iterator iter;
   iter.position = nullptr;
   iter.container = this;
   return iter;
}

template <typename T>
List<T>::Iterator::Iterator()
{  
   position = nullptr;
   container = nullptr;
}

template <typename T>
const T& List<T>::Iterator::operator*() const
{  
   return position->data;
}

template <typename T>
void List<T>::Iterator::operator++()
{  
   position = position->next;
}

template <typename T>
void List<T>::Iterator::operator++(int dummy)
{  
   operator++();
}

template <typename T>
void List<T>::Iterator::operator--()
{  
   if (position == nullptr)
   {
      position = container->last;
   }
   else 
   {
      position = position->previous;
   }
}

template <typename T>
void List<T>::Iterator::operator--(int dummy)
{
   operator--();
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& other) const
{  
   return position == other.position;
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const
{  
   return position != other.position;
}

template <typename T>
void List<T>::free()
{
   Node* to_delete = first;
   while (to_delete != nullptr)
   {
      Node* next_to_delete = to_delete->next;
      delete to_delete;
      to_delete = next_to_delete;
   }
}

template <typename T>
void List<T>::copy(const List& other)
{
   Node* just_copied = nullptr;
   Node* next_to_copy = other.first;
   first = nullptr;
   last = nullptr;
   while (next_to_copy != nullptr)
   {
      Node* copy = new Node(next_to_copy->data);
      copy->previous = just_copied;
      if (just_copied == nullptr)
      {
         first = copy;
      }
      else
      {
         just_copied->next = copy;
      }
      if (next_to_copy == other.last)
      {
         last = copy;
      }
      next_to_copy = next_to_copy->next;
      just_copied = copy;
   }
}

template <typename T>
List<T>::List(const List& other)
{
   copy(other);
}

template <typename T>
List<T>::~List()
{
   free();
}

template <typename T>
List<T>& List<T>::operator=(const List& other)
{
   if (this != &other)
   {
      free();
      copy(other);
   }      
}

#endif
