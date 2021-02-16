/********************************************************************************
** Form generated from reading UI file 'polygon_form.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLYGON_FORM_H
#define UI_POLYGON_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Polygon_Form
{
public:
    QGroupBox *PolygonInputgroupBox;
    QLabel *label;
    QComboBox *DesignationcomboBox;
    QTableWidget *PolyPointstable;
    QCheckBox *SelectMousecheckBox;
    QPushButton *AddPolygonButton;
    QPushButton *UpdatePolygonButton;
    QPushButton *DeletePolygonButton;
    QPushButton *ExportPolygonButton;
    QPushButton *SetStyleButton;
    QGroupBox *SelectPolygongroupBox;
    QPushButton *MovePolygonButton;
    QPushButton *RotatePolygonButton;
    QPushButton *ScalePolygonButton;
    QPushButton *MoveVerticesButton;
    QPushButton *AddVerticesButton;
    QPushButton *DeleteVerticesButton;
    QPushButton *ChangeVerticesButton;
    QComboBox *ColorcomboBox;
    QComboBox *comboBox_3;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *Polygon_Form)
    {
        if (Polygon_Form->objectName().isEmpty())
            Polygon_Form->setObjectName(QStringLiteral("Polygon_Form"));
        Polygon_Form->resize(400, 928);
        PolygonInputgroupBox = new QGroupBox(Polygon_Form);
        PolygonInputgroupBox->setObjectName(QStringLiteral("PolygonInputgroupBox"));
        PolygonInputgroupBox->setGeometry(QRect(10, 10, 381, 491));
        label = new QLabel(PolygonInputgroupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 66, 21));
        DesignationcomboBox = new QComboBox(PolygonInputgroupBox);
        DesignationcomboBox->setObjectName(QStringLiteral("DesignationcomboBox"));
        DesignationcomboBox->setGeometry(QRect(100, 30, 251, 29));
        DesignationcomboBox->setEditable(true);
        PolyPointstable = new QTableWidget(PolygonInputgroupBox);
        if (PolyPointstable->columnCount() < 2)
            PolyPointstable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        PolyPointstable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        PolyPointstable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (PolyPointstable->rowCount() < 6)
            PolyPointstable->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        PolyPointstable->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        PolyPointstable->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        PolyPointstable->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        PolyPointstable->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        PolyPointstable->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        PolyPointstable->setVerticalHeaderItem(5, __qtablewidgetitem7);
        PolyPointstable->setObjectName(QStringLiteral("PolyPointstable"));
        PolyPointstable->setGeometry(QRect(20, 70, 231, 151));
        SelectMousecheckBox = new QCheckBox(PolygonInputgroupBox);
        SelectMousecheckBox->setObjectName(QStringLiteral("SelectMousecheckBox"));
        SelectMousecheckBox->setGeometry(QRect(20, 230, 271, 26));
        AddPolygonButton = new QPushButton(PolygonInputgroupBox);
        AddPolygonButton->setObjectName(QStringLiteral("AddPolygonButton"));
        AddPolygonButton->setGeometry(QRect(0, 400, 161, 31));
        UpdatePolygonButton = new QPushButton(PolygonInputgroupBox);
        UpdatePolygonButton->setObjectName(QStringLiteral("UpdatePolygonButton"));
        UpdatePolygonButton->setGeometry(QRect(210, 400, 161, 31));
        DeletePolygonButton = new QPushButton(PolygonInputgroupBox);
        DeletePolygonButton->setObjectName(QStringLiteral("DeletePolygonButton"));
        DeletePolygonButton->setGeometry(QRect(0, 440, 161, 31));
        ExportPolygonButton = new QPushButton(PolygonInputgroupBox);
        ExportPolygonButton->setObjectName(QStringLiteral("ExportPolygonButton"));
        ExportPolygonButton->setGeometry(QRect(210, 440, 161, 31));
        SetStyleButton = new QPushButton(PolygonInputgroupBox);
        SetStyleButton->setObjectName(QStringLiteral("SetStyleButton"));
        SetStyleButton->setGeometry(QRect(0, 360, 371, 31));
        SelectPolygongroupBox = new QGroupBox(Polygon_Form);
        SelectPolygongroupBox->setObjectName(QStringLiteral("SelectPolygongroupBox"));
        SelectPolygongroupBox->setGeometry(QRect(10, 520, 381, 151));
        MovePolygonButton = new QPushButton(SelectPolygongroupBox);
        MovePolygonButton->setObjectName(QStringLiteral("MovePolygonButton"));
        MovePolygonButton->setGeometry(QRect(20, 30, 98, 31));
        RotatePolygonButton = new QPushButton(SelectPolygongroupBox);
        RotatePolygonButton->setObjectName(QStringLiteral("RotatePolygonButton"));
        RotatePolygonButton->setGeometry(QRect(140, 30, 98, 31));
        ScalePolygonButton = new QPushButton(SelectPolygongroupBox);
        ScalePolygonButton->setObjectName(QStringLiteral("ScalePolygonButton"));
        ScalePolygonButton->setGeometry(QRect(260, 30, 98, 31));
        MoveVerticesButton = new QPushButton(SelectPolygongroupBox);
        MoveVerticesButton->setObjectName(QStringLiteral("MoveVerticesButton"));
        MoveVerticesButton->setGeometry(QRect(140, 70, 111, 31));
        AddVerticesButton = new QPushButton(SelectPolygongroupBox);
        AddVerticesButton->setObjectName(QStringLiteral("AddVerticesButton"));
        AddVerticesButton->setGeometry(QRect(20, 70, 98, 31));
        DeleteVerticesButton = new QPushButton(SelectPolygongroupBox);
        DeleteVerticesButton->setObjectName(QStringLiteral("DeleteVerticesButton"));
        DeleteVerticesButton->setGeometry(QRect(260, 70, 111, 31));
        ChangeVerticesButton = new QPushButton(SelectPolygongroupBox);
        ChangeVerticesButton->setObjectName(QStringLiteral("ChangeVerticesButton"));
        ChangeVerticesButton->setGeometry(QRect(20, 110, 98, 31));
        ColorcomboBox = new QComboBox(Polygon_Form);
        ColorcomboBox->setObjectName(QStringLiteral("ColorcomboBox"));
        ColorcomboBox->setGeometry(QRect(60, 280, 101, 29));
        comboBox_3 = new QComboBox(Polygon_Form);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(280, 320, 101, 29));
        label_3 = new QLabel(Polygon_Form);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 280, 66, 21));
        comboBox_2 = new QComboBox(Polygon_Form);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(280, 280, 101, 29));
        label_2 = new QLabel(Polygon_Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 280, 66, 21));
        spinBox = new QSpinBox(Polygon_Form);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(110, 320, 51, 31));
        label_4 = new QLabel(Polygon_Form);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 320, 91, 21));
        label_5 = new QLabel(Polygon_Form);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 320, 111, 21));

        retranslateUi(Polygon_Form);

        QMetaObject::connectSlotsByName(Polygon_Form);
    } // setupUi

    void retranslateUi(QWidget *Polygon_Form)
    {
        Polygon_Form->setWindowTitle(QApplication::translate("Polygon_Form", "Form", 0));
        PolygonInputgroupBox->setTitle(QApplication::translate("Polygon_Form", "Inputs", 0));
        label->setText(QApplication::translate("Polygon_Form", "Desig.", 0));
        QTableWidgetItem *___qtablewidgetitem = PolyPointstable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Polygon_Form", "Lat.", 0));
        QTableWidgetItem *___qtablewidgetitem1 = PolyPointstable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Polygon_Form", "Long.", 0));
        QTableWidgetItem *___qtablewidgetitem2 = PolyPointstable->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("Polygon_Form", "1", 0));
        QTableWidgetItem *___qtablewidgetitem3 = PolyPointstable->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("Polygon_Form", "2", 0));
        QTableWidgetItem *___qtablewidgetitem4 = PolyPointstable->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("Polygon_Form", "3", 0));
        QTableWidgetItem *___qtablewidgetitem5 = PolyPointstable->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("Polygon_Form", "4", 0));
        QTableWidgetItem *___qtablewidgetitem6 = PolyPointstable->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("Polygon_Form", "5", 0));
        QTableWidgetItem *___qtablewidgetitem7 = PolyPointstable->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("Polygon_Form", "6", 0));
        SelectMousecheckBox->setText(QApplication::translate("Polygon_Form", "Select Polygon Points With &Mouse", 0));
        AddPolygonButton->setText(QApplication::translate("Polygon_Form", "&Add", 0));
        UpdatePolygonButton->setText(QApplication::translate("Polygon_Form", "&Update", 0));
        DeletePolygonButton->setText(QApplication::translate("Polygon_Form", "&Delete", 0));
        ExportPolygonButton->setText(QApplication::translate("Polygon_Form", "&Export", 0));
        SetStyleButton->setText(QApplication::translate("Polygon_Form", "Set Style", 0));
        SelectPolygongroupBox->setTitle(QApplication::translate("Polygon_Form", "Edit Selected Polygon", 0));
        MovePolygonButton->setText(QApplication::translate("Polygon_Form", "Move", 0));
        RotatePolygonButton->setText(QApplication::translate("Polygon_Form", "Rotate", 0));
        ScalePolygonButton->setText(QApplication::translate("Polygon_Form", "Scale", 0));
        MoveVerticesButton->setText(QApplication::translate("Polygon_Form", "Move Vertices", 0));
        AddVerticesButton->setText(QApplication::translate("Polygon_Form", "Add Vertices", 0));
        DeleteVerticesButton->setText(QApplication::translate("Polygon_Form", "Delete Vertices", 0));
        ChangeVerticesButton->setText(QApplication::translate("Polygon_Form", "Change &Style", 0));
        label_3->setText(QApplication::translate("Polygon_Form", "Fill Style", 0));
        label_2->setText(QApplication::translate("Polygon_Form", "Color", 0));
        label_4->setText(QApplication::translate("Polygon_Form", "Transperancy", 0));
        label_5->setText(QApplication::translate("Polygon_Form", "Boundary Style", 0));
    } // retranslateUi

};

namespace Ui {
    class Polygon_Form: public Ui_Polygon_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLYGON_FORM_H
