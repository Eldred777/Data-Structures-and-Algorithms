#include "LinkedList.hpp"

// Returns the length of the list
// TODO: test
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
