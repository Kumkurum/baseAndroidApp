#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <QQmlContext>
#include "Activity/ActivityCore.h"
#include "Service/ServiceCore.h"
#include <QtCore/private/qandroidextras_p.h>

int startService(int argc, char *argv[]) {
    QAndroidService app(argc, argv);
    ServiceCore serviceCore;
    return app.exec();
}

int startGui(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    QTimer::singleShot(800,nullptr,[=](){
        QNativeInterface::QAndroidApplication::hideSplashScreen(400);
        });
    ActivityCore activityCore;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("core", &activityCore);
    const QUrl url("qrc:/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}

int main(int argc, char *argv[]){
    if (argc <= 1) {
        return startGui(argc, argv);
    } else if (argc > 1 && strcmp(argv[1], "-service") == 0) {
        return startService(argc, argv);
    } else {
        qWarning() <<"BaseAndroidApp"<< "Unrecognized command line argument";
        return -1;
    }
}


