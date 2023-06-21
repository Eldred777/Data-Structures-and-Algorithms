#include "LinkedList.hpp"

// Returns the length of the list
template <typename T>
size_t LinkedList<T>::length()
{
  ConsCell<T> cell = this->head;
  size_t count = 1;
  while (cell.cdr) // is not null
  {
    cell = cell.cdr;
    count++;
  }
  return count;
}
// TODO: TEST behaviour when this.head=NULL

template <typename T>
ConsCell<T> &LinkedList<T>::last()
{
  // This is essentially reused from length, stripping the count.
  ConsCell<T> cell = this->head;
  while (cell.cdr)
  {
    cell = cell.cdr;
  }
  return cell;
}
// TODO: after testing length, if any changes were made propagate them here

// Append a cons cell to the current list.
template <typename T>
void LinkedList<T>::append(ConsCell<T> &cell)
{
  auto last_cell = this->last();
  last_cell.cdr = cell;
}
// TODO: test

// Append a new cons cell to the current list, containing `datum`
template <typename T>
void LinkedList<T>::append(T datum)
{
  auto last_cell = this->last();
  last_cell.cdr = new ConsCell(datum);
}
// TODO: test

// Append a cons cell to the current list.
// NOTE: cell's cdr is modified to point to `this.head`
template <typename T>
void LinkedList<T>::prepend(ConsCell<T> &cell)
{
  cell.cdr = this.head;
  this.head = &cell;
}
// TODO: test

// Append a new cons cell to the current list, containing `datum`
template <typename T>
void LinkedList<T>::prepend(T datum)
{
  auto cell = new ConsCell<T>(datum, this.head);
  cell.cdr = this->head;
  this.head = &cell;
}
// TODO: test

template <typename T>
bool LinkedList<T>::insert(size_t index)
{
  return;
}
// TODO: implement

template <typename T>
void LinkedList<T>::remove(T index)
{
  return;
}
// TODO: implement

template <typename T>
void pop(size_t index)
{
  return new ConsCell();
}
// TODO: implement

template <typename T>
void LinkedList<T>::join(LinkedList<T> &list)
{
  this->append(list->head);
}
// TODO: test

template <typename T>
void LinkedList<T>::clone()
{
  return;
}
// TODO: implement

template <typename T>
void LinkedList<T>::clear()
{
  return;
}
// TODO: implement

// ------------------------------------------------------------
// ------------------------------------------------------------
// ------------------------------------------------------------
#include <iostream>

template <typename T>
std::ostream &operator<<(std::ostream &, ConsCell<T>);
template <typename T>
std::ostream &operator<<(std::ostream &, LinkedList<T>);

template <typename T>
bool operator==(ConsCell<T> &, ConsCell<T> &);
template <typename T>
bool operator==(LinkedList<T> &, LinkedList<T> &);

template <typename T>
std::ostream &operator<<(std::ostream &os, ConsCell<T> cell)
{
  // TODO: implement
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, LinkedList<T> list)
{
  // TODO: implement
  return os;
}

template <typename T>
bool operator==(ConsCell<T> &l1, ConsCell<T> &l2)
{
  // TODO: implement
  return true;
}

template <typename T>
bool operator==(LinkedList<T> &l1, LinkedList<T> &l2)
{
  // TODO: implement
  return true;
}