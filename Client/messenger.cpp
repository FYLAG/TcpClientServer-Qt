#include "messenger.h"

#include <QDebug>

Messenger::Messenger(QString login) : userLogin(login) {

    this->socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::readyRead, this, &Messenger::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    this->serverConnect();

}

QString Messenger::getUserLogin() {
    return this->userLogin;
}

QString Messenger::getMessage() {
    return this->strMessage;
}

void Messenger::serverConnect() {
    this->socket->connectToHost("185.248.101.68", 1080); // 127.0.0.1
}

void Messenger::slotReadyRead() {

    QDataStream in(this->socket);
    in.setVersion(QDataStream::Version::Qt_6_6);

    this->strMessage.clear();

    if (in.status() == QDataStream::Ok) {

        in.startTransaction();

        in >> this->strMessage;

        if (in.commitTransaction()) {

            qDebug() << strMessage;
            emit signalAddMessage();

        } else {
            return;
        }

    } else {

        qDebug() << "Status: ERROR.";
        // strMessage = "Error message read...";
        // emit signalAddMessage();

    }

}

void Messenger::sendToServer(QString str) {

    this->messageByte.clear();

    QDataStream out(&this->messageByte, QDataStream::WriteOnly);
    out.setVersion(QDataStream::Version::Qt_6_6);

    out << this->userLogin << str;

    this->socket->write(this->messageByte);

}