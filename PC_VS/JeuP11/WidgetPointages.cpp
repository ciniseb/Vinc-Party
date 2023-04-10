/*====================================================================================================
Fichier: Chronometre.h
Auteurs: Antoine Allard
         Charles Beaulieu
         �mile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         S�bastien St-Denis
         Date: 18 mars 2023
Description: UI des pointages
====================================================================================================*/
#include "WidgetPointages.h"

WidgetPointages::WidgetPointages(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

    //Load Background
    background = new QPixmap;
    background->load("Sun.png");

    //Title
    titlelabel = new QLabel(this);
    titlelabel->setAlignment(Qt::AlignCenter);
    titlelabel->setText("Classement");
    QFont timerFont("Consolas", 40, QFont::Bold);
    titlelabel->setFont(timerFont);
    titlelabel->setStyleSheet("color: black;"
        "background-color: green;"
        "selection-color: black;"
        "selection-background-color: black;"
        "border: 5px solid black;"
        "border-radius: 10px;"
        "padding: 10px;");


}

WidgetPointages::~WidgetPointages()
{}

void WidgetPointages::updateTitleLabelFontSize()
{
    int fontSize = width() / 50;
    QFont font = titlelabel->font();
    font.setPointSize(fontSize);
    titlelabel->setFont(font);
}


void WidgetPointages::paintEvent(QPaintEvent* event)
{
    /////Main Section/////
    QPainter painter(this);


    /////background/////
    qreal targetAspectRatio = qreal(width()) / qreal(height());
    qreal sourceAspectRatio = qreal(background->width()) / qreal(background->height());

    int cropWidth;
    int cropHeight;

    if (targetAspectRatio > sourceAspectRatio)
    {
        cropWidth = background->width();
        cropHeight = int(cropWidth / targetAspectRatio);
    }
    else
    {
        cropHeight = background->height();
        cropWidth = int(cropHeight * targetAspectRatio);
    }

    int cropX = (background->width() - cropWidth) / 2;
    int cropY = (background->height() - cropHeight) / 2;

    QPixmap cropped_background = background->copy(cropX, cropY, cropWidth, cropHeight);
    QPixmap scaled_background = cropped_background.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    painter.drawPixmap(0, 0, scaled_background);


    /////title/////
    int titleLabelWidth = width() * 1 / 2;
    int titleLabelHeight = height() * 1 / 8;
    titlelabel->resize(titleLabelWidth, titleLabelHeight);
    titlelabel->move((width() - titleLabelWidth) / 2, (height() - titleLabelHeight) *0.02);
    updateTitleLabelFontSize();
}