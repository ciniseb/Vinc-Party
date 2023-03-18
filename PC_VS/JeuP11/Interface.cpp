#include "Interface.h"

Interface::Interface(ThreadMoteur *thread, QWidget *parent)
	: QStackedWidget(parent)
{
	ui.setupUi(this);

	threadMoteur = thread;

	widgetMenu = new WidgetMenu(threadMoteur, this);

	addWidget(widgetMenu);
}

Interface::~Interface()
{}
