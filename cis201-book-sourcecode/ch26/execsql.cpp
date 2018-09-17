#include <iostream>

#include <string>
#include <mysql.h>

using namespace std;

void execute_command(MYSQL* connection, string command)
{
   if (mysql_query(connection, command.c_str()) != 0)
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return;
   }

   MYSQL_RES* result = mysql_store_result(connection);
   if (result == NULL) return; 

   int rows = mysql_num_rows(result);
   int fields = mysql_num_fields(result);
   for (int r = 1; r <= rows; r++)
   {
      MYSQL_ROW row = mysql_fetch_row(result);
      for (int f = 0; f < fields; f++)
      {
         string field(row[f]);
         if (f > 0) cout << ",";
         cout << field;
      }
      cout << "\n";
   }

   mysql_free_result(result);
}

int main()
{
   MYSQL* connection = mysql_init(NULL);

   if (mysql_real_connect(connection, NULL, NULL, NULL, 
         "bigcpp", 0, NULL, 0) == NULL)
   {
      cout << "Error: " << mysql_error(connection) << "\n";
      return 1;
   }

   string line;
   bool more = true;
   while (getline(cin, line))
   {
      execute_command(connection, line);
   }

   mysql_close(connection);
   return 0;
}
