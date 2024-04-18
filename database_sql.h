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
private:
    QSqlDatabase db;
signals:
};

#endif // DATABASE_SQL_H
