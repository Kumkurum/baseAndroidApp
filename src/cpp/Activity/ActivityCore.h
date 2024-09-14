//
// Created by andrey on 24.06.24.
//

#ifndef BASICANDROIDAPP_CORE_H
#define BASICANDROIDAPP_CORE_H
#include <QObject>
class LocalClient;
class JavaReceiver;
class ActivityCore: public QObject {
    Q_OBJECT
public:
    ActivityCore(QObject* parent = nullptr);
    ~ActivityCore();
    Q_INVOKABLE void send();
private:
    LocalClient* _client;
    JavaReceiver* _javaReceiver ;
};


#endif //BASICANDROIDAPP_CORE_H
