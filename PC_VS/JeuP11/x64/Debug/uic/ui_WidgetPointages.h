/********************************************************************************
** Form generated from reading UI file 'WidgetPointages.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETPOINTAGES_H
#define UI_WIDGETPOINTAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPointagesClass
{
public:
    QLabel *label;

    void setupUi(QWidget *WidgetPointagesClass)
    {
        if (WidgetPointagesClass->objectName().isEmpty())
            WidgetPointagesClass->setObjectName("WidgetPointagesClass");
        WidgetPointagesClass->resize(1139, 898);
        label = new QLabel(WidgetPointagesClass);
        label->setObjectName("label");
        label->setGeometry(QRect(480, 350, 251, 211));
        QFont font;
        font.setPointSize(48);
        label->setFont(font);

        retranslateUi(WidgetPointagesClass);

        QMetaObject::connectSlotsByName(WidgetPointagesClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetPointagesClass)
    {
        WidgetPointagesClass->setWindowTitle(QCoreApplication::translate("WidgetPointagesClass", "WidgetPointages", nullptr));
        label->setText(QCoreApplication::translate("WidgetPointagesClass", "Yo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPointagesClass: public Ui_WidgetPointagesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETPOINTAGES_H
