#pragma once

#include <iostream>
#include "DBConnection.h"

class DBclass
{
protected:
   DBConnection &dbConn;
public:
   explicit DBclass(DBConnection &_dbConn): dbConn(_dbConn) {}

   bool Init(const std::string &username, const std::string &password)
   {
     if (dbConn.login(username, password))
     {
       std::cout << "SUCCESS DB INIT " << std::endl;
       return true;
     }
     else
     {
       std::cout << "FAILURE AT DB INIT" << std::endl;
       return false;
     }
   }

   bool Close(const std::string &username)
   {
     if (dbConn.logout(username))
     {
       std::cout << "SUCCESS DB CLOSE" << std::endl;
       return true;
     }
     else
     {
       std::cout << "FAILURE AT DB CLOSE" << std::endl;
       return false;
     }
   }

};