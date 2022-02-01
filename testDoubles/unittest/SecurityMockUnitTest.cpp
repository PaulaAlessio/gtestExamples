#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <memory>
#include "../Security.h"

class MockWindow: public Window
{
public:
  MOCK_METHOD0(open,void());
  MOCK_METHOD0(close,void());
  virtual ~MockWindow() = default;
};

class MockDoor: public Door
{
public:
    MOCK_METHOD0(open,void());
    MOCK_METHOD0(close,void());
    virtual ~MockDoor() = default;
};

namespace testing
{
  TEST(Security, SecurityOnWindowOpenIsCalledDoorOpenIsCalled)
  {
    // Given
    auto window = std::make_unique<MockWindow>();
    auto door   = std::make_unique<MockDoor>();

    // Then
    EXPECT_CALL(*window,close).Times(Exactly(1));
    EXPECT_CALL(*door,close).Times(Exactly(1));

    // When
    Security security(std::move(window), std::move(door));
    security.on();
  }

  TEST(Security, SecurityOffWindowCloseIsCalledDoorCloseIsCalled)
  {
    // Given
    auto window = std::make_unique<MockWindow>();
    auto door   = std::make_unique<MockDoor>();

    // Then
    EXPECT_CALL(*window,open).Times(Exactly(1));
    EXPECT_CALL(*door,open).Times(Exactly(1));

    // When
    Security security(std::move(window), std::move(door));
    security.off();
  }
}




