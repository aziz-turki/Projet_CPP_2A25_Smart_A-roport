#include "connexion.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-db");
db.setUserName("aziz");//inserer nom de l'utilisateur
db.setPassword("aziz");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


    return  test;
}
