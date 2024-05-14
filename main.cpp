#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QApplication>
#include "transport_company.h"
#include "database_sql.h"
#include <QThread>

#include "suppliers.h"
#include "cars.h"
#include "clients.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Transport_company ts_company;
    Suppliers supplier;
    Cars car;
    Clients client;

    Database_sql db;
    qDebug() << "Main thread: " << QThread::currentThreadId();
    supplier.setSupplier_vector(db.getDataVector(0,"Supplier","Id_supplier"));
    supplier.setSupplierMaxIndex(db.getMaxElement("Supplier"));
    supplier.setSupplierIndex(0);

    car.setCars_vector(db.getDataVector(0,"Cars","Id_car"));
    car.setCarsMaxIndex(db.getMaxElement("Cars"));
    car.setCarsIndex(0);

    client.setClients_vector(db.getDataVector(0,"Clients","Id_client"));
    client.setClientsMaxIndex(db.getMaxElement("Clients"));
    client.setClientsIndex(0);

    ts_company.setDrivers_vector(db.getDataVector(0,"Drivers","id"));
    ts_company.setDriversMaxIndex(db.getMaxElement("Drivers"));
    ts_company.setDriversIndex(0);

    ts_company.setOrder_vector(db.getDataVector(0,"Orders","id_order"));
    ts_company.setOrderMaxIndex(db.getMaxElement("Orders"));
    ts_company.setOrderIndex(0);


    ts_company.setInvoice_vector(db.getInvoiceDataVector("Invoice","id_order",4));
    qDebug() << ts_company.getInvoice_vector();
    //ts_company.setInvoiceMaxIndex(db.getMaxElement("Invoice"));
    //ts_company.setInvoiceIndex(0);

    //qDebug() << db.getMaxElement("Invoice");
    //qDebug() << db.getIndexOrder(4,true);
    //qDebug() << db.getIndexOrder(6,false);
    ts_company.setInvoiceIndex(db.getIndexOrder(0,true));
    //ts_company.setInvoiceMaxIndex(db.getMaxIndexInvoice());
    //ts_company.setInvoiceIndexTable(0);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Main.qml"));

    QQmlContext *rootContext = engine.rootContext();
    rootContext->setContextProperty("Transport_company", &ts_company);
    rootContext->setContextProperty("Supplier_com", &supplier);
    rootContext->setContextProperty("Car_com", &car);
    rootContext->setContextProperty("Client_com", &client);
    rootContext->setContextProperty("Database", &db);


    engine.load(url);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    return app.exec();
}
