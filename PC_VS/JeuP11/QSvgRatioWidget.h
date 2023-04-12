#pragma once

#include <QSvgWidget>
#include <QResizeEvent>

class QSvgRatioWidget : public QSvgWidget
{
	Q_OBJECT

public:
	QSvgRatioWidget(int hauteur = 1, int largeur = 1, QWidget *parent = nullptr);
	~QSvgRatioWidget();

private:
	float ratio;

protected:
	virtual void resizeEvent(QResizeEvent* event) Q_DECL_OVERRIDE;
};
