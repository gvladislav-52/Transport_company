#include "database.h"

database1::database1()
{
    // db = QSqlDatabase::addDatabase("QPSQL");
    // db.setDatabaseName("ts_company");
    // db.setUserName("postgres");
    // db.setPassword("12345");
    // db.setHostName("127.0.0.1");
    // if (!db.open())
    //     qDebug() << "Error open data base PosgreSQL";
}

QVector<QString> database1::supplier_selectAll(int index)
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
