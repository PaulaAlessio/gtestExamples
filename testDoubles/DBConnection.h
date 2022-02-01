#pragma once

#include <string>

class DBConnection
{
public:
  virtual bool login(const std::string& username, const std::string& password)
  {
    // Some fancy implementation of a database login goes here
    return true;
  }  
  virtual bool logout(const std::string& username)
  {
    // Some fancy implementation of a database logout goes here
    return true;
  }
};
