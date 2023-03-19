/********************************************************************************
** Form generated from reading UI file 'Interface.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceClass
{
public:

    void setupUi(QStackedWidget *InterfaceClass)
    {
        if (InterfaceClass->objectName().isEmpty())
            InterfaceClass->setObjectName("InterfaceClass");
        InterfaceClass->resize(1000, 700);

        retranslateUi(InterfaceClass);

        QMetaObject::connectSlotsByName(InterfaceClass);
    } // setupUi

    void retranslateUi(QStackedWidget *InterfaceClass)
    {
        InterfaceClass->setWindowTitle(QCoreApplication::translate("InterfaceClass", "Interface", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InterfaceClass: public Ui_InterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
