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

//////////////////////////////////////////////////////////////////////////CLIENTS////////////////////////////////////////////////////////////////////////////

void Database_sql::clients_createNewData(QVector<QString> vec)
{
    //qDebug() << vec;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("INSERT INTO Clients (Company, Person, Phone, EMail) VALUES ('"+vec[1]+"', '"+ vec[2] +"', '"+ vec[3] +"', '"+ vec[4] +"');");
    });
    th.join();
}

void Database_sql::clients_addNewData(QVector<QString> vector)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("UPDATE Clients SET Company = '" + vector.at(1) +"', Person = '" + vector.at(2)+"', Phone = '" + vector.at(3) +"',EMail = '" + vector.at(4) +"' WHERE Id_client = '" + vector.at(0) +"'");
    });
    th.join();
}

///////////////////////////////////////////////////////////////////////////CARS/////////////////////////////////////////////////////////////////////////////

void Database_sql::cars_createNewData(QVector<QString> vec)
{
    //qDebug() << vec;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("INSERT INTO Cars (Id_supplier, Brand, Model, Engine_volume, Power_motor, Body, Color, Status, Price, Image) VALUES ("+vec[1]+", '"+ vec[2] +"', '"+ vec[3] +"', "+ vec[4] +", "+ vec[5] +", '"+ vec[6] +"', '"+ vec[7] +"', '"+ vec[8] +"', "+ vec[9] +", '"+ vec[10]+"');");
    });
    th.join();
}

void Database_sql::cars_addNewData(QVector<QString> vector)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("UPDATE Cars SET Id_supplier = '" + vector.at(1) +"', Brand = '" + vector.at(2)+"', Model = '" + vector.at(3) +"',Engine_volume = '" + vector.at(4) +"', Power_motor = '" + vector.at(5) +"', Body = '" + vector.at(6) +"', Color = '" + vector.at(7) +"', Status = '"+vector.at(8)+"', Price = '"+vector.at(9)+"', Image = '"+vector.at(10)+"' WHERE Id_car = '" + vector.at(0) +"'");
    });
    th.join();
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
    return temp_vector;
}

QString Database_sql::getSupplierId(QString company)
{
    QString temp_vector;
    std::thread th([&](){
        //qDebug() << "getDataVector thread: " << QThread::currentThreadId();
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Supplier WHERE Company = '"+company+"' ORDER BY id_supplier ASC");

        while (selectQuery.next())
            temp_vector = selectQuery.value(0).toString();

    });
    th.join();
    return temp_vector;
}

int Database_sql::getIndexSupplier(QVector<QString> vecName, QString vecData)
{
    int index;
    QString str;

    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Supplier WHERE id_supplier = '"+vecData+"' ORDER BY id_supplier ASC");

        while (selectQuery.next())
            str = selectQuery.value(1).toString();

        for(int i = 0; i <vecName.size(); i++)
            if(vecName[i] == str)
            {
                index = i;
                break;
            }
    });
    th.join();
    return index;
}

/////////////////////////////////////////////////////////////////////////SUPPLIER///////////////////////////////////////////////////////////////////////////

void Database_sql::supplier_createNewData(QVector<QString> vector)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("INSERT INTO Supplier (Company, Address, Representative, Phone, Email,Image) VALUES ('"+vector[1]+"', '"+vector[2]+"', '"+vector[3]+"', '"+vector[4]+"', '"+vector[5]+"','"+vector[6]+"')");
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

QVector<QString> Database_sql::getDataVector(int index, QString name, QString sort)
{
    QVector<QString> temp_vector;
    std::thread th([&](){
        //qDebug() << "getDataVector thread: " << QThread::currentThreadId();
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM "+ name +" ORDER BY "+sort+" ASC");

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

void Database_sql::delete_Data(int index,QString nameData, QString id_name)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("DELETE FROM "+nameData+" WHERE "+ id_name +" = "+QString::number(index)+"");
    });
    th.join();
}


