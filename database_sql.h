#ifndef DATABASE_SQL_H
#define DATABASE_SQL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QtSql>

class Database_sql : public QObject
{
    Q_OBJECT
public:
    explicit Database_sql(QObject *parent = nullptr);
public slots:
    QVector<QString> getDataVector(int index,QString name);
    QVector<QString> getAllSupplierName();
    int getMaxElement(QString name);
    void delete_Data(int index, QString nameData, QString id_name);

    void supplier_createNewData();
    void supplier_addNewData(QVector<QString> vector);

    void cars_createNewData(QVector<QString> vec);
    void cars_addNewData(QVector<QString> vector);
private:
    QSqlDatabase db;
signals:
};

#endif // DATABASE_SQL_H
