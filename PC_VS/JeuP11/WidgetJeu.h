#pragma once

#include <QWidget>
#include "ui_WidgetJeu.h"
#include "ThreadMoteur.h"

class WidgetJeu : public QWidget
{
	Q_OBJECT

public:
	WidgetJeu(ThreadMoteur* thread = nullptr, QWidget* parent = nullptr);
	~WidgetJeu();

	ThreadMoteur* threadMoteur;

private:
	Ui::WidgetJeuClass ui;
};
