#pragma once

#include <QWidget>
#include "ui_Page.h"

class Page : public QWidget
{
	Q_OBJECT

public:
	Page(QWidget *parent = nullptr);
	~Page();

private:
	Ui::PageClass ui;
};
