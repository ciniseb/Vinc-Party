#include "WidgetMenu.h"

WidgetMenu::WidgetMenu(ThreadMoteur* thread, QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    threadMoteur = thread;

    connect(threadMoteur, SIGNAL(updateNumero(int)), this, SLOT(numeroBouton(int)));

}

WidgetMenu::~WidgetMenu()
{}

void WidgetMenu::numeroBouton(int valeur)
{
    ui.label->setText(QString::number(valeur));
}