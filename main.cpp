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

    //File_processing fileProcessing;
   // qDebug() << "ID Main-thread:\t" << QThread::currentThreadId();
    Transport_company ts_company;
    Database_sql db;
    qDebug() << "Main thread: " << QThread::currentThreadId();
    ts_company.setSupplier_vector(db.getDataVector(0,"Supplier"));
    ts_company.setSupplierMaxIndex(db.getMaxElement("Supplier"));

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Main.qml"));

    QQmlContext *rootContext = engine.rootContext();
    rootContext->setContextProperty("Transport_company", &ts_company);
    rootContext->setContextProperty("Database", &db);
    //rootContext->setContextProperty("Database", &db);
    engine.load(url);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    return app.exec();
}
