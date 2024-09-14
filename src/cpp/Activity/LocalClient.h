//
// Created by andrey on 28.08.24.
//

#ifndef BASICANDROIDAPP_LOCALCLIENT_H
#define BASICANDROIDAPP_LOCALCLIENT_H
#include <QObject>

class QLocalSocket;
/**
 * Класс для default общения, хитрее делай сам, это пример!
 */
class LocalClient: public QObject {
    Q_OBJECT
public:
    LocalClient(QObject* parent);
    void send(QByteArray data);
public slots:
    void onReadyRead();
    signals:
    void receive(QByteArray data);
private:
    QLocalSocket* _socket;
};


#endif //BASICANDROIDAPP_LOCALCLIENT_H
