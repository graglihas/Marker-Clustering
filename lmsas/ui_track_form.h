/********************************************************************************
** Form generated from reading UI file 'track_form.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACK_FORM_H
#define UI_TRACK_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_track_form
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox;
    QCheckBox *checkBox_10;
    QLineEdit *lineEdit_des;
    QSlider *horizontalSlider;
    QCheckBox *checkBox_7;
    QPushButton *pushButton_del;
    QLineEdit *lineEdit_lat;
    QCheckBox *checkBox_3;
    QLineEdit *lineEdit_speed;
    QCheckBox *checkBox_5;
    QPushButton *pushButton_reset;
    QComboBox *comboBox_color;
    QComboBox *comboBox_type;
    QLineEdit *lineEdit_trackid;
    QLineEdit *lineEdit_lon;
    QCheckBox *checkBox_4;
    QLineEdit *lineEdit_course;
    QCheckBox *checkBox_11;
    QLineEdit *lineEdit_height;
    QCheckBox *checkBox_6;
    QPushButton *pushButton_update;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_hide;
    QCheckBox *checkBox_8;
    QComboBox *comboBox;
    QLabel *label_image;

    void setupUi(QWidget *track_form)
    {
        if (track_form->objectName().isEmpty())
            track_form->setObjectName(QStringLiteral("track_form"));
        track_form->resize(326, 800);
        groupBox = new QGroupBox(track_form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(9, 9, 296, 771));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        checkBox_9 = new QCheckBox(groupBox);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));

        gridLayout_2->addWidget(checkBox_9, 11, 0, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout_2->addWidget(checkBox, 2, 0, 1, 1);

        checkBox_10 = new QCheckBox(groupBox);
        checkBox_10->setObjectName(QStringLiteral("checkBox_10"));

        gridLayout_2->addWidget(checkBox_10, 12, 0, 1, 1);

        lineEdit_des = new QLineEdit(groupBox);
        lineEdit_des->setObjectName(QStringLiteral("lineEdit_des"));

        gridLayout_2->addWidget(lineEdit_des, 2, 1, 1, 1);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider, 12, 1, 1, 1);

        checkBox_7 = new QCheckBox(groupBox);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        gridLayout_2->addWidget(checkBox_7, 9, 0, 1, 1);

        pushButton_del = new QPushButton(groupBox);
        pushButton_del->setObjectName(QStringLiteral("pushButton_del"));

        gridLayout_2->addWidget(pushButton_del, 16, 1, 1, 1);

        lineEdit_lat = new QLineEdit(groupBox);
        lineEdit_lat->setObjectName(QStringLiteral("lineEdit_lat"));

        gridLayout_2->addWidget(lineEdit_lat, 3, 1, 1, 1);

        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        gridLayout_2->addWidget(checkBox_3, 5, 0, 1, 1);

        lineEdit_speed = new QLineEdit(groupBox);
        lineEdit_speed->setObjectName(QStringLiteral("lineEdit_speed"));

        gridLayout_2->addWidget(lineEdit_speed, 8, 1, 1, 1);

        checkBox_5 = new QCheckBox(groupBox);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        gridLayout_2->addWidget(checkBox_5, 7, 0, 1, 1);

        pushButton_reset = new QPushButton(groupBox);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));

        gridLayout_2->addWidget(pushButton_reset, 18, 1, 1, 1);

        comboBox_color = new QComboBox(groupBox);
        comboBox_color->setObjectName(QStringLiteral("comboBox_color"));

        gridLayout_2->addWidget(comboBox_color, 11, 1, 1, 1);

        comboBox_type = new QComboBox(groupBox);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        gridLayout_2->addWidget(comboBox_type, 6, 1, 1, 1);

        lineEdit_trackid = new QLineEdit(groupBox);
        lineEdit_trackid->setObjectName(QStringLiteral("lineEdit_trackid"));

        gridLayout_2->addWidget(lineEdit_trackid, 0, 1, 1, 1);

        lineEdit_lon = new QLineEdit(groupBox);
        lineEdit_lon->setObjectName(QStringLiteral("lineEdit_lon"));

        gridLayout_2->addWidget(lineEdit_lon, 5, 1, 1, 1);

        checkBox_4 = new QCheckBox(groupBox);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        gridLayout_2->addWidget(checkBox_4, 6, 0, 1, 1);

        lineEdit_course = new QLineEdit(groupBox);
        lineEdit_course->setObjectName(QStringLiteral("lineEdit_course"));

        gridLayout_2->addWidget(lineEdit_course, 7, 1, 1, 1);

        checkBox_11 = new QCheckBox(groupBox);
        checkBox_11->setObjectName(QStringLiteral("checkBox_11"));

        gridLayout_2->addWidget(checkBox_11, 14, 0, 1, 1);

        lineEdit_height = new QLineEdit(groupBox);
        lineEdit_height->setObjectName(QStringLiteral("lineEdit_height"));

        gridLayout_2->addWidget(lineEdit_height, 9, 1, 1, 1);

        checkBox_6 = new QCheckBox(groupBox);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        gridLayout_2->addWidget(checkBox_6, 8, 0, 1, 1);

        pushButton_update = new QPushButton(groupBox);
        pushButton_update->setObjectName(QStringLiteral("pushButton_update"));

        gridLayout_2->addWidget(pushButton_update, 16, 0, 1, 1);

        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout_2->addWidget(checkBox_2, 3, 0, 1, 1);

        checkBox_hide = new QCheckBox(groupBox);
        checkBox_hide->setObjectName(QStringLiteral("checkBox_hide"));

        gridLayout_2->addWidget(checkBox_hide, 15, 0, 1, 1);

        checkBox_8 = new QCheckBox(groupBox);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));

        gridLayout_2->addWidget(checkBox_8, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 14, 1, 1, 1);

        label_image = new QLabel(groupBox);
        label_image->setObjectName(QStringLiteral("label_image"));

        gridLayout_2->addWidget(label_image, 18, 0, 1, 1);


        retranslateUi(track_form);

        QMetaObject::connectSlotsByName(track_form);
    } // setupUi

    void retranslateUi(QWidget *track_form)
    {
        track_form->setWindowTitle(QApplication::translate("track_form", "Form", 0));
        groupBox->setTitle(QApplication::translate("track_form", "Inputs", 0));
        checkBox_9->setText(QApplication::translate("track_form", "Force Colour", 0));
        checkBox->setText(QApplication::translate("track_form", "Designation", 0));
        checkBox_10->setText(QApplication::translate("track_form", "Track Size", 0));
        lineEdit_des->setText(QApplication::translate("track_form", "new", 0));
        checkBox_7->setText(QApplication::translate("track_form", "Ht/Dpth(Ft)", 0));
        pushButton_del->setText(QApplication::translate("track_form", "Delete Track", 0));
        lineEdit_lat->setText(QApplication::translate("track_form", "12", 0));
        checkBox_3->setText(QApplication::translate("track_form", "Longitude", 0));
        lineEdit_speed->setText(QApplication::translate("track_form", "10", 0));
        checkBox_5->setText(QApplication::translate("track_form", "Course", 0));
        pushButton_reset->setText(QApplication::translate("track_form", "Reset", 0));
        comboBox_color->clear();
        comboBox_color->insertItems(0, QStringList()
         << QApplication::translate("track_form", "Red", 0)
         << QApplication::translate("track_form", "Blue", 0)
         << QApplication::translate("track_form", "Green", 0)
        );
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("track_form", "Passanger", 0)
         << QApplication::translate("track_form", "Merchant", 0)
         << QApplication::translate("track_form", "Trawler", 0)
        );
        lineEdit_trackid->setText(QApplication::translate("track_form", "1", 0));
        lineEdit_lon->setText(QApplication::translate("track_form", "77", 0));
        checkBox_4->setText(QApplication::translate("track_form", "Type", 0));
        lineEdit_course->setText(QApplication::translate("track_form", "25", 0));
        checkBox_11->setText(QApplication::translate("track_form", "Track Status", 0));
        lineEdit_height->setText(QApplication::translate("track_form", "1000", 0));
        checkBox_6->setText(QApplication::translate("track_form", "Speed(Nm)", 0));
        pushButton_update->setText(QApplication::translate("track_form", "Update Track", 0));
        checkBox_2->setText(QApplication::translate("track_form", "Latitude", 0));
        checkBox_hide->setText(QApplication::translate("track_form", "Hide Track", 0));
        checkBox_8->setText(QApplication::translate("track_form", "Trackid", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("track_form", "Active", 0)
         << QApplication::translate("track_form", "Inactive", 0)
         << QApplication::translate("track_form", "Verified", 0)
         << QApplication::translate("track_form", "Suspecious", 0)
        );
        label_image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class track_form: public Ui_track_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACK_FORM_H
