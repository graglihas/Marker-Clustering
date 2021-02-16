/********************************************************************************
** Form generated from reading UI file 'filtertote.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERTOTE_H
#define UI_FILTERTOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_filtertote
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_tracksInRepo;
    QLabel *label_5;
    QLineEdit *lineEdit_tracksInLayer;
    QLabel *label_6;
    QLineEdit *lineEdit_filteredTracksInRepo;
    QLabel *label;
    QComboBox *color_comboBox;
    QLabel *label_2;
    QComboBox *type_comboBox;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *filtertote)
    {
        if (filtertote->objectName().isEmpty())
            filtertote->setObjectName(QStringLiteral("filtertote"));
        filtertote->resize(385, 507);
        horizontalLayout = new QHBoxLayout(filtertote);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(filtertote);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        lineEdit_tracksInRepo = new QLineEdit(groupBox);
        lineEdit_tracksInRepo->setObjectName(QStringLiteral("lineEdit_tracksInRepo"));

        verticalLayout->addWidget(lineEdit_tracksInRepo);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        lineEdit_tracksInLayer = new QLineEdit(groupBox);
        lineEdit_tracksInLayer->setObjectName(QStringLiteral("lineEdit_tracksInLayer"));

        verticalLayout->addWidget(lineEdit_tracksInLayer);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        lineEdit_filteredTracksInRepo = new QLineEdit(groupBox);
        lineEdit_filteredTracksInRepo->setObjectName(QStringLiteral("lineEdit_filteredTracksInRepo"));
        lineEdit_filteredTracksInRepo->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_filteredTracksInRepo);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        color_comboBox = new QComboBox(groupBox);
        color_comboBox->setObjectName(QStringLiteral("color_comboBox"));

        verticalLayout->addWidget(color_comboBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        type_comboBox = new QComboBox(groupBox);
        type_comboBox->setObjectName(QStringLiteral("type_comboBox"));

        verticalLayout->addWidget(type_comboBox);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(filtertote);

        QMetaObject::connectSlotsByName(filtertote);
    } // setupUi

    void retranslateUi(QWidget *filtertote)
    {
        filtertote->setWindowTitle(QApplication::translate("filtertote", "Form", 0));
        groupBox->setTitle(QApplication::translate("filtertote", "Inputs", 0));
        label_4->setText(QApplication::translate("filtertote", "Tracks In Repo", 0));
        label_5->setText(QApplication::translate("filtertote", "Tracks In Layer", 0));
        label_6->setText(QApplication::translate("filtertote", "Filtered Tracks In Repo", 0));
        label->setText(QApplication::translate("filtertote", "Color ", 0));
        color_comboBox->clear();
        color_comboBox->insertItems(0, QStringList()
         << QApplication::translate("filtertote", "All", 0)
         << QApplication::translate("filtertote", "Green", 0)
         << QApplication::translate("filtertote", "Red", 0)
         << QApplication::translate("filtertote", "Black", 0)
        );
        label_2->setText(QApplication::translate("filtertote", "Type", 0));
        type_comboBox->clear();
        type_comboBox->insertItems(0, QStringList()
         << QApplication::translate("filtertote", "All", 0)
         << QApplication::translate("filtertote", "Air", 0)
         << QApplication::translate("filtertote", "Merchant", 0)
        );
        label_3->setText(QApplication::translate("filtertote", "Source", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("filtertote", "All", 0)
         << QApplication::translate("filtertote", "AIS", 0)
         << QApplication::translate("filtertote", "Radar", 0)
         << QApplication::translate("filtertote", "ESM", 0)
        );
        pushButton->setText(QApplication::translate("filtertote", "Filter", 0));
        pushButton_2->setText(QApplication::translate("filtertote", "Reset", 0));
    } // retranslateUi

};

namespace Ui {
    class filtertote: public Ui_filtertote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERTOTE_H
