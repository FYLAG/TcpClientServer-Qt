#include "messenger.h"

#include <QDebug>

Messenger::Messenger() : messageSize(0) {

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

                if (this->socket->bytesAvailable() < (int) sizeof(quint32)) {

                    break;

                } else {

                    in >> this->messageSize;

                }

            }

            if (this->socket->bytesAvailable() < this->messageSize) {

                break;

            } else {

                qDebug() << messageSize;

                in >> this->strMessage;
                this->messageSize = 0;

                qDebug() << strMessage;

                emit signalAddMessage();

                break;

            }

        }

    } else {

        // strMessage = "Error message read...";
        // emit signalAddMessage();

    }

}

void Messenger::sendToServer(QString str) {

    this->messageByte.clear();

    QDataStream out(&this->messageByte, QDataStream::WriteOnly);
    out.setVersion(QDataStream::Version::Qt_6_6);

    out << quint32(0) << str;

    out.device()->seek(0);
    out << quint32(this->messageByte.size() - sizeof(quint32));

    this->socket->write(this->messageByte);

}