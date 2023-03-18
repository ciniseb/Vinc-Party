#include "WidgetJeu.h"

WidgetJeu::WidgetJeu(ThreadMoteur* thread, QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    threadMoteur = thread;

    //Connexions
}

WidgetJeu::~WidgetJeu()
{}
