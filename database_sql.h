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
    QVector<QString> getSupplierDataVector(int index);
    int getSupplierMaxElement();
    void supplier_createNewData();
    void supplier_addNewData(QVector<QString> vector);
    void delete_Data(int index, QString nameData);
private:
    QSqlDatabase db;
signals:
};

#endif // DATABASE_SQL_H
