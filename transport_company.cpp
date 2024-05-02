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

void Transport_company::setDriversIndex(int num)
{
    drivers_index = num;
}

void Transport_company::setDriversMaxIndex(int element)
{
    drivers_maxIndex = element;
}

void Transport_company::setOrderIndex(int num)
{
    order_index = num;
}

void Transport_company::setOrderMaxIndex(int element)
{
    order_index = element;
}

void Transport_company::setInvoiceIndex(int num)
{
    invoice_index = num;
}

void Transport_company::setInvoiceMaxIndex(int element)
{
    invoice_maxIndex = element;
}

void Transport_company::setInvoiceIndexTable(int num)
{
    invoice_indexTable += num;
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

void Transport_company::drivers_clearVector()
{
    m_Drivers_vector.clear();
    m_Drivers_vector.assign(9,"");
    emit Drivers_vectorChanged();
}

void Transport_company::order_clearVector()
{
    m_Order_vector.clear();
    m_Order_vector.assign(7,"");
    emit Order_vectorChanged();
}

void Transport_company::invoice_clearVector()
{
    m_Invoice_vector.clear();
    m_Invoice_vector.assign(7,"");
    emit Invoice_vectorChanged();
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

int Transport_company::getDriversIndex(int num)
{
    return drivers_index+=num;
}

int Transport_company::getDriversMaxIndex()
{
    return drivers_maxIndex;
}

int Transport_company::getOrderIndex(int num)
{
    return order_index+=num;
}

int Transport_company::getOrderMaxIndex()
{
    return order_maxIndex;
}

int Transport_company::getInvoiceIndex(int num)
{
    return invoice_index+=num;
}

int Transport_company::getInvoiceMaxIndex()
{
    return invoice_maxIndex;
}

int Transport_company::getInvoiceIndexTable()
{
    return invoice_indexTable;
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

QVector<QString> Transport_company::getDrivers_vector() const
{
    return m_Drivers_vector;
}

void Transport_company::setDrivers_vector(const QVector<QString> &newDrivers_vector)
{
    if (m_Drivers_vector == newDrivers_vector)
        return;
    m_Drivers_vector = newDrivers_vector;
    emit Drivers_vectorChanged();
}

QVector<QString> Transport_company::getInvoice_vector() const
{
    return m_Invoice_vector;
}

void Transport_company::setInvoice_vector(const QVector<QString> &newInvoice_vector)
{
    if (m_Invoice_vector == newInvoice_vector)
        return;
    m_Invoice_vector = newInvoice_vector;
    emit Invoice_vectorChanged();
}

QVector<QString> Transport_company::getOrder_vector() const
{
    return m_Order_vector;
}

void Transport_company::setOrder_vector(const QVector<QString> &newOrder_vector)
{
    if (m_Order_vector == newOrder_vector)
        return;
    m_Order_vector = newOrder_vector;
    emit Order_vectorChanged();
}
