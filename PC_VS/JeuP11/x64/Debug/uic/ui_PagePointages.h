/********************************************************************************
** Form generated from reading UI file 'PagePointages.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEPOINTAGES_H
#define UI_PAGEPOINTAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PagePointagesClass
{
public:

    void setupUi(QWidget *PagePointagesClass)
    {
        if (PagePointagesClass->objectName().isEmpty())
            PagePointagesClass->setObjectName("PagePointagesClass");
        PagePointagesClass->resize(600, 400);

        retranslateUi(PagePointagesClass);

        QMetaObject::connectSlotsByName(PagePointagesClass);
    } // setupUi

    void retranslateUi(QWidget *PagePointagesClass)
    {
        PagePointagesClass->setWindowTitle(QCoreApplication::translate("PagePointagesClass", "PagePointages", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PagePointagesClass: public Ui_PagePointagesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEPOINTAGES_H
