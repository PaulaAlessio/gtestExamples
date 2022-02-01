#include <gtest/gtest.h>
#include "../RingOperations.h"

namespace testing
{

  struct IntParams
  {
    int op1;
    int op2;
    int result;
    IntParams(int _op1, int _op2, int _res):op1(_op1),op2(_op2),result(_res) {}
  };

  class AdditionOperationFixture: public TestWithParam<IntParams> { };
  class ProductOperationFixture: public TestWithParam<IntParams> { };

  // Inside the tests, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:
  TEST_P(AdditionOperationFixture, AdditionOpChecks)
  {
    // Given
    auto params = GetParam();

    // When
    int res = RingOperations<int>::addition(params.op1, params.op2);

    // Then
    ASSERT_EQ(res, params.result);
  }

  TEST_P(ProductOperationFixture, ProductOpChecks)
  {
    // Given
    auto params = GetParam();

    // When
    int res = RingOperations<int>::product(params.op1, params.op2);

    // Then
    ASSERT_EQ(res, params.result);
  }

  INSTANTIATE_TEST_CASE_P(Addition,
            AdditionOperationFixture,
            ::testing::Values(IntParams(0,1,1),
                              IntParams(1,0,1),
                              IntParams(0,0,0),
                              IntParams(-1,1,0)));

  INSTANTIATE_TEST_CASE_P(Product,
            ProductOperationFixture,
            ::testing::Values(IntParams(0,1,0),
                              IntParams(1,0,0),
                              IntParams(0,0,0),
                              IntParams(-1,1,-1)));

}