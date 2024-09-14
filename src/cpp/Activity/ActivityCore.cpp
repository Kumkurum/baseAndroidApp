//
// Created by andrey on 24.06.24.
//

#include "ActivityCore.h"
#include "JavaReceiver.h"
#include "LocalClient.h"
#include <QDebug>
#include <QTimer>
ActivityCore::ActivityCore(QObject* parent):QObject{parent}
        ,_client{new LocalClient{this}}
    , _javaReceiver{new JavaReceiver{this}}
{
    qWarning()<<"BaseAndroidApp"<<"MAKE ActivityCore";
    _javaReceiver->sendMessage(10);
    //! Бесполезная начинка, просто пример
    QTimer* timer= new QTimer{this};
    connect(timer, &QTimer::timeout,[this](){
        static int sec{0};
        qDebug()<<"BaseAndroidApp"<<"ACTIVITY"<<sec;
        sec++;
    });
    timer->start(1000);
    //!
}

ActivityCore::~ActivityCore(){
    qWarning()<<"BaseAndroidApp"<<"DEL ActivityCore";
}

void ActivityCore::send(){
    qDebug()<<"BaseAndroidApp"<<"SEND"<<123;
    _client->send(QByteArray::number(123));
}