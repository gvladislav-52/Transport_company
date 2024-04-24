#ifndef TRANSPORT_COMPANY_H
#define TRANSPORT_COMPANY_H

#include <QObject>

class Transport_company: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> Supplier_vector READ getSupplier_vector WRITE setSupplier_vector NOTIFY Supplier_vectorChanged FINAL)
    Q_PROPERTY(QVector<QString> Cars_vector READ getCars_vector WRITE setCars_vector NOTIFY Cars_vectorChanged FINAL)
    Q_PROPERTY(QVector<QString> Clients_vector READ getClients_vector WRITE setClients_vector NOTIFY Clients_vectorChanged FINAL)
public:
    Transport_company();
    QVector<QString> getSupplier_vector() const;
    QVector<QString> getCars_vector() const;
    QVector<QString> getClients_vector() const;

signals:
    void Supplier_vectorChanged();
    void Cars_vectorChanged();

    void Clients_vectorChanged();

public slots:
    int getSupplierIndex(int num);
    int getSupplierMaxIndex();
    int getCarsIndex(int num);
    int getCarsMaxIndex();
    int getClientsIndex(int num);
    int getClientsMaxIndex();

    void setSupplierIndex(int num);
    void setSupplierMaxIndex(int element);
    void setCarsIndex(int num);
    void setCarsMaxIndex(int element);
    void setClientsIndex(int num);
    void setClientsMaxIndex(int element);

    void cars_clearVector();
    void supplier_clearVector();
    void clients_clearVector();

    void setCars_vector(const QVector<QString> &newCars_vector);
    void setSupplier_vector(const QVector<QString> newSupplier_vector);
    void setClients_vector(const QVector<QString> &newClients_vector);

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
};

#endif // TRANSPORT_COMPANY_H
