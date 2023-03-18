/********************************************************************************
** Form generated from reading UI file 'WidgetPiano.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETPIANO_H
#define UI_WIDGETPIANO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPianoClass
{
public:

    void setupUi(QWidget *WidgetPianoClass)
    {
        if (WidgetPianoClass->objectName().isEmpty())
            WidgetPianoClass->setObjectName("WidgetPianoClass");
        WidgetPianoClass->resize(600, 400);

        retranslateUi(WidgetPianoClass);

        QMetaObject::connectSlotsByName(WidgetPianoClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetPianoClass)
    {
        WidgetPianoClass->setWindowTitle(QCoreApplication::translate("WidgetPianoClass", "WidgetPiano", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPianoClass: public Ui_WidgetPianoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETPIANO_H
