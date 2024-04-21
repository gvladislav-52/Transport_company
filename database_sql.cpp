#include "database_sql.h"

Database_sql::Database_sql(QObject *parent)
    : QObject{parent}
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("ts_company");
    db.setUserName("postgres");
    db.setPassword("12345");
    db.setHostName("127.0.0.1");
    if (!db.open())
        qDebug() << "Error open data base PosgreSQL";
}

/////////////////////////////////////////////////////////////////////////SUPPLIER///////////////////////////////////////////////////////////////////////////

void Database_sql::supplier_createNewData()
{
    QSqlQuery selectQuery("INSERT INTO Supplier (Company, Address, Representative, Phone, Email,Image) VALUES ('', '', '', '', '','')");
}

void Database_sql::supplier_addNewData(QVector<QString> vector)
{
    QSqlQuery selectQuery("UPDATE Supplier SET Company = '" + vector.at(1) +"', Address = '" + vector.at(2)+"', Representative = '" + vector.at(3) +"',Phone = '" + vector.at(4) +"', Email = '" + vector.at(5) +"', Image = '" + vector.at(6) +"' WHERE Id_Supplier = '" + vector.at(0) +"'");
}

//////////////////////////////////////////////////////////////////////////SOCIAL////////////////////////////////////////////////////////////////////////////

QVector<QString> Database_sql::getDataVector(int index, QString name)
{
    QSqlQuery selectQuery("SELECT * FROM "+name+" ORDER BY id_supplier ASC");
    QVector<QString> temp_vector;

    if(selectQuery.seek(index))
    {
        QSqlRecord record = selectQuery.record();
        for (int i = 0; i < record.count(); ++i)
            temp_vector.append(selectQuery.value(i).toString());
    }
    return temp_vector;
}

int Database_sql::getMaxElement(QString name)
{
    QSqlQuery selectQuery("SELECT * FROM "+name+"");
    int max_element = 0;

    while(selectQuery.next())
        ++max_element;

    return max_element;
}

void Database_sql::delete_Data(int index,QString nameData)
{
    QSqlQuery selectQuery("DELETE FROM "+nameData+" WHERE Id_Supplier = "+QString::number(index)+"");
}


