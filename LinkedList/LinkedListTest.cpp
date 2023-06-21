#include "LinkedList.hpp"
#include <iostream>

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
