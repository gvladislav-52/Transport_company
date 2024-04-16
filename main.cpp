#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QApplication>
//#include "file_processing.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //File_processing fileProcessing;
   // qDebug() << "ID Main-thread:\t" << QThread::currentThreadId();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/Main.qml"));

    QQmlContext *rootContext = engine.rootContext();
    //ootContext->setContextProperty("file_proc", &fileProcessing);
    engine.load(url);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    return app.exec();
}
