#include "Interface.h"

Interface::Interface(ThreadMoteur *thread, QWidget *parent)
	: QStackedWidget(parent)
{

	ui.setupUi(this);
	

	threadMoteur = thread;

	widgetMenu = new WidgetMenu(threadMoteur, this);
	widgetJeu = new WidgetJeu(threadMoteur, this);
	widgetPointage = new WidgetPointage(threadMoteur, this);
	widgetPiano = new WidgetPiano(threadMoteur, this);

	addWidget(widgetMenu);
	addWidget(widgetJeu);
	addWidget(widgetPointage);
	addWidget(widgetPiano);

}	


Interface::~Interface()
{
	delete threadMoteur;
	delete widgetMenu;

}
