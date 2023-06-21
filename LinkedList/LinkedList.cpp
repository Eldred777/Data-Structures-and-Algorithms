#include <iostream>
#include <memory>

template <typename T>
struct LinkedList
{
  T data;
  // Initialise with null pointer
  LinkedList<T> *next = 0;
};

// Nodes for a linked list. Note we use LISP convention for naming the parts of
// the cons cell.
template <typename T>
struct ConsCell
{
  T car;
  // Initialise with null pointer
  ConsCell<T> *cdr = 0;

};

int playing_around()
{
  // Make head of list
  auto l = new ConsCell<int>();

  // Allocate memory to head of list
  l->car = -1;

  // Add some more cons cells
  l->cdr = new ConsCell<int>();
  l->cdr->car = 1;

  // Check output
  std::cout << l->car << " "
            << l->cdr->car;

  delete l->cdr, l;
  // TODO: add something to `ConsCell` that takes care of this deletion for me.

  return 0;
}

int main()
{
  playing_around();

  return 0;
}
