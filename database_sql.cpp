#include "database_sql.h"
#include "thread"
Database_sql::Database_sql(QObject *parent)
    : QObject{parent}
{
    std::thread th([&](){
    qDebug() << "Constructor thread: " << QThread::currentThreadId();
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("ts_company");
    db.setUserName("postgres");
    db.setPassword("12345");
    db.setHostName("127.0.0.1");
    if (!db.open()) {
        qDebug() << "Erro open database!";
    }
    });
    th.join();
}

/////////////////////////////////////////////////////////////////////////SUPPLIER///////////////////////////////////////////////////////////////////////////

void Database_sql::supplier_createNewData()
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("INSERT INTO Supplier (Company, Address, Representative, Phone, Email,Image) VALUES ('', '', '', '', '','')");
    });
    th.join();
}

void Database_sql::supplier_addNewData(QVector<QString> vector)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("UPDATE Supplier SET Company = '" + vector.at(1) +"', Address = '" + vector.at(2)+"', Representative = '" + vector.at(3) +"',Phone = '" + vector.at(4) +"', Email = '" + vector.at(5) +"', Image = '" + vector.at(6) +"' WHERE Id_Supplier = '" + vector.at(0) +"'");
    });
    th.join();
}

//////////////////////////////////////////////////////////////////////////SOCIAL////////////////////////////////////////////////////////////////////////////

QVector<QString> Database_sql::getDataVector(int index, QString name)
{
    QVector<QString> temp_vector;
    std::thread th([&](){
        //qDebug() << "getDataVector thread: " << QThread::currentThreadId();
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM "+ name +" ORDER BY id_supplier ASC");

    if(selectQuery.seek(index))
    {
        QSqlRecord record = selectQuery.record();
        for (int i = 0; i < record.count(); ++i)
            temp_vector.append(selectQuery.value(i).toString());
    }
    });
    th.join();
    return temp_vector;
}

int Database_sql::getMaxElement(QString name)
{
    int max_element = 0;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM "+name+"");

    while(selectQuery.next())
        ++max_element;
    });
    th.join();
    return max_element;
}

void Database_sql::delete_Data(int index,QString nameData,QString id_name)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("DELETE FROM "+nameData+" WHERE "+id_name+"' = "+QString::number(index)+"");
    });
    th.join();
}


