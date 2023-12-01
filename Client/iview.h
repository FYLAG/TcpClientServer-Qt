#ifndef IVIEW_H
#define IVIEW_H

#include <QString>

/*! \interface IView
    MVP view interface.
*/

class IView {

public:
    /*! Method for add text message to chat */
    virtual void addMessage(QString str) = 0;
    /*! Method for getting user text message */
    virtual QString getMessage() = 0;

public: // signals
    /*! Signal to call a specific slot */
    virtual void signalSendMessage() = 0;

};

#endif // IVIEW_H
