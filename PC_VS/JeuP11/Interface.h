#pragma once

#include <QStackedWidget>
#include "ui_Interface.h"
#include "ThreadMoteur.h"
#include "WidgetMenu.h"

class Interface : public QStackedWidget
{
	Q_OBJECT

public:
	Interface(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~Interface();

	ThreadMoteur* threadMoteur;

private:
	Ui::InterfaceClass ui;

	WidgetMenu* widgetMenu;
};