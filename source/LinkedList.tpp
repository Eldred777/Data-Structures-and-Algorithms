#include "LinkedList.hpp"

#include <stdexcept>

// Returns the length of the list
template <typename T>
size_t LinkedList<T>::length()
{
  // Empty list case.
  if (!this->head)
  {
    return 0;
  }

  // List is non-empty.
  ConsCell<T> cell = this->head;
  size_t count = 1;

  // Traverse the list
  while (cell.cdr) // is not null
  {
    cell = *cell.cdr;
    count++;
  }

  return count;
}
// TODO: test, when this.head=NULL

// Returns the last cons cell of the list.
// Throws `std::length_error` if the list is empty.
template <typename T>
ConsCell<T> &LinkedList<T>::last()
{
  // TODO: error if this.head == NULL, how to deal with?
  // Maybe throw an error?
  if (!this->head)
  {
    throw std::length_error("last() called on an empty list");
  }

  ConsCell<T> cell = *this->head;

  while (cell.cdr)
  {
    cell = cell.cdr;
  }

  // TODO: non-terminating loop if list is cyclic

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
// This runs in O(n) time, as it must traverse the list.
template <typename T>
void LinkedList<T>::append(T datum)
{
  auto last_cell = this->last();
  last_cell.cdr = new ConsCell(datum);
}
// TODO: test

// Prepend a given cons cell to the current list.
// `cell` should be on the heap.
// NOTE: cell's cdr is modified to point to `this.head`
// This runs in O(1) time, as the head is immediately available.
template <typename T>
void LinkedList<T>::prepend(ConsCell<T> &cell)
{
  cell.cdr = this.head;
  this.head = &cell;
}
// TODO: test

// Prepend a new cons cell to the current list, containing `datum`
template <typename T>
void LinkedList<T>::prepend(T datum)
{
  auto cell = new ConsCell<T>(datum, this.head);
  cell.cdr = this->head;
  this.head = &cell;
}
// TODO: test

template <typename T>
void LinkedList<T>::insert(size_t index)
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
  return;
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
  auto head = this->head;
  auto cell_ptr = head;
  auto previous = cell_ptr;

  this->head = nullptr;

  while (cell_ptr->cdr)
  {
    // In the case of a circular list, break.
    if (cell_ptr == head)
    {
      break;
    }

    // Keep track of previous, go to next cell, delete the previous cell.
    previous = cell_ptr;
    cell_ptr = cell_ptr->cdr;
    delete previous;
  }
}
// TODO: test: likely need to use valgrind to test this

template <typename T>
LinkedList<T>::~LinkedList()
{
  (*this).clear();
}

// ------------------------------------------------------------
// ------------------------------------------------------------
// ------------------------------------------------------------

// IMPLEMENT OPERATORS, INCLUDING IOSTREAM PRINTING

#include <iostream>

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

// Value equality
template <typename T>
bool operator==(const ConsCell<T> &cell1, const ConsCell<T> &cell2)
{
  return cell1.car == cell2.car;
}

// Value equality, O(N)
template <typename T>
bool operator==(const LinkedList<T> &l1, const LinkedList<T> &l2)
{
  // If they point to the same place then true, else check by value
  if (l1.head == l2.head)
  {
    return true;
  }

  // We check equality of each cons cell
  // Make sure neither is null
  if (!(l1.head && l2.head))
  {
    return false;
  }

  const ConsCell<T> *cell1 = l1.head;
  const ConsCell<T> *cell2 = l2.head;

  while (true)
  {
    // Traverse the linked list and look at equality of cons cells.
    // Branches annotated with --true? are able to return true values.

    if (!(*cell1 == *cell2))
    { // True => some cons cells contain different data
      return false;
    }
    else if (!(cell1->cdr || cell2->cdr))
    { // Check if both are null.
      // True => final cons cell. Determined by equality of the cons cells.
      return *cell1 == *cell2;
    } // --true?
    else if (!cell1->cdr && !cell2->cdr)
    { // Check if either are null.
      // Lists of different length cannot be equal.
      return false;
    }
    else if (cell1 == l1.head || cell2 == l2.head)
    { // Check if we have a loop
      // True => at least one loop loops.
      // Then the result is true only if
      return cell1 == l1.head && cell2 == l2.head;
    } // --true?

    cell1 = cell1->cdr;
    cell2 = cell2->cdr;
  }
}
// TODO: test
