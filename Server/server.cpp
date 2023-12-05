#include "server.h"

#include <QDebug>

Server::Server() {

    if (this->listen(QHostAddress("0.0.0.0"), 1080)) { // QHostAddress::Any
        qDebug() << "Server working.";
    } else {
        qDebug() << "Server don't work.";
    }

}

Server::~Server() {

    this->close();
    qDebug() << "Server stoped.";

}

void Server::incomingConnection(qintptr socketDescriptor) {

    this->socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::slotSocketDelete);

    this->sockets.push_back(socket);

    qDebug() << "Client connected - " << socketDescriptor;

}

void Server::slotSocketDelete() {

    this->socket = reinterpret_cast<QTcpSocket*>(sender());

    this->sockets.removeOne(this->socket);

    qDebug() << "Client disconnected.";

    this->socket->deleteLater();

}

void Server::slotReadyRead() {

    this->socket = reinterpret_cast<QTcpSocket*>(sender());

    QDataStream in(this->socket);
    in.setVersion(QDataStream::Version::Qt_6_6);

    if (in.status() == QDataStream::Ok) {

        qDebug() << "Status: OK, Message: read...";

        QString strUserLogin;
        QString strMessage;

        in.startTransaction();

        in >> strUserLogin >> strMessage ;

        if (in.commitTransaction()) {

            strMessage = strUserLogin + ":\t" + strMessage;
            qDebug() << strMessage;

            sendToClient(strMessage);

        } else {
            return;
        }

    } else {

        qDebug() << "Status: ERROR.";

    }

}

void Server::sendToClient(QString str) {

    QByteArray messageByte;

    QDataStream out(&messageByte, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Version::Qt_6_6);

    out << str;

    for (auto iter : this->sockets) {
        iter->write(messageByte);
    }

}
