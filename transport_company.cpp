#include "transport_company.h"
#include "qdebug.h"

Transport_company::Transport_company(){}

void Transport_company::setOrderIndex(int num)
{
    order_index = num;
}

void Transport_company::setOrderMaxIndex(int element)
{
    order_maxIndex = element;
}

void Transport_company::setInvoiceIndex(int num)
{
    invoice_index = num;
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
