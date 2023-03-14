#pragma once

#include "FenetreMenu.h"
#include <QWidget>
#include "ui_UI_Menu.h"

class UI_Menu : public QWidget
{
	Q_OBJECT

private:
	Ui::UI_MenuClass ui;

	ES threadArduino;
	FenetreMenu pageMenu;

public:
	UI_Menu(QWidget *parent = nullptr);
	~UI_Menu();

signals:


private slots:
	void test();

};
