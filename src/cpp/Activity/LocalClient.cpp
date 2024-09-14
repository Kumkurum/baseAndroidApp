//
// Created by andrey on 28.08.24.
//

#include "LocalClient.h"
#include <QLocalSocket>
#include <QByteArray>
#include <QDebug>
#include <QTimer>
LocalClient::LocalClient(QObject* parent):QObject{parent}
        , _socket{new QLocalSocket{this}}
{
    connect(_socket, &QLocalSocket::readyRead, this, &LocalClient::onReadyRead);
    connect(_socket, &QLocalSocket::connected,[](){
        qWarning() <<"BaseAndroidApp"<<"LocalClient Connected!";
    });
    _socket->connectToServer("baseAndroidApp");
    QTimer* timer = new QTimer{this};
    connect(timer, &QTimer::timeout,[this, timer](){
        if(_socket->state() == QLocalSocket::UnconnectedState){
            qDebug()<<"BaseAndroidApp"<<"in";
            _socket->connectToServer("baseAndroidApp");
        }else{
            timer->stop();
        }
    });
    timer->start(1000);//потому что хз когда там загрузится сервис
}

void LocalClient::send(QByteArray data){
    _socket->write(std::move(data));
    _socket->flush();
}
void LocalClient::onReadyRead(){
    emit receive(_socket->readAll());
}