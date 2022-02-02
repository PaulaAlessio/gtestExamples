#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <functional>
#include "CaesarDeciphering.h"

static std::function<void*(size_t)> __allocate;
static std::function<void(void*)> __free;

struct ResourcesMock
{
  ResourcesMock()
  {
    assert(!__allocate && !__free);
    __allocate = [this](size_t s){ return this->r_alloc(s); };
    __free = [this](void* p){ this->r_free(p); };
  }

  ~ResourcesMock()
  {
    __allocate = {};
    __free = {};
  }

  MOCK_CONST_METHOD1(r_alloc, void*(size_t));
  MOCK_CONST_METHOD1(r_free, void(void*));

};

void* r_alloc(size_t size)
{
  return __allocate(size);
}

void r_free(void* resource)
{
  __free(resource);
}

namespace testing
{
  struct DecoderTestsFixture : Test
  {
    ResourcesMock rs;
    using ValueWithError = std::pair< int, std::string>;
  };

  TEST_F(DecoderTestsFixture, failed_reserve_resources)
  {
    EXPECT_CALL(rs, r_alloc(_)).WillRepeatedly(Return(nullptr));
    ASSERT_THAT(caesarDecipher("we wont be able to allocate",2), Eq(ValueWithError(-1, "")));
  }

  TEST_F(DecoderTestsFixture, invalid_message)
  {
    char msg[] = "wrong message 123";
    char out[sizeof(msg)];
    EXPECT_CALL(rs, r_alloc(sizeof(msg))).WillRepeatedly(Return(out));
    ASSERT_THAT(caesarDecipher("wrong message 123",2), Eq(ValueWithError(-1, "")));
  }


  TEST_F(DecoderTestsFixture, valid_message)
  {
    char msg[] = "gnkz";
    char out[sizeof(msg)];
    EXPECT_CALL(rs, r_alloc(sizeof(msg))).WillRepeatedly(Return(out));
    EXPECT_CALL(rs, r_free(out));
    ASSERT_THAT(caesarDecipher("gnkz",1), Eq(ValueWithError(0, "hola")));
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

