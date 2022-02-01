#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../DBclass.h"

class DBConnectionStubAndSpy: public DBConnection
{
 public:
    MOCK_METHOD2(login, bool(const std::string&, const std::string&));
    MOCK_METHOD1(logout, bool(const std::string &));
    virtual ~DBConnectionStubAndSpy() = default;
};

namespace testing
{
  TEST(DBClassStub, InitIsSuccessGeneric)
  {
    // Given
    DBConnectionStubAndSpy dbConn;
    DBclass db(dbConn);
    bool expectedOutput = true;

    // Then
    EXPECT_CALL(dbConn, login).Times(Exactly(1)).WillOnce(Return(expectedOutput));

    // When
    bool ret = db.Init("username", "pwd");

    // Then
    ASSERT_EQ(ret,expectedOutput);
  }

    TEST(DBClassStub, InitIsFailureGeneric)
    {
      // Given
      DBConnectionStubAndSpy dbConn;
      DBclass db(dbConn);
      bool expectedOutput = false;

      // Then
      EXPECT_CALL(dbConn, login).Times(Exactly(1)).WillOnce(Return(expectedOutput));

      // When
      bool ret = db.Init("username", "pwd");

      // Then
      ASSERT_EQ(ret,expectedOutput);
    }

  TEST(DBClassSpy, InitIsSuccessArgumentsChecked)
  {
    // Given
    DBConnectionStubAndSpy dbConn;
    DBclass db(dbConn);
    std::string username = "user";
    std::string password = "pwd";
    bool expectedOutput = true;

    // Then
    EXPECT_CALL(dbConn, login(username, password)).Times(Exactly(1)).WillOnce(Return(expectedOutput));

    // When
    bool ret = db.Init(username, password);

    // Then
    ASSERT_EQ(ret,expectedOutput);
  }

  TEST(DBClassStub, InitIsFailureArgumentsChecked)
    {
      // Given
      DBConnectionStubAndSpy dbConn;
      DBclass db(dbConn);
      std::string username = "user";
      std::string password = "pwd";
      bool expectedOutput = false;

      // Then
      EXPECT_CALL(dbConn, login(username, password)).Times(Exactly(1)).WillOnce(Return(expectedOutput));

      // When
      bool ret = db.Init(username, password);

      // Then
      ASSERT_EQ(ret,expectedOutput);
    }

}
