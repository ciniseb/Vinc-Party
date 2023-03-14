/********************************************************************************
** Form generated from reading UI file 'UI_Menu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_MENU_H
#define UI_UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UI_MenuClass
{
public:
    QPushButton *bouton_test;

    void setupUi(QWidget *UI_MenuClass)
    {
        if (UI_MenuClass->objectName().isEmpty())
            UI_MenuClass->setObjectName("UI_MenuClass");
        UI_MenuClass->resize(600, 400);
        bouton_test = new QPushButton(UI_MenuClass);
        bouton_test->setObjectName("bouton_test");
        bouton_test->setGeometry(QRect(250, 180, 75, 24));

        retranslateUi(UI_MenuClass);

        QMetaObject::connectSlotsByName(UI_MenuClass);
    } // setupUi

    void retranslateUi(QWidget *UI_MenuClass)
    {
        UI_MenuClass->setWindowTitle(QCoreApplication::translate("UI_MenuClass", "UI_Menu", nullptr));
        bouton_test->setText(QCoreApplication::translate("UI_MenuClass", "RIEN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UI_MenuClass: public Ui_UI_MenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_MENU_H
