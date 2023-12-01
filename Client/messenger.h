#ifndef MESSENGER_H
#define MESSENGER_H

#include <QTcpSocket>
#include <QTcpServer>

#include <QString>
#include <QObject>

class Messenger : public QObject {
    Q_OBJECT

public:
    explicit Messenger();

    QString getMessage();

    void serverConnect();

    void updateMessenger();

    void sendToServer(QString str);

private:
    QString strMessage;
    QTcpSocket *socket;
    QByteArray messageData;
    quint32 messageSize;

private slots:
    void slotReadyRead();

signals:
    void signalAddMessage();

};

#endif // MESSENGER_H
