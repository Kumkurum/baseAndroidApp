//
// Created by andrey on 28.08.24.
//

#include "LocalServer.h"

#include <QLocalServer>
#include <QLocalSocket>

LocalServer::LocalServer(QObject* parent): QObject(parent)
        ,_server{new QLocalServer{this}}
{
    connect(_server, &QLocalServer::newConnection, this, &LocalServer::onNewConnection);
    QLocalServer::removeServer("baseAndroidApp");
    if(!_server->listen("baseAndroidApp")) {
        qWarning() << "ERROR!"<<Q_FUNC_INFO << _server->errorString();
        _server->close();
    }
}

void LocalServer::send(QByteArray data) {
    if(!_socket)
        return;
    _socket->write(std::move(data));
    _socket->flush();
}
void LocalServer::onNewConnection() {
    qWarning() <<"BaseAndroidApp"<<"LocalServer Connected!";
    if(_socket) {
        _socket->close();
        _socket->deleteLater();
    }
    _socket = _server->nextPendingConnection();
    connect(_socket, &QLocalSocket::disconnected, [=]() {
        _socket->deleteLater();
        _socket = nullptr;
    });
    connect(_socket, &QLocalSocket::readyRead, this, &LocalServer::onReadyRead);
}

void LocalServer::onReadyRead() {
    emit receive(std::move(_socket->readAll()));
}