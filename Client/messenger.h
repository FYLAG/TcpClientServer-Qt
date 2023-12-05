#ifndef MESSENGER_H
#define MESSENGER_H

#include <QTcpSocket>
#include <QTcpServer>

#include <QString>
#include <QObject>

class Messenger : public QObject {
    Q_OBJECT

public:
    explicit Messenger(QString login);

    QString getUserLogin();

    QString getMessage();

    void serverConnect();

    void updateMessenger();

    void sendToServer(QString str);

private:

    QString userLogin;

    QString strMessage;
    QTcpSocket *socket;
    QByteArray messageByte;

private slots:
    void slotReadyRead();

signals:
    void signalAddMessage();

};

#endif // MESSENGER_H
