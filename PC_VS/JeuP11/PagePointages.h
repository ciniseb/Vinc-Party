#pragma once

#include <QWidget>
#include "ui_PagePointages.h"

class PagePointages : public QWidget
{
	Q_OBJECT

public:
	PagePointages(QWidget *parent = nullptr);
	~PagePointages();

private:
	Ui::PagePointagesClass ui;
};
