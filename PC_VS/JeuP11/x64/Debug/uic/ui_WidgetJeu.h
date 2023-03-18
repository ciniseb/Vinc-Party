/********************************************************************************
** Form generated from reading UI file 'WidgetJeu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETJEU_H
#define UI_WIDGETJEU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetJeuClass
{
public:
    QFrame *frame;

    void setupUi(QWidget *WidgetJeuClass)
    {
        if (WidgetJeuClass->objectName().isEmpty())
            WidgetJeuClass->setObjectName("WidgetJeuClass");
        WidgetJeuClass->resize(1000, 700);
        frame = new QFrame(WidgetJeuClass);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 200, 1000, 500));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(WidgetJeuClass);

        QMetaObject::connectSlotsByName(WidgetJeuClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetJeuClass)
    {
        WidgetJeuClass->setWindowTitle(QCoreApplication::translate("WidgetJeuClass", "WidgetJeu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetJeuClass: public Ui_WidgetJeuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETJEU_H
