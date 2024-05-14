#ifndef CARS_H
#define CARS_H

#include <QObject>

class Cars: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> Cars_vector READ getCars_vector WRITE setCars_vector NOTIFY Cars_vectorChanged FINAL)
public:
    Cars();
    QVector<QString> getCars_vector() const;
signals:
    void Cars_vectorChanged();
public slots:
    int getCarsIndex(int num);
    int getCarsMaxIndex();
    void setCarsIndex(int num);
    void setCarsMaxIndex(int element);
    void cars_clearVector();
    void setCars_vector(const QVector<QString> &newCars_vector);
private:
    QVector<QString> m_Cars_vector;
    int cars_index = 0;
    int cars_maxIndex;
};

#endif // CARS_H
