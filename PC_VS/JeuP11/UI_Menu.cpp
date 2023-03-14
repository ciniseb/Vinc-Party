#include "UI_Menu.h"

UI_Menu::UI_Menu(QWidget *parent)
	: QWidget(parent), pageMenu(&threadArduino)
{
	ui.setupUi(this);

	threadArduino.demarrer();
	pageMenu.start();

	QWidget::connect(&pageMenu, SIGNAL(FenetreMenu::test), this, SLOT(test));
}

UI_Menu::~UI_Menu()
{}

void UI_Menu::test()
{
	ui.bouton_test->setText("WOUHOUUUUUU");
}