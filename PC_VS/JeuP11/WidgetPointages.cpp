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
Description: UI des pointages
====================================================================================================*/
#include "WidgetPointages.h"

WidgetPointages::WidgetPointages(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

    nameVector = new QVector<std::string>;
    levelVector = new QVector<int>;
    timeVector = new QVector<double>;
    buttonLayouts = new QList<QHBoxLayout*>;
    timelevelVector = new QVector<double>;
    distanceVector = new QVector<int>;



    //Load Background
    background = new QPixmap;
    background->load("fen.png");

    //Title
    titlelabel = new QLabel(this);
    titlelabel->setAlignment(Qt::AlignCenter);
    titlelabel->setText("Classement - Temps");
    QFont timerFont("Consolas", 40, QFont::Bold);
    titlelabel->setFont(timerFont);
    titlelabel->setStyleSheet("color: black;"
        "background-color: papayawhip;"
        "selection-color: black;"
        "selection-background-color: black;"
        "border: 5px solid black;"
        "border-radius: 10px;"
        "padding: 10px;");

    /////Leaderboard/////
    footprint = new QRect(width() * 0.1, height() * 0.2, width() * 0.8, height() * 0.75);
    layout = new QGridLayout(this);

    int numRows = 2;
    int numCols = 3;

    for (int i = 0; i < numButtons; ++i)
    {
        button = new QPushButton(this);
        QFont buttonFont("Arial", 20);
        button->setFont(buttonFont);
        //button->setStyleSheet("background-color: rgba(135, 206, 250, 127);");
        button->setFixedSize(QSize(footprint->width() * 10, 60));
        button->setCursor(Qt::PointingHandCursor);

        QHBoxLayout* buttonLayout = new QHBoxLayout(button);
        QLabel* indexLabel = new QLabel();
        QLabel* nameLabel = new QLabel();

        indexLabel->setAlignment(Qt::AlignCenter);

        buttonLayout->addWidget(indexLabel);
        buttonLayout->addWidget(nameLabel);
        buttonLayouts->append(buttonLayout);
        layout->addWidget(button);
    }


    playerCardLabel = new QLabel(this);
    playerCardLabel->setAlignment(Qt::AlignTop);
    //playerCardLabel->setStyleSheet("background-color: white; border: 3px solid black; border-radius: 10px; padding: 15px;");
    playerCardLabel->setVisible(false);


    ///rules
    // Add control instructions label
    rulesLabel = new QLabel(this);
    if(MODE_CLAVIER)
    { 
        rulesLabel->setText("Z - Menu \nX - Mode distance/temps \nEnter - Carte du joueur");\

    }
    else
    {
        rulesLabel->setText("D - Menu \nI - Mode distance/temps \nJOYSTICK - Carte du joueur");\
    }
    QFont rulesFont("Arial", 12);
    rulesLabel->setFont(rulesFont);
    rulesLabel->setStyleSheet("color: black;");
    rulesLabel->setGeometry(10, height(), 400, 50);




    ///Connect
    connect(threadMoteur, SIGNAL(Pointages_Right()), this, SLOT(right()));
    connect(threadMoteur, SIGNAL(Pointages_Left()), this, SLOT(left()));
    connect(threadMoteur, SIGNAL(Pointages_Up()), this, SLOT(up()));
    connect(threadMoteur, SIGNAL(Pointages_Down()), this, SLOT(down()));
    connect(threadMoteur, SIGNAL(Pointage_Select()), this, SLOT(select()));
    connect(threadMoteur, &ThreadMoteur::Pointages_Names, this, &WidgetPointages::names);
    connect(threadMoteur, &ThreadMoteur::Pointages_Level, this, &WidgetPointages::level);
    connect(threadMoteur, &ThreadMoteur::Pointages_Time, this, &WidgetPointages::time);
    connect(threadMoteur, &ThreadMoteur::Pointages_TimePerLev, this, &WidgetPointages::timeperlev);
    connect(threadMoteur, &ThreadMoteur::Pointages_Distance, this, &WidgetPointages::distance);
    connect(threadMoteur, SIGNAL(switchmode()), this, SLOT(switchmode()));

    

    updateButtons();
    selectButton(0);

}

