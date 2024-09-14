//
// Created by andrey on 28.08.24.
//

#ifndef BASICANDROIDAPP_LOCALSERVER_H
#define BASICANDROIDAPP_LOCALSERVER_H

#include <QObject>
#include <QByteArray>

class QLocalServer;
class QLocalSocket;
/**
 * Класс для default общения, хитрее делай сам, это пример!
 */
class LocalServer : public QObject{
Q_OBJECT
public:
    LocalServer(QObject* parent = nullptr);
    void send(QByteArray data);

public slots:
    void onNewConnection();
    void onReadyRead();
    signals:
    void receive(QByteArray data);
private:
    QLocalServer* _server;
    QLocalSocket* _socket{nullptr};
};


#endif //BASICANDROIDAPP_LOCALSERVER_H
