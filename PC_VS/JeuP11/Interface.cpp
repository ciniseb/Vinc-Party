#include "Interface.h"

Interface::Interface(ThreadMoteur *thread, QWidget *parent)
	: QStackedWidget(parent)
{
	ui.setupUi(this);

	threadMoteur = thread;

	widgetMenu = new WidgetMenu(threadMoteur, this);
	widgetJeu = new WidgetJeu(threadMoteur, this);

	addWidget(widgetMenu);
	addWidget(widgetJeu);
}

Interface::~Interface()
{
	delete threadMoteur;
	delete widgetMenu;
}
