/********************************************************************************
** Form generated from reading UI file 'dbconnectionform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBCONNECTIONFORM_H
#define UI_DBCONNECTIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBConnectionForm
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit_server;
    QLabel *label_2;
    QLineEdit *lineEdit_port;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;

    void setupUi(QWidget *DBConnectionForm)
    {
        if (DBConnectionForm->objectName().isEmpty())
            DBConnectionForm->setObjectName(QStringLiteral("DBConnectionForm"));
        DBConnectionForm->resize(355, 670);
        gridLayout = new QGridLayout(DBConnectionForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(DBConnectionForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(17, 25, 60, 21));
        lineEdit_server = new QLineEdit(groupBox);
        lineEdit_server->setObjectName(QStringLiteral("lineEdit_server"));
        lineEdit_server->setGeometry(QRect(108, 25, 211, 33));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(17, 64, 66, 21));
        lineEdit_port = new QLineEdit(groupBox);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));
        lineEdit_port->setGeometry(QRect(108, 64, 211, 33));
        pushButton_connect = new QPushButton(groupBox);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(17, 103, 141, 31));
        pushButton_disconnect = new QPushButton(groupBox);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));
        pushButton_disconnect->setGeometry(QRect(170, 100, 151, 31));

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(DBConnectionForm);

        QMetaObject::connectSlotsByName(DBConnectionForm);
    } // setupUi

    void retranslateUi(QWidget *DBConnectionForm)
    {
        DBConnectionForm->setWindowTitle(QApplication::translate("DBConnectionForm", "Form", 0));
        groupBox->setTitle(QApplication::translate("DBConnectionForm", "DB Connect", 0));
        label->setText(QApplication::translate("DBConnectionForm", "Server ip", 0));
        lineEdit_server->setText(QApplication::translate("DBConnectionForm", "127.0.0.1", 0));
        label_2->setText(QApplication::translate("DBConnectionForm", "Password", 0));
        lineEdit_port->setText(QApplication::translate("DBConnectionForm", "5432", 0));
        pushButton_connect->setText(QApplication::translate("DBConnectionForm", "Connect", 0));
        pushButton_disconnect->setText(QApplication::translate("DBConnectionForm", "Disconnect", 0));
    } // retranslateUi

};

namespace Ui {
    class DBConnectionForm: public Ui_DBConnectionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBCONNECTIONFORM_H
