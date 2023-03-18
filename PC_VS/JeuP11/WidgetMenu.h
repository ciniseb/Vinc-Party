#pragma once

#include <QtWidgets/QWidget>
#include "ui_WidgetMenu.h"
#include "ThreadMoteur.h"

class WidgetMenu : public QWidget
{
    Q_OBJECT

public:
    WidgetMenu(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
    ~WidgetMenu();

    ThreadMoteur* threadMoteur;

private:
    Ui::WidgetMenuClass ui;

public slots:
    void selection(int);
    void confirmation();

    //Tests
    void numeroBouton(int);
};

