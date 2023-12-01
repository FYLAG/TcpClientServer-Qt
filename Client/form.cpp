#include "form.h"
#include "ui_form.h"

#include <QDebug>

Form::Form(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Form) {

    ui->setupUi(this);

}

Form::~Form() {
    delete ui;
}

void Form::addMessage(QString str) {
    this->ui->textBrowser->append(str);
}

QString Form::getMessage() {

    QString str = this->ui->lineEdit->text();
    this->ui->lineEdit->clear();

    return str;
}

void Form::on_pushButton_sendMessage_clicked() {
    emit signalSendMessage();
}


void Form::on_lineEdit_returnPressed() {
    emit signalSendMessage();
}

