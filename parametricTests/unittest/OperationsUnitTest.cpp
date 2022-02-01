#include <gtest/gtest.h>
#include "../RingOperations.h"

namespace testing
{
  using testing::Types;

  // Define a test fixture class template.  Here we just reuse
  template <typename T>
  class OperationsTest : public testing::Test  {
  protected:
     std::unique_ptr<RingOperations<T>> ringOperations =  std::unique_ptr<RingOperations<T>>(new RingOperations<T>());
  };

  // Declare the test case.  (argument: test fixture name)
  TYPED_TEST_CASE_P(OperationsTest);

  // Use TYPED_TEST_P(TestCaseName, TestName) to define a test,
  // similar to what you do with TEST_F.
  TYPED_TEST_P(OperationsTest, TestAddition)
  {
      ASSERT_EQ(this->ringOperations->addition(2,3),5);
  }

  TYPED_TEST_P(OperationsTest, TestProduct)
  {
      ASSERT_EQ(this->ringOperations->product(2,3),6);
  }

  // Type-parameterized tests involve one extra step: you have to
  // enumerate the tests you defined:
  REGISTER_TYPED_TEST_CASE_P(
            OperationsTest,  // The first argument is the test case name.
            // The rest of the arguments are the test names.
            TestAddition, TestProduct);

  // Now we have to instantiate the tests for the types you want to test
  using myTypes =  Types<int, unsigned int, float, double>;
  INSTANTIATE_TYPED_TEST_CASE_P(OnTheFlyAndPreCalculated,    // Instance name
                                OperationsTest,             // Test case name
                                myTypes);  // Type list
}




