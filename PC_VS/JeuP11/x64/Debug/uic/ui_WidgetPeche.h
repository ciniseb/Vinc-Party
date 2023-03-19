/********************************************************************************
** Form generated from reading UI file 'WidgetPeche.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETPECHE_H
#define UI_WIDGETPECHE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPecheClass
{
public:

    void setupUi(QWidget *WidgetPecheClass)
    {
        if (WidgetPecheClass->objectName().isEmpty())
            WidgetPecheClass->setObjectName("WidgetPecheClass");
        WidgetPecheClass->resize(600, 400);

        retranslateUi(WidgetPecheClass);

        QMetaObject::connectSlotsByName(WidgetPecheClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetPecheClass)
    {
        WidgetPecheClass->setWindowTitle(QCoreApplication::translate("WidgetPecheClass", "WidgetPeche", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPecheClass: public Ui_WidgetPecheClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETPECHE_H
