#pragma once

#include <QStackedWidget>
#include "ui_Interface.h"
#include "ThreadMoteur.h"
#include "WidgetMenu.h"
#include "WidgetJeu.h"

class Interface : public QStackedWidget
{
	Q_OBJECT

public:
	Interface(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~Interface();

private:
	Ui::InterfaceClass ui;

	ThreadMoteur* threadMoteur;

	WidgetMenu* widgetMenu;
	WidgetJeu* widgetJeu;
};