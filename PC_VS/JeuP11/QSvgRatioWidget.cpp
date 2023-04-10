#include "QSvgRatioWidget.h"

QSvgRatioWidget::QSvgRatioWidget(int hauteur, int largeur, QWidget *parent) : QSvgWidget(parent)
{
    ratio = hauteur / largeur;
}

QSvgRatioWidget::~QSvgRatioWidget() {}

void QSvgRatioWidget::resizeEvent(QResizeEvent* event)
{
    event->accept();

    if (event->size().width()*ratio > event->size().height()) {
        QWidget::resize(event->size().height()/ratio, event->size().height());
    }
    else {
        QWidget::resize(event->size().width(), event->size().width()*ratio);
    }
}
