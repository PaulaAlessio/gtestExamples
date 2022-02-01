#include <iostream>
#include "RingOperations.h"

template<typename type1>
void stupidgame()
{
  type1 op1, op2;
  std::cout << "Introduzca dos objetos de tipo: " << typeid(type1).name() << std::endl;
  std::cin >>  op1 >> op2;
  std::cout << "Suma:      " << RingOperations<type1>::addition(op1, op2) << std::endl;
  std::cout << "Producto:  " << RingOperations<type1>::product(op1, op2) << std::endl;
}

int main()
{
  stupidgame<int>();
  stupidgame<float>();
  return 0;
}


