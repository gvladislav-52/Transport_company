#include "suppliers.h"

Suppliers::Suppliers() {}

QVector<QString> Suppliers::getSupplier_vector() const
{
    return m_Supplier_vector;
}

void Suppliers::setSupplierMaxIndex(int element)
{
    supplier_maxIndex = element;
}

void Suppliers::supplier_clearVector()
{
    m_Supplier_vector.clear();
    m_Supplier_vector.assign(7, "");
    emit Supplier_vectorChanged();
}

void Suppliers::setSupplier_vector(const QVector<QString> newSupplier_vector)
{
    if (m_Supplier_vector == newSupplier_vector)
        return;
    m_Supplier_vector = newSupplier_vector;
    emit Supplier_vectorChanged();
}

int Suppliers::getSupplierIndex(int num)
{
    return supplier_index += num;
}

int Suppliers::getSupplierMaxIndex()
{
    return supplier_maxIndex;
}

void Suppliers::setSupplierIndex(int num)
{
    supplier_index = num;
}
