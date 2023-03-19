/********************************************************************************
** Form generated from reading UI file 'WidgetMineur.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETMINEUR_H
#define UI_WIDGETMINEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetMineurClass
{
public:

    void setupUi(QWidget *WidgetMineurClass)
    {
        if (WidgetMineurClass->objectName().isEmpty())
            WidgetMineurClass->setObjectName("WidgetMineurClass");
        WidgetMineurClass->resize(600, 400);

        retranslateUi(WidgetMineurClass);

        QMetaObject::connectSlotsByName(WidgetMineurClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetMineurClass)
    {
        WidgetMineurClass->setWindowTitle(QCoreApplication::translate("WidgetMineurClass", "WidgetMineur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetMineurClass: public Ui_WidgetMineurClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETMINEUR_H
