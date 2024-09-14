//
// Created by andrey on 28.08.24.
//

#include "JavaReceiverNoQt.h"
#include <QtCore/private/qandroidextras_p.h>
#include <QDebug>
#include "ActivityCore.h"
//надо всегда помнить что в надроиде как минимум 2 потока, один на дисплей другой внутренний
static void formJavaToCpp(JNIEnv *env, jobject thiz, jboolean res){
    qDebug()<<"BaseAndroidApp"<<"formJavaToCpp";
    // Запрос приходит из другого потока, поэтому управление делаем на основе флагов
    JavaReceiverNoQt::_state = (bool)res;
//    if(JavaReceiverNoQt::_instance)
//        emit static_cast<ActivityCore*>(JavaReceiverNoQt::_instance->_handler)->stateChanged();
}

JavaReceiverNoQt* JavaReceiverNoQt::_instance = nullptr;//для связи с жабой нужны статики
bool JavaReceiverNoQt::_state = false;//статики для изменения состояния

JavaReceiverNoQt::JavaReceiverNoQt(void* handler):
        _handler{handler}
{
    _instance = this;
    //Регистрация методов для прокидывания в жабу
    const JNINativeMethod methods[] = {{"formJavaToCpp", "(Z)V", reinterpret_cast<void *>(formJavaToCpp)}};//может быть несколько
    QJniEnvironment env;
    env.registerNativeMethods("ru/base_app/app/MainActivity", methods, 1);// java класс с кем связываем функции
}

JavaReceiverNoQt::~JavaReceiverNoQt() = default;

void JavaReceiverNoQt::sendMessage(int sec) {
    //так вот мы можем дёрнуть функцию в java из плюсов
    auto activity = QJniObject(QNativeInterface::QAndroidApplication::context());
    QAndroidIntent serviceIntent(activity.object(), "ru/base_app/app/MainActivity");
    activity.callObjectMethod("fromCppToJava", "(I)V", sec);//(I)V тип функции см на сайте QT по поводу типов параметров, строка оч странно выглядит, если что

}