#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QtSql>

class database1 : public QObject
{
    Q_OBJECT
public:
    explicit database1();
public slots:
    QVector<QString> supplier_selectAll(int index);
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
