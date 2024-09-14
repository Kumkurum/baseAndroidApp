//
// Created by andrey on 28.08.24.
//

#ifndef BASICANDROIDAPP_JAVARECEIVERNOQT_H
#define BASICANDROIDAPP_JAVARECEIVERNOQT_H

/**
 * Класс для связи с жабой
 */
class JavaReceiverNoQt {
public:
    JavaReceiverNoQt(void* handler);
    ~JavaReceiverNoQt();
    void sendMessage(int sec);
    static bool _state;
    static JavaReceiverNoQt* _instance;
    void* _handler;
};
#endif //BASICANDROIDAPP_JAVARECEIVERNOQT_H
