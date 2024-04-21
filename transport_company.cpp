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

QString Transport_company::getSupplier_wordVector(int index)
{
    return m_Supplier_vector.at(index);
}
void Transport_company::setSupplier_vector(const QVector<QString> newSupplier_vector)
{
    if (m_Supplier_vector == newSupplier_vector)
        return;
    m_Supplier_vector = newSupplier_vector;
    emit Supplier_vectorChanged();
}

// void Transport_company::setSupplier_vector(QString str, int index)
// {
//     m_Supplier_vector[index] = str;
//     qDebug() << m_Supplier_vector;
//     emit Supplier_vectorChanged();
// }

int Transport_company::getSupplierIndex(int num)
{
    return supplier_index +=num;

}

int Transport_company::getSupplierMaxIndex()
{
    qDebug() << supplier_maxIndex-1;
    return supplier_maxIndex;
}

void Transport_company::setSupplierIndex(int num)
{
    supplier_index = num;
}
