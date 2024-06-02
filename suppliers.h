#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#include <QObject>

class Suppliers : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> Supplier_vector READ getSupplier_vector WRITE setSupplier_vector
                   NOTIFY Supplier_vectorChanged FINAL)
public:
    Suppliers();
    QVector<QString> getSupplier_vector() const;
signals:
    void Supplier_vectorChanged();
public slots:
    int getSupplierIndex(int num);
    int getSupplierMaxIndex();
    void setSupplierIndex(int num);
    void setSupplierMaxIndex(int element);
    void supplier_clearVector();
    void setSupplier_vector(const QVector<QString> newSupplier_vector);

private:
    QVector<QString> m_Supplier_vector;
    int supplier_index = 0;
    int supplier_maxIndex;
};

#endif // SUPPLIERS_H
