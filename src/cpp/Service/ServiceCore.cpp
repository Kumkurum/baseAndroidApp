//
// Created by andrey on 25.06.24.
//

#include "ServiceCore.h"
#include <QDebug>
#include <QTimer>
#include "LocalServer.h"
ServiceCore::ServiceCore(QObject* parent):QObject{parent}
        , _server{new LocalServer{this}}
{
    qWarning()<<"BaseAndroidApp"<<"MAKE ServiceCore";
    //! Бесполезная начинка, просто пример
    QTimer* timer= new QTimer{this};
    connect(timer, &QTimer::timeout,[this](){
        static int sec{0};
        qDebug()<<"BaseAndroidApp"<<"SERVER"<<sec;
        sec++;
    });
    timer->start(1000);
    //!
    connect(_server, &LocalServer::receive, [](QByteArray data){
        qDebug()<<"BaseAndroidApp"<<"RECEIVE"<<data;
    });
};

ServiceCore::~ServiceCore(){
    qWarning()<<"BaseAndroidApp"<<"DEL ServiceCore";
}