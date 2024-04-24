#ifndef TRANSPORT_COMPANY_H
#define TRANSPORT_COMPANY_H

#include <QObject>

class Transport_company: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> Supplier_vector READ getSupplier_vector WRITE setSupplier_vector NOTIFY Supplier_vectorChanged FINAL)
    Q_PROPERTY(QVector<QString> Cars_vector READ getCars_vector WRITE setCars_vector NOTIFY Cars_vectorChanged FINAL)
public:
    Transport_company();
    QVector<QString> getSupplier_vector() const;
    QVector<QString> getCars_vector() const;

signals:
    void Supplier_vectorChanged();
    void Cars_vectorChanged();

public slots:
    int getSupplierIndex(int num);
    int getSupplierMaxIndex();
    int getCarsIndex(int num);
    int getCarsMaxIndex();

    void setSupplierIndex(int num);
    void setSupplierMaxIndex(int element);
    void setCarsIndex(int num);
    void setCarsMaxIndex(int element);

    void clearVector();

    void setCars_vector(const QVector<QString> &newCars_vector);
    void setSupplier_vector(const QVector<QString> newSupplier_vector);

    //QString getSupplier_wordVector(int index);
private:
    QVector<QString> m_Supplier_vector;
    int supplier_index = 0;
    int supplier_maxIndex;

    QVector<QString> m_Cars_vector;
    int cars_index = 0;
    int cars_maxIndex;
};

#endif // TRANSPORT_COMPANY_H
