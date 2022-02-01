#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char **argv)
{
  // Initialization of mocking framework                                                                                                                    
  ::testing::InitGoogleMock(&argc, argv);
  // Initialization of testing framework                                                                                                                    
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
