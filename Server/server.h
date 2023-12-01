#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>

#include <QVector>
#include <QString>

class Server : public QTcpServer {

public:
    Server();

    QTcpSocket *socket;

private:
    QVector<QTcpSocket*> sockets;
    QByteArray messageByte;
    quint32 messageSize;

    void sendToClient(QString str);

private slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();

};

#endif // SERVER_H
