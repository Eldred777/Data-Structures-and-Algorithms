#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__

// TODO: Implement: iter, toString
// TODO: Reference counted ConsCells to support merged lists? This may even work for circular lists?
// TODO: sorting algorithms

template <typename T>
struct ConsCell;

template <typename T>
struct LinkedList
{
  ConsCell<T> *head = 0;

  // TODO: constructor from array (iterable?) of T

  // TODO: deconstructor

  bool isEmpty(){return bool(head)}; // TODO: test
  size_t length();
  ConsCell<T> &last();
  void append(ConsCell<T> &);
  void append(T);
  void prepend(ConsCell<T> &);
  void prepend(T);
  bool insert(size_t);
  void remove(T);
  void pop(size_t);
  ConsCell<T> &search(T);
  void join(LinkedList<T> &);
  void clone();
  void clear();
};

// Nodes for a linked list. Note we use LISP convention of car and cdr for
// naming the parts of the cons cell.
template <typename T>
struct ConsCell
{
  T car;
  // Initialise with null pointer
  ConsCell<T> *cdr = 0;

  ConsCell(T datum)
  {
    return new ConsCell{datum, 0};
  }

  // TODO: deconstructor

  LinkedList<T> toList()
  {
    return LinkedList{this};
  }
};

#include "LinkedList.tpp"

#endif //__LINKEDLIST__H__
