/*====================================================================================================
Fichier: Chronometre.h
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 18 mars 2023
Description: UI du mineur
====================================================================================================*/
#include "WidgetJeuMineur.h"


WidgetJeuMineur::WidgetJeuMineur(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
	threadMoteur = thread;
    mine_background = new QPixmap;
    block_shape= new QPixmap;
    ///////Mine Layout Section///////
    // Load the mood
    mine_background->load("Background_Mine1.png");

    shapes = { "block1.png", "block2.png", "block3.png", "block4.png", "block5.png", "block6.png"};
    block_shape->load(shapes[0]);
    block_rect = QRect((width() - block_shape->width()) / 2, (height() - block_shape->height()) / 2,block_shape->width(), block_shape->height());

    //Shake it up!
    shakeAnimation = new QPropertyAnimation(this, "blockRect");
    setFocusPolicy(Qt::StrongFocus);

    ///////Timer Section///////
    timerStarted = false;
    countdownLabel = new QLabel(this);
    countdownLabel->setAlignment(Qt::AlignCenter);

    countdownTimer = new QTimer(this);
    countdownTimer->setInterval(1000); 

    QFont timerFont("Consolas", 20, QFont::Bold);
    countdownLabel->setFont(timerFont);
    countdownLabel->setStyleSheet("color: black;"
        "background-color: green;"
        "selection-color: black;"
        "selection-background-color: black;"
        "border: 5px solid black;"
        "border-radius: 10px;"
        "padding: 10px;");
    countdownLabel->hide();

    ///////Rules Section///////
    rulesLabel = new QLabel(this);
    if (MODE_CLAVIER)
    {
        rulesLabel->setText("<html><head/><body><p><b>Regle Du Mini-Jeu:<br/></b>Appuyer sur H et B pour Miner le block!<br/>Attention, vous n'avez pas beaucoup de temps...");
    }
    else
        rulesLabel->setText("<html><head/><body><p><b>Regle Du Mini-Jeu:<br/></b>Donner un coup vers le haut et vers le bas pour Miner le block!<br/>Attention, vous n'avez pas beaucoup de temps...");

    rulesLabel->setAlignment(Qt::AlignCenter);
    rulesLabel->setWordWrap(false);
    rulesLabel->setStyleSheet("color: black;"
        "background-color: burlywood;"
        "selection-color: black;"
        "selection-background-color: black;"
        "border: 5px solid black;"
        "border-radius: 10px;"
        "padding: 10px;");


    ///////Connexions///////
    connect(threadMoteur, SIGNAL(jeuMineur_block(float)), this, SLOT(blockUpadate(float)));
    connect(threadMoteur, SIGNAL(jeuMineur_menu()), this, SLOT(debut()));
    connect(countdownTimer, SIGNAL(timeout()), this, SLOT(updateCountdown()));
    connect(threadMoteur, SIGNAL(jeuMineur_timer(int)), this, SLOT(timer(int)));

}

void WidgetJeuMineur::blockUpadate(float pourcentage)
{
    if (pourcentage <= 100 * (1 / 5.0))
    {
        block_shape->load(shapes[0]);
    }
    else if (pourcentage <= 100 * (2 / 5.0))
    {
        block_shape->load(shapes[1]);
    }
    else if (pourcentage <= 100 * (3 / 5.0))
    {
        block_shape->load(shapes[2]);
    }
    else if (pourcentage <= 100 * (4 / 5.0))
    {
        block_shape->load(shapes[3]);
    }
    else if (pourcentage < 98)
    {
        block_shape->load(shapes[4]);
    }
    else
    {
        block_shape->load(shapes[5]);
        countdownTimer->stop();
    }

    if (!timerStarted) {
        countdownLabel->show();
        countdownTimer->start();
        timerStarted = true;
    }
    rulesLabel->hide();
    startShakingAnimation();
    update();
}


void WidgetJeuMineur::debut()
{

}

void WidgetJeuMineur::updateCountdownLabel() 
{
    countdownLabel->setText(QString::number(countdownTime));
}

void WidgetJeuMineur::updateCountdown() 
{
    countdownTime--;
    updateCountdownLabel();

    if (countdownTime == 6)
    {
        countdownLabel->setStyleSheet("color: black;"
            "background-color: yellow;"
            "selection-color: black;"
            "selection-background-color: black;"
            "border: 5px solid black;"
            "border-radius: 10px;"
            "padding: 10px;");
    }
    else if(countdownTime == 3)
    {
        countdownLabel->setStyleSheet("color: black;"
            "background-color: red;"
            "selection-color: black;"
            "selection-background-color: black;"
            "border: 5px solid black;"
            "border-radius: 10px;"
            "padding: 10px;");
    }
    if (countdownTime <= 0) 
    {
        countdownTimer->stop();
    }
}

