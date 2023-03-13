/********************************************************************************
** Form generated from reading UI file 'PageJeu.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEJEU_H
#define UI_PAGEJEU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageJeuClass
{
public:

    void setupUi(QWidget *PageJeuClass)
    {
        if (PageJeuClass->objectName().isEmpty())
            PageJeuClass->setObjectName("PageJeuClass");
        PageJeuClass->resize(600, 400);

        retranslateUi(PageJeuClass);

        QMetaObject::connectSlotsByName(PageJeuClass);
    } // setupUi

    void retranslateUi(QWidget *PageJeuClass)
    {
        PageJeuClass->setWindowTitle(QCoreApplication::translate("PageJeuClass", "PageJeu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PageJeuClass: public Ui_PageJeuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEJEU_H
