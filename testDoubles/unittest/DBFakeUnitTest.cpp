#include <map>
#include <gtest/gtest.h>
#include "../DBclass.h"

class DBconnectionFake : public DBConnection {
    const std::map<std::string, std::string, std::less<>> validCredentials = {{"user1", "password1"},
                                                           {"user2", "password2"}};

public:
    bool login(const std::string &username, const std::string &password) final
    {
       return std::any_of(validCredentials.begin(), validCredentials.end(),
                          [&username, &password](const std::pair<std::string, std::string> &p)
                          { return (p.first == username && p.second == password);
        });
    }

    bool logout(const std::string &username) final
    {
      return std::any_of(validCredentials.begin(), validCredentials.end(),
                         [&username](const std::pair<std::string, std::string> &p)
                         { return (p.first == username);
                         });
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
