#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>

#include "iview.h"
#include "messenger.h"

class Presenter : public QObject {
    Q_OBJECT

public:
    explicit Presenter(IView*, QObject *parent = nullptr);

private:
    IView *view;
    Messenger *model;

private slots:
    void sendMessage();
    void receiveMessage();

};

#endif // PRESENTER_H
