/********************************************************************************
** Form generated from reading UI file 'clustertracks.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLUSTERTRACKS_H
#define UI_CLUSTERTRACKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClusterTracks
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;

    void setupUi(QWidget *ClusterTracks)
    {
        if (ClusterTracks->objectName().isEmpty())
            ClusterTracks->setObjectName(QStringLiteral("ClusterTracks"));
        ClusterTracks->resize(400, 575);
        groupBox = new QGroupBox(ClusterTracks);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 361, 531));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 100, 81, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 60, 71, 21));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 60, 191, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 140, 59, 14));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 140, 191, 22));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 190, 81, 22));

        retranslateUi(ClusterTracks);

        QMetaObject::connectSlotsByName(ClusterTracks);
    } // setupUi

    void retranslateUi(QWidget *ClusterTracks)
    {
        ClusterTracks->setWindowTitle(QApplication::translate("ClusterTracks", "Form", 0));
        groupBox->setTitle(QApplication::translate("ClusterTracks", "Cluster Tracks", 0));
        pushButton->setText(QApplication::translate("ClusterTracks", "Load File", 0));
        label->setText(QApplication::translate("ClusterTracks", "File Path", 0));
        label_2->setText(QApplication::translate("ClusterTracks", "Grid Size", 0));
        pushButton_2->setText(QApplication::translate("ClusterTracks", "Cluster", 0));
    } // retranslateUi

};

namespace Ui {
    class ClusterTracks: public Ui_ClusterTracks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLUSTERTRACKS_H
