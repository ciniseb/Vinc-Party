/********************************************************************************
** Form generated from reading UI file 'PageMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEMENU_H
#define UI_PAGEMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageMenuClass
{
public:

    void setupUi(QWidget *PageMenuClass)
    {
        if (PageMenuClass->objectName().isEmpty())
            PageMenuClass->setObjectName("PageMenuClass");
        PageMenuClass->resize(600, 400);

        retranslateUi(PageMenuClass);

        QMetaObject::connectSlotsByName(PageMenuClass);
    } // setupUi

    void retranslateUi(QWidget *PageMenuClass)
    {
        PageMenuClass->setWindowTitle(QCoreApplication::translate("PageMenuClass", "PageMenu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PageMenuClass: public Ui_PageMenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEMENU_H