WidgetPointages::~WidgetPointages()
{
    delete titlelabel;
    delete footprint;
    delete button;
    delete background;
    delete buttonLayouts;
    delete rulesLabel;
}

void WidgetPointages::distance(int distance)
{
    distanceVector->append(distance);
}
void WidgetPointages::timeperlev(double time)
{
    timelevelVector->append(time);
}
void WidgetPointages::time(double time)
{
    timeVector->append(time);
}
void WidgetPointages::level(int level)
{
    levelVector->append(level);
    updateButtons();
}

void WidgetPointages::names(const std::string& playerName)
{
    nameVector->append(playerName);
    updateButtons();
}

void WidgetPointages::right()
{
    if (playerCard)
    {
        return;
    }

    maxPage();
    if (currentPage == 9)
    {
        currentPage = 9;
    }
    if (currentPage == maxPages)
    {
        currentPage = maxPages;
    }
    else
    currentPage++;
    updateButtons();
}

void WidgetPointages::left()
{
    if (playerCard)
    {
        return;
    }

    if (currentPage == 0)
    {
        currentPage = 0;
    }
    else
    currentPage--;
    updateButtons();
}

void WidgetPointages::up()
{
    if (playerCard)
    {
        return; 
    }

    int newIndex = selectedButtonIndex - 1;
    if (newIndex >= 0 && newIndex < numButtons)
    {
        selectButton(newIndex);
    }
    else if (newIndex == -1)
    {
        if (currentPage == 0)
        {
            selectButton(0); 
        }
        else
        {
            currentPage--;
            updateButtons();
            selectButton(4);
        }
    }
}

void WidgetPointages::down()
{
    if (playerCard)
    {
        return;
    }

    maxPage();
    int newIndex = selectedButtonIndex + 1;
    int lastIndex = nameVector->size() - (currentPage * numButtons);

    if (newIndex < numButtons && newIndex < lastIndex)
    {
        selectButton(newIndex);
    }
    else if (newIndex == numButtons)
    {
        if (currentPage == maxPages)
        {
            currentPage = maxPages;
        }
        else
        {
            currentPage++;
            updateButtons();
            selectButton(0);
        }
    }
}


void WidgetPointages::switchmode()
{
    if (!sortByDistancebool)
    {        
        titlelabel->setText("Classement - Distance");
        sortByDistancebool = true;
        sortByDistance();
    }
    else
    {
        titlelabel->setText("Classement - Temps");
        sortByDistancebool = false;
        sortByTimePerLevel();
    }
}
int WidgetPointages::maxPage()
{
    maxPages = static_cast<int>(ceil(static_cast<double>(nameVector->size()) / numButtons) - 1);
    return maxPages;
}


void WidgetPointages::select()
{
    if (!playerCard)
    {
        playerCard = true;
    }
    else
    {
        playerCard = false;
    }
    updatePlayerCard(); 
}



void WidgetPointages::selectButton(int index)
{
    std::cout << index;

    if (index >= 0 && index < numButtons)
    {
        QPushButton* oldButton = qobject_cast<QPushButton*>(layout->itemAt(selectedButtonIndex)->widget());
        oldButton->setStyleSheet("background-color: rgba(255, 255, 255, 127); border: 1px solid black;border-radius: 10px;");

        selectedButtonIndex = index;
        QPushButton* currentButton = qobject_cast<QPushButton*>(layout->itemAt(selectedButtonIndex)->widget());
        currentButton->setStyleSheet("background-color: rgba(200, 200, 200, 127); border: 1px solid black;border-radius: 10px;");

        QHBoxLayout* buttonLayout = buttonLayouts->at(selectedButtonIndex);
        QLabel* indexLabel = qobject_cast<QLabel*>(buttonLayout->itemAt(0)->widget());
    }
    indexUpdate(index);
}