void WidgetJeuMineur::showEvent(QShowEvent* event) 
{
    QWidget::showEvent(event);
}

int WidgetJeuMineur::timer(int maxVal)
{
    countdownTime = maxVal;
    return countdownTime;
}

void WidgetJeuMineur::updateTimerLabelFontSize()
{
    int fontSize = width() / 75;
    QFont font = countdownLabel->font();
    font.setPointSize(fontSize);
    countdownLabel->setFont(font);
}
void WidgetJeuMineur::updateRulesLabelFontSize() 
{
    int fontSize = width() / 125; 
    QFont font = rulesLabel->font();
    font.setPointSize(fontSize);
    rulesLabel->setFont(font);
}


WidgetJeuMineur::~WidgetJeuMineur()
{
    delete mine_background;
    delete block_shape;
    delete shakeAnimation;
    delete rulesLabel;
    delete countdownLabel;
    delete countdownTimer;
}

QRect WidgetJeuMineur::blockRect() const 
{
    return block_rect;
}

void WidgetJeuMineur::setBlockRect(const QRect& rect) 
{
    if (block_rect != rect) {
        block_rect = rect;
        emit blockRectChanged();
        update();
    }
}


void WidgetJeuMineur::startShakingAnimation()
{
    shakeAnimation->stop(); 

    shakeAnimation->setDuration(100);
    shakeAnimation->setLoopCount(1);
    shakeAnimation->setEasingCurve(QEasingCurve::InOutSine);

    shakeAnimation->setKeyValueAt(0, block_rect);
    shakeAnimation->setKeyValueAt(0.25, block_rect.adjusted(-10, 0, -10, 0));
    shakeAnimation->setKeyValueAt(0.5, block_rect);
    shakeAnimation->setKeyValueAt(0.75, block_rect.adjusted(10, 0, 10, 0));
    shakeAnimation->setKeyValueAt(1, block_rect);

    shakeAnimation->start();
}


void WidgetJeuMineur::paintEvent(QPaintEvent* event)
{
    /////Main Section/////
    QPainter painter(this);

    qreal targetAspectRatio = qreal(width()) / qreal(height());

    qreal sourceAspectRatio = qreal(mine_background->width()) / qreal(mine_background->height());

    int cropWidth;
    int cropHeight;

    if (targetAspectRatio > sourceAspectRatio) 
    {
        cropWidth = mine_background->width();
        cropHeight = int(cropWidth / targetAspectRatio);
    }
    else 
    {
        cropHeight = mine_background->height();
        cropWidth = int(cropHeight * targetAspectRatio);
    }

    int cropX = (mine_background->width() - cropWidth) / 2;
    int cropY = (mine_background->height() - cropHeight) / 2;

    QPixmap cropped_background = mine_background->copy(cropX, cropY, cropWidth, cropHeight);

    QPixmap scaled_background = cropped_background.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    painter.drawPixmap(0, 0, scaled_background);

    QPixmap scaled_shape = block_shape->scaled(block_rect.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(block_rect, scaled_shape);


    //Rules section
    int rulesLabelWidth = width() * 1 / 3;
    int rulesLabelHeight = height() * 1 / 8;
    rulesLabel->resize(rulesLabelWidth, rulesLabelHeight);
    rulesLabel->move((width() - rulesLabelWidth) / 2, (height() - rulesLabelHeight) -40);
    updateRulesLabelFontSize();

    //timer Section
    int timerLabelWidth = width()* 1/14;
    int timerLabelheight = height() * 1/8;
    countdownLabel->resize(timerLabelWidth, timerLabelheight);
    countdownLabel->move(width() - 20 - countdownLabel->width() - 10, 10);
    updateTimerLabelFontSize();
}



void WidgetJeuMineur::resizeEvent(QResizeEvent* event) 
{
    // Update the block
    int block_width = width() / 3 *1.2;
    int block_height = height() / 2 *1.2;
    block_rect = QRect((width() - block_width) / 2, (height() - block_height) / 2, block_width, block_height);

    QWidget::resizeEvent(event);
}