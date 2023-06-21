#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__

// TODO: Implement: pop, equals, iter, toString
// TODO: Reference counted ConsCells to support merged lists. This may even work for circular lists?

template <typename T>
struct LinkedList
{
  ConsCell<T> *head = 0;

  bool isEmpty(){return bool(head)}; // TODO: test
  size_t length();
  void append(); // TODO: implement
  void insert(); // TODO: implement
  void remove(); // TODO: implement
  void clear();  // TODO: implement
  void copy();   // TODO: implement
  void join();   // TODO: implement
};

// Nodes for a linked list. Note we use LISP convention for naming the parts of
// the cons cell.
template <typename T>
struct ConsCell
{
  T car;
  // Initialise with null pointer
  ConsCell<T> *cdr = 0;

  LinkedList<T> toList()
  {
    return LinkedList{this};
  }
};

#include "LinkedList.tpp"

#endif //__LINKEDLIST__H__
