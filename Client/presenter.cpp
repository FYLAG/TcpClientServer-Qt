#include "presenter.h"

Presenter::Presenter(IView *view, QObject *parent)
        : QObject(parent), view(view), model(new Messenger("New User")) {

    view->setUserLogin(model->getUserLogin());

    QObject *viewObject = dynamic_cast<QObject*>(this->view);

    connect(viewObject, SIGNAL(signalSendMessage()), this, SLOT(sendMessage()));
    connect(model, SIGNAL(signalAddMessage()), this, SLOT(receiveMessage()));

}

void Presenter::sendMessage() {
    model->sendToServer(view->getMessage());
}

void Presenter::receiveMessage() {
    view->addMessage(model->getMessage());
}
