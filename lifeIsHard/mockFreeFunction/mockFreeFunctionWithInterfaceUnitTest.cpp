#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <functional>
#include "CaesarDecipheringWithInterface.h"


struct ResourcesMock: IResources
{
  MOCK_METHOD1(r_alloc, void*(size_t));
  MOCK_METHOD1(r_free, void(void*));
};

namespace testing
{
  struct DecoderTestsFixture : Test
  {
    ResourcesMock rs;
    CaesarDeciphering caesarDecipher;
    DecoderTestsFixture(): caesarDecipher(rs) {}
    using ValueWithError = std::pair< int, std::string>;
  };

  TEST_F(DecoderTestsFixture, failed_reserve_resources)
  {
    EXPECT_CALL(rs, r_alloc(_)).WillRepeatedly(Return(nullptr));
    ASSERT_THAT(caesarDecipher.decipher("we wont be able to allocate",2), Eq(ValueWithError(-1, "")));
  }

  TEST_F(DecoderTestsFixture, invalid_message)
  {
    char msg[] = "wrong message 123";
    char out[sizeof(msg)];
    EXPECT_CALL(rs, r_alloc(sizeof(msg))).WillRepeatedly(Return(out));
    ASSERT_THAT(caesarDecipher.decipher("wrong message 123",2), Eq(ValueWithError(-1, "")));
  }


  TEST_F(DecoderTestsFixture, valid_message)
  {
    char msg[] = "gnkz";
    char out[sizeof(msg)];
    EXPECT_CALL(rs, r_alloc(sizeof(msg))).WillRepeatedly(Return(out));
    EXPECT_CALL(rs, r_free(out));
    ASSERT_THAT(caesarDecipher.decipher("gnkz",1), Eq(ValueWithError(0, "hola")));
  }

}

int main(int argc, char **argv)
{
    // Initialization of mocking framework
    ::testing::InitGoogleMock(&argc, argv);
    // Initialization of testing framework
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

