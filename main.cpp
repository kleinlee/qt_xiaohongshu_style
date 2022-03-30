#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "colorimageprovider.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url("qrc:/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.addImageProvider("colors", new ColorImageProvider);
    engine.load(url);

    return app.exec();
}
