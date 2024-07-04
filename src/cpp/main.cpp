#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#ifdef ANDROID
#include <QtCore/private/qandroidextras_p.h>
#endif

int startService(int argc, char *argv[]) {
    qDebug() << "Service starting with from the same .so file";
    QAndroidService app(argc, argv);
    return app.exec();
}
int startGui(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
#ifdef ANDROID
    QTimer::singleShot(800,nullptr,[=](){
        QNativeInterface::QAndroidApplication::hideSplashScreen(400);
        });
#endif

    QQmlApplicationEngine engine;
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
        // code to handle main activity execution
        return startGui(argc, argv);
    } else if (argc > 1 && strcmp(argv[1], "-service") == 0) {
        return startService(argc, argv);
    } else {
        qWarning() << "Unrecognized command line argument";
        return -1;
    }
}


