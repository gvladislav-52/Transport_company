#ifndef TRANSPORT_COMPANY_H
#define TRANSPORT_COMPANY_H

#include <QObject>

class Transport_company: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> Supplier_vector READ getSupplier_vector WRITE setSupplier_vector NOTIFY Supplier_vectorChanged FINAL)
    Q_PROPERTY(QVector<QString> Cars_vector READ getCars_vector WRITE setCars_vector NOTIFY Cars_vectorChanged FINAL)
    Q_PROPERTY(QVector<QString> Clients_vector READ getClients_vector WRITE setClients_vector NOTIFY Clients_vectorChanged FINAL)
    Q_PROPERTY(QVector<QString> Drivers_vector READ getDrivers_vector WRITE setDrivers_vector NOTIFY Drivers_vectorChanged FINAL)
    Q_PROPERTY(QVector<QString> Order_vector READ getOrder_vector WRITE setOrder_vector NOTIFY Order_vectorChanged FINAL)
    Q_PROPERTY(QVector<QString> Invoice_vector READ getInvoice_vector WRITE setInvoice_vector NOTIFY Invoice_vectorChanged FINAL)
public:
    Transport_company();
    QVector<QString> getSupplier_vector() const;
    QVector<QString> getCars_vector() const;
    QVector<QString> getClients_vector() const;
    QVector<QString> getDrivers_vector() const;


    QVector<QString> getInvoice_vector() const;


    QVector<QString> getOrder_vector() const;

signals:
    void Supplier_vectorChanged();
    void Cars_vectorChanged();

    void Clients_vectorChanged();

    void Drivers_vectorChanged();

    void Invoice_vectorChanged();

    void Order_vectorChanged();

public slots:
    int getSupplierIndex(int num);
    int getSupplierMaxIndex();
    int getCarsIndex(int num);
    int getCarsMaxIndex();
    int getClientsIndex(int num);
    int getClientsMaxIndex();
    int getDriversIndex(int num);
    int getDriversMaxIndex();

    int getOrderIndex(int num);
    int getOrderMaxIndex();
    int getInvoiceIndex(int num);
    // int getInvoiceMaxIndex();
    // int getInvoiceIndexTable();


    void setSupplierIndex(int num);
    void setSupplierMaxIndex(int element);
    void setCarsIndex(int num);
    void setCarsMaxIndex(int element);
    void setClientsIndex(int num);
    void setClientsMaxIndex(int element);
    void setDriversIndex(int num);
    void setDriversMaxIndex(int element);

    void setOrderIndex(int num);
    void setOrderMaxIndex(int element);
    void setInvoiceIndex(int num);
    //void setInvoiceMaxIndex(int element);
    //void setInvoiceIndexTable(int num);

    void cars_clearVector();
    void supplier_clearVector();
    void clients_clearVector();
    void drivers_clearVector();
    void order_clearVector();
    void invoice_clearVector();

    void setCars_vector(const QVector<QString> &newCars_vector);
    void setSupplier_vector(const QVector<QString> newSupplier_vector);
    void setClients_vector(const QVector<QString> &newClients_vector);
    void setDrivers_vector(const QVector<QString> &newDrivers_vector);
    void setOrder_vector(const QVector<QString> &newOrder_vector);
    void setInvoice_vector(const QVector<QString> &newInvoice_vector);

private:
    QVector<QString> m_Supplier_vector;
    int supplier_index;
    int supplier_maxIndex;

    QVector<QString> m_Cars_vector;
    int cars_index = 0;
    int cars_maxIndex;

    QVector<QString> m_Clients_vector;
    int clients_index = 0;
    int clients_maxIndex;

    QVector<QString> m_Drivers_vector;
    int drivers_index = 0;
    int drivers_maxIndex;


    QVector<QString> m_Invoice_vector;
    int invoice_index = 0;
    //int invoice_maxIndex;
    //int invoice_indexTable = 0;

    QVector<QString> m_Order_vector;
    int order_index = 0;
    int order_maxIndex;
};

#endif // TRANSPORT_COMPANY_H
