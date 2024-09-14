//
// Created by andrey on 28.08.24.
//

#ifndef BASICANDROIDAPP_JAVARECEIVER_H
#define BASICANDROIDAPP_JAVARECEIVER_H
#include <QObject>
/**
 * Класс для связи с жабой
 */
class JavaReceiver:public QObject {
    Q_OBJECT
public:
    JavaReceiver(QObject* parent);
    ~JavaReceiver();
    void sendMessage(int sec);
    static bool _state;
    static JavaReceiver* _instance;
signals:
    void stateChanged();
};


#endif //BASICANDROIDAPP_JAVARECEIVER_H
