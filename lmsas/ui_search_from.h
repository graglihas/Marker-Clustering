/********************************************************************************
** Form generated from reading UI file 'search_from.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_FROM_H
#define UI_SEARCH_FROM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Searches_form
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *comboBox;

    void setupUi(QWidget *Searches_form)
    {
        if (Searches_form->objectName().isEmpty())
            Searches_form->setObjectName(QStringLiteral("Searches_form"));
        Searches_form->resize(420, 1200);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Searches_form->sizePolicy().hasHeightForWidth());
        Searches_form->setSizePolicy(sizePolicy);
        Searches_form->setMinimumSize(QSize(420, 0));
        groupBox = new QGroupBox(Searches_form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 251, 61));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 30, 66, 21));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(50, 30, 200, 29));

        retranslateUi(Searches_form);

        QMetaObject::connectSlotsByName(Searches_form);
    } // setupUi

    void retranslateUi(QWidget *Searches_form)
    {
        Searches_form->setWindowTitle(QApplication::translate("Searches_form", "Form", 0));
        groupBox->setTitle(QApplication::translate("Searches_form", "Select Search", 0));
        label->setText(QApplication::translate("Searches_form", "Type", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Searches_form", "Expanding Square Search", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class Searches_form: public Ui_Searches_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_FROM_H
