/********************************************************************************
** Form generated from reading UI file 'gisview.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GISVIEW_H
#define UI_GISVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GisView
{
public:

    void setupUi(QWidget *GisView)
    {
        if (GisView->objectName().isEmpty())
            GisView->setObjectName(QStringLiteral("GisView"));
        GisView->resize(400, 300);

        retranslateUi(GisView);

        QMetaObject::connectSlotsByName(GisView);
    } // setupUi

    void retranslateUi(QWidget *GisView)
    {
        GisView->setWindowTitle(QApplication::translate("GisView", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class GisView: public Ui_GisView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GISVIEW_H
