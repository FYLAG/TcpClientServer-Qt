/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *textBrowser;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_sendMessage;

    void setupUi(QMainWindow *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(800, 600);
        Form->setMinimumSize(QSize(400, 400));
        centralwidget = new QWidget(Form);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 64));
        frame->setMaximumSize(QSize(16777215, 64));
        frame->setStyleSheet(QString::fromUtf8(".QFrame {\n"
"	background: #17212B;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(16, 16, 16, 16);
        label = new QLabel(frame);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(".QLabel {\n"
"	color: white;\n"
"}"));

        horizontalLayout_2->addWidget(label);


        verticalLayout->addWidget(frame);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setStyleSheet(QString::fromUtf8(".QFrame {\n"
"	background: #0E1621;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(frame_2);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setStyleSheet(QString::fromUtf8(".QScrollArea {\n"
"	background: transparent;\n"
"	border: none;\n"
"}\n"
"\n"
".QScrollArea QWidget {\n"
"	background: transparent;\n"
"}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 798, 468));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName("verticalLayout_3");
        textBrowser = new QTextBrowser(scrollAreaWidgetContents);
        textBrowser->setObjectName("textBrowser");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Consolas")});
        font1.setPointSize(10);
        textBrowser->setFont(font1);
        textBrowser->setStyleSheet(QString::fromUtf8(".QTextBrowser {\n"
"	color: white;\n"
"}"));

        verticalLayout_3->addWidget(textBrowser);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setMinimumSize(QSize(0, 64));
        frame_3->setMaximumSize(QSize(16777215, 128));
        frame_3->setStyleSheet(QString::fromUtf8(".QFrame {\n"
"	background: #17212B;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(frame_3);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(0, 64));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Consolas")});
        font2.setPointSize(12);
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QString::fromUtf8(".QLineEdit {\n"
"	background: transparent;\n"
"	padding-left: 16px;\n"
"	border: none;\n"
"	color: white;\n"
"}"));

        horizontalLayout->addWidget(lineEdit);

        pushButton_sendMessage = new QPushButton(frame_3);
        pushButton_sendMessage->setObjectName("pushButton_sendMessage");
        pushButton_sendMessage->setMinimumSize(QSize(64, 64));
        pushButton_sendMessage->setMaximumSize(QSize(64, 16777215));
        pushButton_sendMessage->setFont(font2);
        pushButton_sendMessage->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_sendMessage->setStyleSheet(QString::fromUtf8(".QPushButton {\n"
"	background: transparent;\n"
"	border-radius: 8px;\n"
"	border: none;\n"
"	margin: 8px;\n"
"	color: white;\n"
"}\n"
"\n"
".QPushButton:hover:!pressed {\n"
"	background: #33FFFFFF;\n"
"}\n"
"\n"
".QPushButton:pressed {\n"
"	background: #11FFFFFF;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/paper-plane-solid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_sendMessage->setIcon(icon);
        pushButton_sendMessage->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_sendMessage);


        verticalLayout->addWidget(frame_3);

        Form->setCentralWidget(centralwidget);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QMainWindow *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Messenger", nullptr));
        label->setText(QCoreApplication::translate("Form", "UserLogin", nullptr));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("Form", "Write a message...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
