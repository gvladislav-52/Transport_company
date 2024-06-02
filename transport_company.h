#ifndef TRANSPORT_COMPANY_H
#define TRANSPORT_COMPANY_H

#include <QObject>

class Transport_company : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> Order_vector READ getOrder_vector WRITE setOrder_vector NOTIFY
                   Order_vectorChanged FINAL)
    Q_PROPERTY(QVector<QString> Invoice_vector READ getInvoice_vector WRITE setInvoice_vector NOTIFY
                   Invoice_vectorChanged FINAL)
public:
    Transport_company();

    QVector<QString> getInvoice_vector() const;

    QVector<QString> getOrder_vector() const;

signals:

    void Invoice_vectorChanged();

    void Order_vectorChanged();

public slots:

    int getOrderIndex(int num);
    int getOrderMaxIndex();
    int getInvoiceIndex(int num);

    void setOrderIndex(int num);
    void setOrderMaxIndex(int element);
    void setInvoiceIndex(int num);

    void order_clearVector();
    void invoice_clearVector();

    void setOrder_vector(const QVector<QString> &newOrder_vector);
    void setInvoice_vector(const QVector<QString> &newInvoice_vector);

private:
    QVector<QString> m_Invoice_vector;
    int invoice_index = 0;

    QVector<QString> m_Order_vector;
    int order_index = 0;
    int order_maxIndex;
};

#endif // TRANSPORT_COMPANY_H
