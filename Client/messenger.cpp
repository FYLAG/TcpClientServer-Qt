#include "messenger.h"

#include <QDebug>

Messenger::Messenger() {

    this->socket = new QTcpSocket(this);

    connect(socket, &QTcpSocket::readyRead, this, &Messenger::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    this->serverConnect();

}

QString Messenger::getMessage() {
    return this->strMessage;
}

void Messenger::serverConnect() {
    this->socket->connectToHost("127.0.0.1", 1080);
}

void Messenger::slotReadyRead() {

    QDataStream in(this->socket);
    in.setVersion(QDataStream::Version::Qt_6_6);

    this->strMessage.clear();

    if (in.status() == QDataStream::Ok) {

        while(true) {

            if (this->messageSize == 0) {

                if (this->socket->bytesAvailable() < sizeof(quint32)) {

                    break;

                } else {

                    in >> this->messageSize;

                }

            } else if (this->socket->bytesAvailable() < this->messageSize) {

                break;

            } else {

                in >> this->strMessage;
                this->messageSize = 0;

                emit signalAddMessage();

            }

        }

    } else {

        // strMessage = "Error message read...";
        // emit signalAddMessage();

    }

}

void Messenger::sendToServer(QString str) {

    this->messageData.clear();

    QDataStream out(&this->messageData, QDataStream::WriteOnly);
    out.setVersion(QDataStream::Version::Qt_6_6);

    out << quint32(0) << str;

    out.device()->seek(0);
    out << quint32(this->messageData.size()) - sizeof(quint32);

    this->socket->write(this->messageData);

}