#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{//bool test=false;
 db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("Manar");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
return true ;



 return  false;
}
void Connection::closeconnection(){db.close();}
