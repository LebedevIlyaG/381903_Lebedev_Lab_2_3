#include <iostream>
#include "Queue.h"
#include "Steck.h"

int main()
{
  TSteck<int> a(3);
  a.Push(10);

  std::cout<< a << "\nHi\n";
  return 0;
}
