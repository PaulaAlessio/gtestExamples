#include <gtest/gtest.h>
#include "../DBclass.h"

class DBConnectiondummy: public DBConnection
{
 public:
    explicit DBConnectiondummy(bool _loginRet = false, bool _logoutRet = false):
             loginRet(_loginRet), logoutRet(_logoutRet) {}
    bool login(const std::string &username, const std::string &password) final {return loginRet;}
    bool logout(const std::string &username) final {return logoutRet;}
    virtual ~DBConnectiondummy() = default;
 private:
    bool loginRet = false;
    bool logoutRet = false;
};

namespace testing
{
  TEST(DBclassDummy, InitIsSuccess)
  {
    // Given
    auto dbConn = DBConnectiondummy(true);
    auto db = DBclass(dbConn);

    // When
    bool ret = db.Init("user", "pwd");

    // Then
    ASSERT_EQ(ret,true);
  }

  TEST(DBclassDummy, InitIsFailure)
  {
    // Given
    auto dbConn = DBConnectiondummy(false);
    auto db = DBclass(dbConn);

    // When
    bool ret = db.Init("user", "pwd");

    // Then
    ASSERT_EQ(ret,false);
  }

}
