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

///////////////////////////////////////////////////////////////////////////CARS/////////////////////////////////////////////////////////////////////////////

void Database_sql::cars_createNewData(QVector<QString> vec)
{
    //qDebug() << vec;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("INSERT INTO Cars (Id_supplier, Brand, Model, Engine_volume, Power_motor, Body, Color, Status, Price, Release_data, VIN, Image) VALUES (4, '"+ vec[1] +"', '"+ vec[2] +"', "+ vec[3] +", "+ vec[4] +", '"+ vec[5] +"', '"+ vec[6] +"', '"+ vec[7] +"', "+ vec[8] +", '"+ vec[9] +"', '"+ vec[10] +"','"+ vec[11] +"');");
    });
    th.join();
}

void Database_sql::cars_addNewData(QVector<QString> vector)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("UPDATE Cars SET Id_supplier = '" + vector.at(1) +"', Brand = '" + vector.at(2)+"', Model = '" + vector.at(3) +"',Engine_volume = '" + vector.at(4) +"', Power_motor = '" + vector.at(5) +"', Body = '" + vector.at(6) +"', Color = '" + vector.at(7) +"', Status = '"+vector.at(8)+"', Price = '"+vector.at(9)+"', Release_data = '"+vector.at(10)+"', VIN = '"+vector.at(11)+"', Image = '"+vector.at(12)+"' WHERE Id_Supplier = '" + vector.at(0) +"'");
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
        for (int i = 1; i < record.count(); ++i)
            temp_vector.append(selectQuery.value(i).toString());
    }
    });
    th.join();
    return temp_vector;
}

QVector<QString> Database_sql::getAllSupplierName()
{
    QVector<QString> temp_vector;
    std::thread th([&](){
        //qDebug() << "getDataVector thread: " << QThread::currentThreadId();
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Supplier ORDER BY id_supplier ASC");

        while (selectQuery.next()) {
            // Получаем первое значение (индекс 0) из текущей строки
            temp_vector.append(selectQuery.value(1).toString());
        }
    });
    th.join();
    qDebug() << temp_vector;
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

void Database_sql::delete_Data(int index,QString nameData, QString id_name)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("DELETE FROM "+nameData+" WHERE "+ id_name +" = "+QString::number(index)+"");
    });
    th.join();
}


