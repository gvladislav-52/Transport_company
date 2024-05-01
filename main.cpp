#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QApplication>
#include "transport_company.h"
#include "database_sql.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Transport_company ts_company;
    Database_sql db;
    qDebug() << "Main thread: " << QThread::currentThreadId();
    ts_company.setSupplier_vector(db.getDataVector(0,"Supplier","Id_supplier"));
    ts_company.setSupplierMaxIndex(db.getMaxElement("Supplier"));
    ts_company.setSupplierIndex(0);

    ts_company.setCars_vector(db.getDataVector(0,"Cars","Id_car"));
    ts_company.setCarsMaxIndex(db.getMaxElement("Cars"));
    ts_company.setCarsIndex(0);

    ts_company.setClients_vector(db.getDataVector(0,"Clients","Id_client"));
    ts_company.setClientsMaxIndex(db.getMaxElement("Clients"));
    ts_company.setClientsIndex(0);

    ts_company.setDrivers_vector(db.getDataVector(0,"Drivers","id"));
    ts_company.setDriversMaxIndex(db.getMaxElement("Drivers"));
    ts_company.setDriversIndex(0);


    ts_company.setInvoice_vector(db.getInvoiceDataVector("Invoice","id_order","4"));
    qDebug() << ts_company.getInvoice_vector();
    ts_company.setInvoiceMaxIndex(db.getMaxElement("Invoice"));
    ts_company.setInvoiceIndex(0);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Main.qml"));

    QQmlContext *rootContext = engine.rootContext();
    rootContext->setContextProperty("Transport_company", &ts_company);
    rootContext->setContextProperty("Database", &db);

    engine.load(url);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    return app.exec();
}
