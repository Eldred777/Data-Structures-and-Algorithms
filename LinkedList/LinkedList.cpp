#include <iostream>
#include <memory>

template <typename T>
struct LinkedList
{
  T data;
  // Initialise with null pointer
  LinkedList<T> *next = 0;
};

int playing_around()
{
  // Make head of list
  auto l = new LinkedList<int>();

  // Allocate memory to head of list
  l->data = -1;

  // Add some more cons cells
  l->next = new LinkedList<int>();
  l->next->data = 1;

  // Check output
  std::cout << l->data << " "
            << l->next->data;

  delete l->next, l;
  // TODO: add something to `LinkedList` that takes care of this deletion for me.

  return 0;
}

// ---------------------------------------------------
// Trying to use shared pointers instead

template <typename T>
struct LinkedList_Shared
{
  T data;
  std::shared_ptr<LinkedList_Shared<T>> next;
};

int playing_around_shared()
{
  // Make head of list
  std::unique_ptr<LinkedList_Shared<int>> l(new LinkedList_Shared<int>);

  // Allocate memory to head of list
  l->data = -1;

  std::cout << l->data << std::endl;

  // Add some more cons cells
  l->next = std::make_shared<LinkedList_Shared<int>>();
  l->next->data = 1;

  // Check output
  std::cout << l->data << " "
            << l->next->data;

  return 0;
}

// ----------------------------------------------

int main()
{
  playing_around_shared();

  return 0;
}