int WidgetPointages::indexUpdate(int index)
{
    currentIndex = (currentPage  * 5) + index;
    return currentIndex;
}

void WidgetPointages::updateButtons()
{
    int startIndex = currentPage * numButtons;

    for (int i = 0; i < numButtons; ++i)
    {
        QHBoxLayout* buttonLayout = buttonLayouts->at(i);

        QLabel* indexLabel = qobject_cast<QLabel*>(buttonLayout->itemAt(0)->widget());
        QLabel* nameLabel = qobject_cast<QLabel*>(buttonLayout->itemAt(1)->widget());

        int vectorIndex = startIndex + i;
        QPushButton* currentButton = qobject_cast<QPushButton*>(layout->itemAt(i)->widget());

        if (vectorIndex < nameVector->size() && vectorIndex < timeVector->size())
        {
            QString playerName = QString::fromStdString(nameVector->at(vectorIndex));
            double playerTime = timeVector->at(vectorIndex);
            indexLabel->setText(QString("%1").arg(vectorIndex + 1));
            nameLabel->setText(playerName);

            indexLabel->setStyleSheet("color: black; background-color: transparent; border: none;");
            nameLabel->setStyleSheet("color: black; background-color: transparent; border: none;");

            currentButton->setVisible(true);
        }
        else
        {
            indexLabel->setText("");
            nameLabel->setText("");

            currentButton->setVisible(false);
        }

        if (i == selectedButtonIndex)
        {
            if (vectorIndex < nameVector->size() && vectorIndex < timeVector->size())
            {
                currentButton->setStyleSheet("background-color: rgba(255, 255, 255, 127); border: 1px solid black;border-radius: 10px;");
            }
            else
            {
                currentButton->setStyleSheet("background-color: transparent; border-image: none;");
            }
        }
        else
        {
            if (vectorIndex < nameVector->size() && vectorIndex < timeVector->size())
            {
                currentButton->setStyleSheet("background-color: rgba(255, 255, 255, 127); border: 1px solid black;border-radius: 10px;");
            }
            else
            {
                currentButton->setStyleSheet("background-color: transparent; border-image: none;");
            }
        }

        updateButtonFontSizes();
    }
}



void WidgetPointages::updatePlayerCard()
{
    if (playerCard)
    {
        QString playerName = QString::fromStdString(nameVector->at(currentIndex));
        int playerLevel = levelVector->at(currentIndex);
        double playerTime = timeVector->at(currentIndex);
        double playerTimePerLevel = timelevelVector->at(currentIndex);
        int playerDistance = distanceVector->at(currentIndex);
        playerCardLabel->setText(QString("%1\n\n\tNiveau atteint: %2\n\tTemps: %3\n\tTemps par niveau: %4\n\tDistance parcourue: %5").arg(playerName).arg(playerLevel).arg(playerTime).arg(playerTimePerLevel).arg(playerDistance));

        playerCardLabel->setStyleSheet("color: black;"
            "background-color: peachpuff;"
            "selection-color: black;"
            "selection-background-color: black;"
            "border: 5px solid black;"
            "border-radius: 10px;"
            "padding: 10px;");

        int cardWidth = width() / 2;
        int cardHeight = height() * 0.5;
        playerCardLabel->resize(cardWidth, cardHeight);
        playerCardLabel->move((width() - cardWidth) / 2, (height() - cardHeight) * 0.6);

        int fontSize = width() / 45;
        QFont font("Arial", fontSize);
        playerCardLabel->setFont(font);

        playerCardLabel->setVisible(true);
    }
    else
    {
        playerCardLabel->setVisible(false);
    }
}

