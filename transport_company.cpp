#include "transport_company.h"
#include "qdebug.h"

Transport_company::Transport_company():supplier_index(0) {}

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

void Transport_company::setClientsIndex(int num)
{
    clients_index = num;
}

void Transport_company::setClientsMaxIndex(int element)
{
    clients_maxIndex = element;
}

void Transport_company::cars_clearVector()
{
    m_Cars_vector.clear();
    m_Cars_vector.assign(11,"");
    emit Cars_vectorChanged();
}

void Transport_company::supplier_clearVector()
{
    m_Supplier_vector.clear();
    m_Supplier_vector.assign(7,"");
    emit Supplier_vectorChanged();
}

void Transport_company::clients_clearVector()
{
    m_Clients_vector.clear();
    m_Clients_vector.assign(5,"");
    emit Clients_vectorChanged();
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

int Transport_company::getClientsIndex(int num)
{
    return clients_index+=num;
}

int Transport_company::getClientsMaxIndex()
{
    return clients_maxIndex;
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

QVector<QString> Transport_company::getClients_vector() const
{
    return m_Clients_vector;
}

void Transport_company::setClients_vector(const QVector<QString> &newClients_vector)
{
    if (m_Clients_vector == newClients_vector)
        return;
    m_Clients_vector = newClients_vector;
    emit Clients_vectorChanged();
}
