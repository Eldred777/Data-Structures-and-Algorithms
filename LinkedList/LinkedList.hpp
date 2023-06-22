#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__

#include <cstddef>

// TODO: Implement: iter, toString, zip (casting?)
// TODO: Reference counted ConsCells to support merged lists? This may even work for circular lists?
// TODO: sorting algorithms
// TODO: Is there a way to enforce null pointer safety in this? Perhaps implementing a next(). This will be much easier if I implement the Maybe monad.

template <typename T>
struct ConsCell;

template <typename T>
struct LinkedList
{
  ConsCell<T> *head = 0;

  // TODO: constructor from array (iterable?) of T

  // TODO: deconstructor

  bool isEmpty() { return bool(head); }; // TODO: test
  size_t length();
  ConsCell<T> &last();
  void append(ConsCell<T> &);
  void append(T);
  void prepend(ConsCell<T> &);
  void prepend(T);
  void insert(size_t);
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
  ConsCell<T> *cdr;

  // ConsCell() {}

  ConsCell(T datum)
  {
    car = datum;
    cdr = 0;
  }

  ConsCell(T datum, ConsCell<T> *cell)
  {
    car = datum;
    cdr = cell;
  }

  // TODO: deconstructor?

  LinkedList<T> toList()
  {
    return LinkedList{this};
  }
};

#include "LinkedList.tpp"

#endif //__LINKEDLIST__H__
