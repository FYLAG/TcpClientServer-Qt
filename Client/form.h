#ifndef FORM_H
#define FORM_H

#include <QMainWindow>

#include <QTcpSocket>
#include <QTcpServer>

#include "iview.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Form;
}
QT_END_NAMESPACE

class Form : public QMainWindow, public IView {

    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);
    ~Form();
    /*! Method for add text message to chat */
    void addMessage(QString str) override;
    /*! Method for getting user text message */
    QString getMessage() override;

private:
    Ui::Form *ui;

private slots:
    void on_pushButton_sendMessage_clicked();

    void on_lineEdit_returnPressed();

signals:
    /*! Signal to call a specific slot */
    void signalSendMessage() override;

};

#endif // FORM_H
