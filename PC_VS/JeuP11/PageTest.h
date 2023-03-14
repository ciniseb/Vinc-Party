#pragma once

#include <QWidget>
#include "Page.h"
#include "ui_PageTest.h"

class PageTest : public QWidget, public Page
{
public:
	PageTest(ES*);
	~PageTest();

	void initialiser();
	void ouvrir();

	void affichage_DEBUG(int);

private:
	Ui::PageTestClass ui;
};