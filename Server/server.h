#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>

#include <QVector>
#include <QString>

class Server : public QTcpServer {

public:
    Server();
    ~Server();

    QTcpSocket *socket;

private:
    QVector<QTcpSocket*> sockets;

    void sendToClient(QString str);

private slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
    void slotSocketDelete();

};

#endif // SERVER_H
