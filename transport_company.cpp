#include "transport_company.h"
#include "qdebug.h"

Transport_company::Transport_company() {}

QVector<QString> Transport_company::getSupplier_vector() const
{
    return m_Supplier_vector;
}

void Transport_company::setSupplierMaxIndex(int element)
{
    supplier_maxIndex = element;
}

void Transport_company::setCarsIndex(int num)
{
    cars_index = num;
}

void Transport_company::setCarsMaxIndex(int element)
{
    cars_maxIndex = element;
}

void Transport_company::clearVector()
{
    m_Cars_vector.clear();
    m_Cars_vector.assign(12,"");
    emit Cars_vectorChanged();
}

// QString Transport_company::getSupplier_wordVector(int index)
// {
//     return m_Supplier_vector.at(index);
// }
void Transport_company::setSupplier_vector(const QVector<QString> newSupplier_vector)
{
    if (m_Supplier_vector == newSupplier_vector)
        return;
    m_Supplier_vector = newSupplier_vector;
    emit Supplier_vectorChanged();
}

int Transport_company::getSupplierIndex(int num)
{
    return supplier_index +=num;

}

int Transport_company::getSupplierMaxIndex()
{
    return supplier_maxIndex;
}

int Transport_company::getCarsIndex(int num)
{
    return cars_index +=num;
}

int Transport_company::getCarsMaxIndex()
{
    return cars_maxIndex;
}

void Transport_company::setSupplierIndex(int num)
{
    supplier_index = num;
}

QVector<QString> Transport_company::getCars_vector() const
{
    return m_Cars_vector;
}

void Transport_company::setCars_vector(const QVector<QString> &newCars_vector)
{
    if (m_Cars_vector == newCars_vector)
        return;
    m_Cars_vector = newCars_vector;
    emit Cars_vectorChanged();
}
