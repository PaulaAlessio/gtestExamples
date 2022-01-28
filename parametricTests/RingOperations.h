#pragma once

template <typename type1>
class RingOperations
{

public:
  static type1 addition(const type1& op1, const type1& op2)
  {
    return op1 + op2;
  }

  static type1 product(const type1& op1, const type1& op2)
  {
    return op1 * op2;
  }

};
