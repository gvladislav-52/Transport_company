#ifndef TRANSPORT_COMPANY_H
#define TRANSPORT_COMPANY_H

#include <QObject>

class Transport_company: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> Supplier_vector READ getSupplier_vector WRITE setSupplier_vector NOTIFY Supplier_vectorChanged FINAL)
public:
    Transport_company();
    QVector<QString> getSupplier_vector() const;
    void setSupplierMaxIndex(int && element);
signals:
    void Supplier_vectorChanged();
public slots:
    int getSupplierIndex(int num);
    int getSupplierMaxIndex();
    void setSupplier_vector(const QVector<QString> &newSupplier_vector);
private:
    QVector<QString> m_Supplier_vector;
    int supplier_index = 0;
    int supplier_maxIndex;
};

#endif // TRANSPORT_COMPANY_H
