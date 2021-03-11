#include "connection.h"

Connection::Connection()
{


}

bool Connection::OuvrirConnection()
{

    bool test=false;

db=QSqlDatabase ::addDatabase("QODBC");
db.setDatabaseName("smart_restaurant");
db.setUserName("ashref");
db.setPassword("0123456789");

if(db.open())
return true;

return test;

}

void Connection::FermerConnection()
{
    db.close();
}
