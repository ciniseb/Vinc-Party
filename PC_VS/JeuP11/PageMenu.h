#pragma once

#include <QtWidgets/QWidget>
#include "ui_PageMenu.h"

class PageMenu : public QWidget
{
    Q_OBJECT

public:
    PageMenu(QWidget *parent = nullptr);
    ~PageMenu();

private:
    Ui::PageMenuClass ui;
};
