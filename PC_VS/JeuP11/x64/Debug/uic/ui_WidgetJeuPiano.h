/********************************************************************************
** Form generated from reading UI file 'WidgetJeuPiano.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETJEUPIANO_H
#define UI_WIDGETJEUPIANO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetJeuPianoClass
{
public:

    void setupUi(QWidget *WidgetJeuPianoClass)
    {
        if (WidgetJeuPianoClass->objectName().isEmpty())
            WidgetJeuPianoClass->setObjectName("WidgetJeuPianoClass");
        WidgetJeuPianoClass->resize(600, 400);

        retranslateUi(WidgetJeuPianoClass);

        QMetaObject::connectSlotsByName(WidgetJeuPianoClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetJeuPianoClass)
    {
        WidgetJeuPianoClass->setWindowTitle(QCoreApplication::translate("WidgetJeuPianoClass", "WidgetJeuPiano", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetJeuPianoClass: public Ui_WidgetJeuPianoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETJEUPIANO_H
