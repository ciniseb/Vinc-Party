/********************************************************************************
** Form generated from reading UI file 'WidgetJeuMineur.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETJEUMINEUR_H
#define UI_WIDGETJEUMINEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetJeuMineurClass
{
public:

    void setupUi(QWidget *WidgetJeuMineurClass)
    {
        if (WidgetJeuMineurClass->objectName().isEmpty())
            WidgetJeuMineurClass->setObjectName("WidgetJeuMineurClass");
        WidgetJeuMineurClass->resize(600, 400);

        retranslateUi(WidgetJeuMineurClass);

        QMetaObject::connectSlotsByName(WidgetJeuMineurClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetJeuMineurClass)
    {
        WidgetJeuMineurClass->setWindowTitle(QCoreApplication::translate("WidgetJeuMineurClass", "WidgetJeuMineur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetJeuMineurClass: public Ui_WidgetJeuMineurClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETJEUMINEUR_H
