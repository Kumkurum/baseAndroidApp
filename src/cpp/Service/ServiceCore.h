//
// Created by andrey on 25.06.24.
//

#ifndef BASICANDROIDAPP_SERVICECORE_H
#define BASICANDROIDAPP_SERVICECORE_H
#include <QObject>
class LocalServer;
class ServiceCore: public QObject {
    Q_OBJECT
public:
    ServiceCore(QObject* parent = nullptr);
    ~ServiceCore();
private:
    LocalServer* _server;
};


#endif //BASICANDROIDAPP_SERVICECORE_H
