/********************************************************************************
** Form generated from reading UI file 'WidgetPointage.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETPOINTAGE_H
#define UI_WIDGETPOINTAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPointageClass
{
public:
    QLabel *label;

    void setupUi(QWidget *WidgetPointageClass)
    {
        if (WidgetPointageClass->objectName().isEmpty())
            WidgetPointageClass->setObjectName("WidgetPointageClass");
        WidgetPointageClass->resize(1139, 898);
        label = new QLabel(WidgetPointageClass);
        label->setObjectName("label");
        label->setGeometry(QRect(480, 350, 251, 211));
        QFont font;
        font.setPointSize(48);
        label->setFont(font);

        retranslateUi(WidgetPointageClass);

        QMetaObject::connectSlotsByName(WidgetPointageClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetPointageClass)
    {
        WidgetPointageClass->setWindowTitle(QCoreApplication::translate("WidgetPointageClass", "WidgetPointage", nullptr));
        label->setText(QCoreApplication::translate("WidgetPointageClass", "Yo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPointageClass: public Ui_WidgetPointageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETPOINTAGE_H
