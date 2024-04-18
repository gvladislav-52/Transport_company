#include "transport_company.h"

Transport_company::Transport_company() {}

QVector<QString> Transport_company::getSupplier_vector() const
{
    return m_Supplier_vector;
}

void Transport_company::setSupplierMaxIndex(int &&element)
{
    supplier_maxIndex = element;
}

void Transport_company::setSupplier_vector(const QVector<QString> &newSupplier_vector)
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