void WidgetPointages::sortByDistance()
{
    QVector<int> sortedIndices(nameVector->size());
    std::iota(sortedIndices.begin(), sortedIndices.end(), 0);

    std::sort(sortedIndices.begin(), sortedIndices.end(), [this](int a, int b) {
        if (levelVector->at(a) == levelVector->at(b))
        {
            return distanceVector->at(a) < distanceVector->at(b);
        }
        return levelVector->at(a) > levelVector->at(b);
        });

    QVector<std::string> sortedNames = *nameVector;
    QVector<int> sortedLevels = *levelVector;
    QVector<double> sortedTimes = *timeVector;
    QVector<double> sortedTimePerLevels = *timelevelVector;
    QVector<int> sortedDistances = *distanceVector;

    for (int i = 0; i < sortedIndices.size(); ++i)
    {
        int index = sortedIndices[i];
        sortedNames[i] = nameVector->at(index);
        sortedLevels[i] = levelVector->at(index);
        sortedTimes[i] = timeVector->at(index);
        sortedTimePerLevels[i] = timelevelVector->at(index);
        sortedDistances[i] = distanceVector->at(index);
    }

    *nameVector = sortedNames;
    *levelVector = sortedLevels;
    *timeVector = sortedTimes;
    *timelevelVector = sortedTimePerLevels;
    *distanceVector = sortedDistances;

    updateButtons();
}

void WidgetPointages::sortByTimePerLevel()
{
    QVector<int> sortedIndices(nameVector->size());
    std::iota(sortedIndices.begin(), sortedIndices.end(), 0);

    std::sort(sortedIndices.begin(), sortedIndices.end(), [&](int i, int j)
        {
            if (levelVector->at(i) == levelVector->at(j))
            {
                return timeVector->at(i) / levelVector->at(i) < timeVector->at(j) / levelVector->at(j);
            }
            return levelVector->at(i) > levelVector->at(j);
        });

    QVector<std::string> sortedNames(*nameVector);
    QVector<int> sortedLevels(*levelVector);
    QVector<double> sortedTimes(*timeVector);
    QVector<double> sortedTimePerLevel(*timelevelVector);
    QVector<int> sortedDistances(*distanceVector);

    for (int i = 0; i < nameVector->size(); ++i)
    {
        sortedNames[i] = nameVector->at(sortedIndices[i]);
        sortedLevels[i] = levelVector->at(sortedIndices[i]);
        sortedTimes[i] = timeVector->at(sortedIndices[i]);
        sortedTimePerLevel[i] = timelevelVector->at(sortedIndices[i]);
        sortedDistances[i] = distanceVector->at(sortedIndices[i]);
    }

    *nameVector = sortedNames;
    *levelVector = sortedLevels;
    *timeVector = sortedTimes;
    *timelevelVector = sortedTimePerLevel;
    *distanceVector = sortedDistances;

    updateButtons();
}



void WidgetPointages::updateButtonFontSizes()
{
    buttonFontSize = width() / 50; 
    QFont labelFont("Arial", buttonFontSize);

    for (int i = 0; i < numButtons; ++i)
    {
        QHBoxLayout* buttonLayout = buttonLayouts->at(i);

        QLabel* indexLabel = qobject_cast<QLabel*>(buttonLayout->itemAt(0)->widget());
        QLabel* nameLabel = qobject_cast<QLabel*>(buttonLayout->itemAt(1)->widget());

        indexLabel->setFont(labelFont);
        nameLabel->setFont(labelFont);
    }
}



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
    titlelabel->move((width() - titleLabelWidth) / 2, (height() - titleLabelHeight) *0.05);
    updateTitleLabelFontSize();

    /////Leaderboard/////
    footprint->setRect(width()*0.1, height() * 0.2, width() * 0.8, height() * 0.75);
    layout->setGeometry(*footprint);
    updateButtonFontSizes();

    updatePlayerCard();
}

