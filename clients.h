#ifndef CLIENTS_H
#define CLIENTS_H

#include <QObject>

class Clients : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> Clients_vector READ getClients_vector WRITE setClients_vector NOTIFY
                   Clients_vectorChanged FINAL)
public:
    Clients();
    QVector<QString> getClients_vector() const;
signals:
    void Clients_vectorChanged();
public slots:
    int getClientsIndex(int num);
    int getClientsMaxIndex();
    void setClientsIndex(int num);
    void setClientsMaxIndex(int element);
    void clients_clearVector();
    void setClients_vector(const QVector<QString> &newClients_vector);

private:
    QVector<QString> m_Clients_vector;
    int clients_index = 0;
    int clients_maxIndex;
};

#endif // CLIENTS_H
