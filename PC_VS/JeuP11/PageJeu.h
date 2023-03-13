#pragma once

#include <QWidget>
#include "ui_PageJeu.h"

class PageJeu : public QWidget
{
	Q_OBJECT

public:
	PageJeu(QWidget *parent = nullptr);
	~PageJeu();

private:
	Ui::PageJeuClass ui;
};
