/********************************************************************************
** Form generated from reading UI file 'WidgetMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETMENU_H
#define UI_WIDGETMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetMenuClass
{
public:
    QPushButton *bouton_jouer;
    QPushButton *bouton_pointages;
    QPushButton *bouton_quitter;

    void setupUi(QWidget *WidgetMenuClass)
    {
        if (WidgetMenuClass->objectName().isEmpty())
            WidgetMenuClass->setObjectName("WidgetMenuClass");
        WidgetMenuClass->resize(1000, 700);
        bouton_jouer = new QPushButton(WidgetMenuClass);
        bouton_jouer->setObjectName("bouton_jouer");
        bouton_jouer->setGeometry(QRect(250, 230, 500, 50));
        bouton_jouer->setCheckable(true);
        bouton_jouer->setChecked(true);
        bouton_jouer->setAutoDefault(false);
        bouton_jouer->setFlat(false);
        bouton_pointages = new QPushButton(WidgetMenuClass);
        bouton_pointages->setObjectName("bouton_pointages");
        bouton_pointages->setGeometry(QRect(250, 290, 500, 50));
        bouton_pointages->setCheckable(true);
        bouton_quitter = new QPushButton(WidgetMenuClass);
        bouton_quitter->setObjectName("bouton_quitter");
        bouton_quitter->setGeometry(QRect(250, 420, 500, 50));
        bouton_quitter->setCheckable(true);

        retranslateUi(WidgetMenuClass);

        bouton_jouer->setDefault(false);


        QMetaObject::connectSlotsByName(WidgetMenuClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetMenuClass)
    {
        WidgetMenuClass->setWindowTitle(QCoreApplication::translate("WidgetMenuClass", "WidgetMenu", nullptr));
        bouton_jouer->setText(QCoreApplication::translate("WidgetMenuClass", "Jouer", nullptr));
        bouton_pointages->setText(QCoreApplication::translate("WidgetMenuClass", "Pointages", nullptr));
        bouton_quitter->setText(QCoreApplication::translate("WidgetMenuClass", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetMenuClass: public Ui_WidgetMenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETMENU_H
