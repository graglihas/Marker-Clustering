/********************************************************************************
** Form generated from reading UI file 'expandingsquaresearch_form.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPANDINGSQUARESEARCH_FORM_H
#define UI_EXPANDINGSQUARESEARCH_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExpandingSquareSearch_form
{
public:
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *LatlineEdit;
    QLabel *label_5;
    QCheckBox *StartPointcheckBox;
    QLineEdit *LonglineEdit;
    QGroupBox *groupBox_4;
    QTableWidget *tableWidget;
    QCheckBox *ScoutPoscheckBox;
    QGroupBox *groupBox_5;
    QLabel *label_6;
    QLineEdit *SWidthlineEdit;
    QLabel *label_7;
    QLineEdit *CoverageFlineEdit;
    QLabel *label_8;
    QLineEdit *InvestigationTlineEdit;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *ScoutSpeedlineEdit;
    QLineEdit *WindDirlineEdit;
    QLineEdit *NoOfTurnslineEdit;
    QLineEdit *TransitSpeedlineEdit;
    QLineEdit *RemarkslineEdit;
    QLabel *label_16;
    QDoubleSpinBox *EnduranceSpinBox;
    QGroupBox *groupBox_6;
    QFormLayout *formLayout_3;
    QLabel *label;
    QComboBox *DesincomboBox;
    QLabel *label_2;
    QLabel *label_3;
    QCheckBox *checkBox;
    QSpinBox *LineWidthSpinBox;
    QSpinBox *ColorspinBox;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *label_14;
    QLineEdit *TrackSpacelineEdit;
    QLabel *label_15;
    QLineEdit *EstimateTlineEdit;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_3;
    QPushButton *AddUpdateButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *ExpandingSquareSearch_form)
    {
        if (ExpandingSquareSearch_form->objectName().isEmpty())
            ExpandingSquareSearch_form->setObjectName(QStringLiteral("ExpandingSquareSearch_form"));
        ExpandingSquareSearch_form->resize(410, 1055);
        groupBox = new QGroupBox(ExpandingSquareSearch_form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 400, 781));
        groupBox->setStyleSheet(QStringLiteral(""));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 180, 331, 131));
        formLayout = new QFormLayout(groupBox_3);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        LatlineEdit = new QLineEdit(groupBox_3);
        LatlineEdit->setObjectName(QStringLiteral("LatlineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, LatlineEdit);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        StartPointcheckBox = new QCheckBox(groupBox_3);
        StartPointcheckBox->setObjectName(QStringLiteral("StartPointcheckBox"));

        formLayout->setWidget(3, QFormLayout::LabelRole, StartPointcheckBox);

        LonglineEdit = new QLineEdit(groupBox_3);
        LonglineEdit->setObjectName(QStringLiteral("LonglineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, LonglineEdit);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 630, 401, 151));
        tableWidget = new QTableWidget(groupBox_4);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 50, 321, 101));
        ScoutPoscheckBox = new QCheckBox(groupBox_4);
        ScoutPoscheckBox->setObjectName(QStringLiteral("ScoutPoscheckBox"));
        ScoutPoscheckBox->setGeometry(QRect(30, 20, 271, 26));
        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 290, 351, 341));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(17, 25, 128, 21));
        SWidthlineEdit = new QLineEdit(groupBox_5);
        SWidthlineEdit->setObjectName(QStringLiteral("SWidthlineEdit"));
        SWidthlineEdit->setGeometry(QRect(151, 25, 171, 33));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(17, 64, 110, 21));
        CoverageFlineEdit = new QLineEdit(groupBox_5);
        CoverageFlineEdit->setObjectName(QStringLiteral("CoverageFlineEdit"));
        CoverageFlineEdit->setGeometry(QRect(151, 64, 171, 33));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(17, 103, 119, 21));
        InvestigationTlineEdit = new QLineEdit(groupBox_5);
        InvestigationTlineEdit->setObjectName(QStringLiteral("InvestigationTlineEdit"));
        InvestigationTlineEdit->setGeometry(QRect(151, 103, 171, 33));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(17, 142, 111, 21));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(17, 181, 100, 21));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(17, 220, 82, 21));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(17, 259, 117, 21));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(17, 298, 57, 21));
        ScoutSpeedlineEdit = new QLineEdit(groupBox_5);
        ScoutSpeedlineEdit->setObjectName(QStringLiteral("ScoutSpeedlineEdit"));
        ScoutSpeedlineEdit->setGeometry(QRect(151, 142, 171, 33));
        WindDirlineEdit = new QLineEdit(groupBox_5);
        WindDirlineEdit->setObjectName(QStringLiteral("WindDirlineEdit"));
        WindDirlineEdit->setGeometry(QRect(150, 180, 171, 33));
        NoOfTurnslineEdit = new QLineEdit(groupBox_5);
        NoOfTurnslineEdit->setObjectName(QStringLiteral("NoOfTurnslineEdit"));
        NoOfTurnslineEdit->setGeometry(QRect(150, 220, 171, 33));
        TransitSpeedlineEdit = new QLineEdit(groupBox_5);
        TransitSpeedlineEdit->setObjectName(QStringLiteral("TransitSpeedlineEdit"));
        TransitSpeedlineEdit->setGeometry(QRect(150, 259, 51, 33));
        RemarkslineEdit = new QLineEdit(groupBox_5);
        RemarkslineEdit->setObjectName(QStringLiteral("RemarkslineEdit"));
        RemarkslineEdit->setGeometry(QRect(150, 298, 171, 33));
        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(210, 260, 71, 21));
        EnduranceSpinBox = new QDoubleSpinBox(groupBox_5);
        EnduranceSpinBox->setObjectName(QStringLiteral("EnduranceSpinBox"));
        EnduranceSpinBox->setGeometry(QRect(280, 260, 61, 31));
        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(20, 14, 311, 194));
        formLayout_3 = new QFormLayout(groupBox_6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label = new QLabel(groupBox_6);
        label->setObjectName(QStringLiteral("label"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        DesincomboBox = new QComboBox(groupBox_6);
        DesincomboBox->setObjectName(QStringLiteral("DesincomboBox"));
        DesincomboBox->setEditable(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, DesincomboBox);

        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox_6);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_3);

        checkBox = new QCheckBox(groupBox_6);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, checkBox);

        LineWidthSpinBox = new QSpinBox(groupBox_6);
        LineWidthSpinBox->setObjectName(QStringLiteral("LineWidthSpinBox"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, LineWidthSpinBox);

        ColorspinBox = new QSpinBox(groupBox_6);
        ColorspinBox->setObjectName(QStringLiteral("ColorspinBox"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, ColorspinBox);

        groupBox_2 = new QGroupBox(ExpandingSquareSearch_form);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 940, 321, 108));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_14);

        TrackSpacelineEdit = new QLineEdit(groupBox_2);
        TrackSpacelineEdit->setObjectName(QStringLiteral("TrackSpacelineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, TrackSpacelineEdit);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_15);

        EstimateTlineEdit = new QLineEdit(groupBox_2);
        EstimateTlineEdit->setObjectName(QStringLiteral("EstimateTlineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, EstimateTlineEdit);

        label_14->raise();
        label_15->raise();
        TrackSpacelineEdit->raise();
        EstimateTlineEdit->raise();
        groupBox_7 = new QGroupBox(ExpandingSquareSearch_form);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 810, 341, 141));
        gridLayout_3 = new QGridLayout(groupBox_7);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        AddUpdateButton = new QPushButton(groupBox_7);
        AddUpdateButton->setObjectName(QStringLiteral("AddUpdateButton"));

        gridLayout_3->addWidget(AddUpdateButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox_7);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(groupBox_7);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_3->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(groupBox_7);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_3->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(groupBox_7);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_3->addWidget(pushButton_5, 2, 0, 1, 2);


        retranslateUi(ExpandingSquareSearch_form);

        QMetaObject::connectSlotsByName(ExpandingSquareSearch_form);
    } // setupUi

    void retranslateUi(QWidget *ExpandingSquareSearch_form)
    {
        ExpandingSquareSearch_form->setWindowTitle(QApplication::translate("ExpandingSquareSearch_form", "Form", 0));
        groupBox->setTitle(QApplication::translate("ExpandingSquareSearch_form", "Inputs", 0));
        groupBox_3->setTitle(QApplication::translate("ExpandingSquareSearch_form", "Starting Point", 0));
        label_4->setText(QApplication::translate("ExpandingSquareSearch_form", "Latitude", 0));
        label_5->setText(QApplication::translate("ExpandingSquareSearch_form", "Longitude", 0));
        StartPointcheckBox->setText(QApplication::translate("ExpandingSquareSearch_form", "Select With Mouse Click", 0));
        groupBox_4->setTitle(QApplication::translate("ExpandingSquareSearch_form", "Scout Start and Return Point", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ExpandingSquareSearch_form", "Latitude", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ExpandingSquareSearch_form", "Longitude", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("ExpandingSquareSearch_form", "Start Position", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("ExpandingSquareSearch_form", "Return Position", 0));
        ScoutPoscheckBox->setText(QApplication::translate("ExpandingSquareSearch_form", "Select Position With Mouse Click", 0));
        groupBox_5->setTitle(QString());
        label_6->setText(QApplication::translate("ExpandingSquareSearch_form", "Sweep Width (Nm)", 0));
        label_7->setText(QApplication::translate("ExpandingSquareSearch_form", "Coverage Factor", 0));
        label_8->setText(QApplication::translate("ExpandingSquareSearch_form", "Investigation Time", 0));
        label_9->setText(QApplication::translate("ExpandingSquareSearch_form", "Scout Speed(Kt)", 0));
        label_10->setText(QApplication::translate("ExpandingSquareSearch_form", "Wind Direction", 0));
        label_11->setText(QApplication::translate("ExpandingSquareSearch_form", "No Of Turns", 0));
        label_12->setText(QApplication::translate("ExpandingSquareSearch_form", "Transit Speed(Kt)", 0));
        label_13->setText(QApplication::translate("ExpandingSquareSearch_form", "Remarks", 0));
        label_16->setText(QApplication::translate("ExpandingSquareSearch_form", "Endurance", 0));
        groupBox_6->setTitle(QString());
        label->setText(QApplication::translate("ExpandingSquareSearch_form", "Designation", 0));
        label_2->setText(QApplication::translate("ExpandingSquareSearch_form", "Force color", 0));
        label_3->setText(QApplication::translate("ExpandingSquareSearch_form", "Line Width", 0));
        checkBox->setText(QApplication::translate("ExpandingSquareSearch_form", "Hide", 0));
        groupBox_2->setTitle(QApplication::translate("ExpandingSquareSearch_form", "Outputs", 0));
        label_14->setText(QApplication::translate("ExpandingSquareSearch_form", "TrackSpace(Nm)", 0));
        label_15->setText(QApplication::translate("ExpandingSquareSearch_form", "Total Estimation Time", 0));
        groupBox_7->setTitle(QString());
        AddUpdateButton->setText(QApplication::translate("ExpandingSquareSearch_form", "Add/Update", 0));
        pushButton_2->setText(QApplication::translate("ExpandingSquareSearch_form", "Delete", 0));
        pushButton_3->setText(QApplication::translate("ExpandingSquareSearch_form", "View Page", 0));
        pushButton_4->setText(QApplication::translate("ExpandingSquareSearch_form", "Export", 0));
        pushButton_5->setText(QApplication::translate("ExpandingSquareSearch_form", "Reset", 0));
    } // retranslateUi

};

namespace Ui {
    class ExpandingSquareSearch_form: public Ui_ExpandingSquareSearch_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPANDINGSQUARESEARCH_FORM_H
