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

QVector<QString> Database_sql::getSupplierDataVector(int index)
{
    QSqlQuery selectQuery("SELECT * FROM Supplier");
    QVector<QString> temp_vector;

    if(selectQuery.seek(index))
    {
        QSqlRecord record = selectQuery.record();
        for (int i = 0; i < record.count(); ++i)
            temp_vector.append(selectQuery.value(i).toString());
    }
    return temp_vector;
}

int Database_sql::getSupplierMaxElement()
{
    QSqlQuery selectQuery("SELECT * FROM Supplier");
    int max_element = 0;

    while(selectQuery.next())
        ++max_element;

    return max_element;
}
