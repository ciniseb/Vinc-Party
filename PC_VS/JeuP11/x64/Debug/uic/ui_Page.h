/********************************************************************************
** Form generated from reading UI file 'Page.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_H
#define UI_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageClass
{
public:

    void setupUi(QWidget *PageClass)
    {
        if (PageClass->objectName().isEmpty())
            PageClass->setObjectName("PageClass");
        PageClass->resize(600, 400);

        retranslateUi(PageClass);

        QMetaObject::connectSlotsByName(PageClass);
    } // setupUi

    void retranslateUi(QWidget *PageClass)
    {
        PageClass->setWindowTitle(QCoreApplication::translate("PageClass", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PageClass: public Ui_PageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_H
