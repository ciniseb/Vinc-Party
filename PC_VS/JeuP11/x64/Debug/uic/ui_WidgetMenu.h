/********************************************************************************
** Form generated from reading UI file 'WidgetMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETMENU_H
#define UI_WIDGETMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetMenuClass
{
public:
    QLabel *label;

    void setupUi(QWidget *WidgetMenuClass)
    {
        if (WidgetMenuClass->objectName().isEmpty())
            WidgetMenuClass->setObjectName("WidgetMenuClass");
        WidgetMenuClass->resize(405, 219);
        label = new QLabel(WidgetMenuClass);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 70, 91, 81));

        retranslateUi(WidgetMenuClass);

        QMetaObject::connectSlotsByName(WidgetMenuClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetMenuClass)
    {
        WidgetMenuClass->setWindowTitle(QCoreApplication::translate("WidgetMenuClass", "WidgetMenu", nullptr));
        label->setText(QCoreApplication::translate("WidgetMenuClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetMenuClass: public Ui_WidgetMenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETMENU_H
