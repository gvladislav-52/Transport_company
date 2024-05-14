#include "drivers.h"

Drivers::Drivers() {}

void Drivers::setDriversIndex(int num)
{
    drivers_index = num;
}

void Drivers::setDriversMaxIndex(int element)
{
    drivers_maxIndex = element;
}

void Drivers::drivers_clearVector()
{
    m_Drivers_vector.clear();
    m_Drivers_vector.assign(9,"");
    emit Drivers_vectorChanged();
}

int Drivers::getDriversIndex(int num)
{
    return drivers_index+=num;
}

int Drivers::getDriversMaxIndex()
{
    return drivers_maxIndex;
}

QVector<QString> Drivers::getDrivers_vector() const
{
    return m_Drivers_vector;
}

void Drivers::setDrivers_vector(const QVector<QString> &newDrivers_vector)
{
    if (m_Drivers_vector == newDrivers_vector)
        return;
    m_Drivers_vector = newDrivers_vector;
    emit Drivers_vectorChanged();
}
