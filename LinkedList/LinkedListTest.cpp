#include "LinkedList.hpp"
#include <iostream>

bool basic_construction_and_equality_of_ConsCell();
bool basic_construction_and_equality_of_LinkedList();

int main()
{
  std::cout << basic_construction_and_equality_of_ConsCell()
            << " basic_construction_and_equality_of_ConsCell()\n";

  return 0;
}

bool basic_construction_and_equality_of_ConsCell()
{
  typedef ConsCell<int> cons;
  bool test_raw_comparison;
  bool test_equality_operator;

  cons *c1 = new cons(1);
  cons *c2 = new cons(1, c1);

  test_raw_comparison = c1->car == c2->car;
  test_equality_operator = *c1 == *c2;

  delete c1;
  delete c2;

  return test_raw_comparison && test_equality_operator;
}

bool basic_construction_and_equality_of_LinkedList() {
  return 1; 
}
