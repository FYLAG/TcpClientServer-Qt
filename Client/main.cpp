#include <QApplication>

#include "form.h"
#include "presenter.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    Form *view = new Form();
    Presenter presenter = Presenter(view);

    view->show();

    return a.exec();

}
