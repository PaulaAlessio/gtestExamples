#include <map>
#include <gtest/gtest.h>
#include "../DBclass.h"

class DBconnectionFake : public DBConnection {
    std::map<std::string, std::string, std::less<>> validCredentials = {{"user1", "password1"},
                                                           {"user2", "password2"}};

public:
    bool login(const std::string &username, const std::string &password) final
    {
      for (const auto &credentials: validCredentials) {
        if (username == credentials.first &&  password == credentials.second)
          return true;
      }
      return false;
    }

    bool logout(const std::string &username) final
    {
      for (const auto &credentials: validCredentials)
      {
        if (username == credentials.first) return true;
      }
      return false;
    }

    virtual ~DBconnectionFake() = default;
};


namespace testing
{
  TEST(DBclassFake, loginSuccess)
  {
    // Given
    DBconnectionFake dbConn;
    DBclass db(dbConn);

    // When
    auto ret = db.Init("user2", "password2");

    // Then
    ASSERT_EQ(ret, true);
  }

  TEST(DBclassFake, loginFailedPasswordWrong)
  {
    // Given
    DBconnectionFake dbConn;
    DBclass db(dbConn);

    // When
    auto ret = db.Init("user1", "IForgotThePassword");

    // Then
    ASSERT_EQ(ret, false);
  }

  TEST(DBclassFake, loginFailedUserWrong)
  {
    // Given
    DBconnectionFake dbConn;
    DBclass db(dbConn);

    // When
    auto ret = db.Init("IdontKnowMyName", "password2");

    // Then
    ASSERT_EQ(ret, false);
  }

  TEST(DBclassFake, loginFailedUserWrongPasswordWrong)
  {
    // Given
    DBconnectionFake dbConn;
    DBclass db(dbConn);

    // When
    auto ret = db.Init("IdontKnowMyName", "IForgotMyPassword");

    // Then
    ASSERT_EQ(ret, false);
  }

}
