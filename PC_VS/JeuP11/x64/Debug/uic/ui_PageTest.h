/********************************************************************************
** Form generated from reading UI file 'PageTest.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGETEST_H
#define UI_PAGETEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageTestClass
{
public:

    void setupUi(QWidget *PageTestClass)
    {
        if (PageTestClass->objectName().isEmpty())
            PageTestClass->setObjectName("PageTestClass");
        PageTestClass->resize(600, 400);

        retranslateUi(PageTestClass);

        QMetaObject::connectSlotsByName(PageTestClass);
    } // setupUi

    void retranslateUi(QWidget *PageTestClass)
    {
        PageTestClass->setWindowTitle(QCoreApplication::translate("PageTestClass", "PageTest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PageTestClass: public Ui_PageTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGETEST_H
