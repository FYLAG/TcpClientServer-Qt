#include "server.h"

#include <QDebug>

Server::Server() {

    if (this->listen(QHostAddress::Any, 1080)) {
        qDebug() << "Server working.";
    } else {
        qDebug() << "Server don't work.";
    }

}

void Server::incomingConnection(qintptr socketDescriptor) {

    this->socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    this->sockets.push_back(socket);

    qDebug() << "Client connected - " << socketDescriptor;

}

void Server::slotReadyRead() {

    this->socket = reinterpret_cast<QTcpSocket*>(sender());

    QDataStream in(socket);
    in.setVersion(QDataStream::Version::Qt_6_6);

    if (in.status() == QDataStream::Ok) {

        qDebug() << "Status: OK, Message: read...";

        QString strMessage;

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

                in >> strMessage;
                this->messageSize = 0;

                sendToClient(strMessage);

            }

        }

    } else {

        qDebug() << "Status: ERROR.";

    }

}

void Server::sendToClient(QString str) {

    this->messageByte.clear();

    QDataStream out(&this->messageByte, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Version::Qt_6_6);

    out << quint32(0) << str;

    out.device()->seek(0);
    out << quint32(this->messageByte.size()) - sizeof(quint32);

    for (auto iter : this->sockets) {
        iter->write(this->messageByte);
        qDebug() << "Send.";
    }

}
