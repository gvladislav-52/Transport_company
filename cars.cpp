#include "cars.h"

Cars::Cars() {}

void Cars::setCarsIndex(int num)
{
    cars_index = num;
}

void Cars::setCarsMaxIndex(int element)
{
    cars_maxIndex = element;
}

void Cars::cars_clearVector()
{
    m_Cars_vector.clear();
    m_Cars_vector.assign(11,"");
    emit Cars_vectorChanged();
}

int Cars::getCarsIndex(int num)
{
    return cars_index +=num;
}

int Cars::getCarsMaxIndex()
{
    return cars_maxIndex;
}

QVector<QString> Cars::getCars_vector() const
{
    return m_Cars_vector;
}

void Cars::setCars_vector(const QVector<QString> &newCars_vector)
{
    if (m_Cars_vector == newCars_vector)
        return;
    m_Cars_vector = newCars_vector;
    emit Cars_vectorChanged();
}
