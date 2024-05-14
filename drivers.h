#ifndef DRIVERS_H
#define DRIVERS_H

#include <QObject>

class Drivers: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> Drivers_vector READ getDrivers_vector WRITE setDrivers_vector NOTIFY Drivers_vectorChanged FINAL)
public:
    Drivers();
    QVector<QString> getDrivers_vector() const;
signals:
    void Drivers_vectorChanged();
public slots:
    int getDriversIndex(int num);
    int getDriversMaxIndex();
    void setDriversIndex(int num);
    void setDriversMaxIndex(int element);
    void drivers_clearVector();
    void setDrivers_vector(const QVector<QString> &newDrivers_vector);
private:
    QVector<QString> m_Drivers_vector;
    int drivers_index = 0;
    int drivers_maxIndex;
};

#endif // DRIVERS_H
