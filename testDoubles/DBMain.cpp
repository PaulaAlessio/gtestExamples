#include "DBclass.h"

int main()
{
  DBConnection dbConnection;
  DBclass dbOperations(dbConnection);
  dbOperations.Init("name", "password");
  dbOperations.Close("name");

  return 0;
}
