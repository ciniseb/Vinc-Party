/*====================================================================================================
Fichier: WidgetJeuPiano.cpp
Auteurs: Antoine Allard
         Charles Beaulieu
         Émile Bois
         Enes Caku
         Zachari Gervais
         Anne-Sophie Nguyen
         Sébastien St-Denis
         Date: 18 mars 2023
Description: UI du piano
====================================================================================================*/
#include "WidgetJeuPiano.h"

WidgetJeuPiano::WidgetJeuPiano(ThreadMoteur* thread, QWidget* parent) : QWidget(parent)
{
    threadMoteur = thread;

    //Load Background
    background = new QPixmap;
    background->load("background_Piano.png");

    // Load note images
    bleu.load("bleu.png");
    orange.load("orange.png");
    vert.load("vert.png");
    rouge.load("rouge.png");

    // Resize note images
    int newWidth = 100; // Largeur souhaitée
    int newHeight = 100; // Hauteur souhaitée

    vert = vert.scaled(newWidth, newHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    rouge = rouge.scaled(newWidth, newHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    bleu = bleu.scaled(newWidth, newHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    orange = orange.scaled(newWidth, newHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    timer = new QTimer(this);
    timer->start(1000 / 60); // 60 FPS
    
    Demarrage();

    //Connexions
    connect(threadMoteur, &ThreadMoteur::AjoutNote, this, &WidgetJeuPiano::Ajout_Note);
    connect(threadMoteur, &ThreadMoteur::Update_score, this, &WidgetJeuPiano::Update_score);
    connect(timer, &QTimer::timeout, this, &WidgetJeuPiano::updateNotes);
    connect(threadMoteur, &ThreadMoteur::Demarrage_WidgetPiano, this, &WidgetJeuPiano::Demarrage);
}

WidgetJeuPiano::~WidgetJeuPiano()
{
    // Arrêtez et supprimez le QTimer
    if (timer)
    {
        timer->stop();
        delete timer;
        timer = nullptr;
    }

    // Supprimez le QPixmap pour le fond d'écran
    if (background)
    {
        delete background;
        background = nullptr;
    }
}

void WidgetJeuPiano::Demarrage()
{
    infoStaticText.setTextFormat(Qt::RichText);
    infoText = "Bienvenue dans le jeu du piano du diable! \n Appuyez su D, I, E, U pour commencer \n \n Pour gagner, Appuyez quand la lumiere de la manette est jaune";
    firstNoteAppeared = false;
    score = 0;
}

void WidgetJeuPiano::paintEvent(QPaintEvent* event)
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

    scaleFactor = qreal(scaled_background.width()) / qreal(background->width());
    
    //Notes

    for (const Note& note : notes) 
    {
        painter.drawPixmap(note.x, note.y, note.image);
    }

    // Dessine le texte du score
    QFont font("Arial", 20, QFont::Bold); // Choisissez la police, la taille et le style
    painter.setFont(font);
    painter.setPen(Qt::white); // Choisissez la couleur du texte
    QString scoreText = QString("Score: %1").arg(score); 
    painter.drawText(10, 30, scoreText); // Choisissez la position du texte

    // Dessine le texte d'information
    QFont infoFont("Arial", 20, QFont::Bold);
    painter.setFont(infoFont);
    painter.setPen(Qt::white);
    painter.drawText(QRect(0, 0, width(), height()), Qt::AlignCenter, infoText.replace("<br>", "\n"));

}

void WidgetJeuPiano::Update_score(int newscore)
{
    score = newscore;
    update();
}

void WidgetJeuPiano::Ajout_Note(int note)
{
    //qDebug() << "Ajout_Note() called with note:" << note;
    Note newNote;
    if (!firstNoteAppeared)
    {
        infoText = " ";
        firstNoteAppeared = true;
    }
    switch (note)
    {
    case 1: //Vert
        newNote.image = vert.scaled(vert.width() * scaleFactor, vert.height() * scaleFactor, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        newNote.x = width() * 0.2;
        newNote.y = 0;
        newNote.noteType = 1;
        break;
    case 2: //Rouge
        newNote.image = rouge.scaled(rouge.width() * scaleFactor, rouge.height() * scaleFactor, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        newNote.x = width() * 0.4;
        newNote.y = 0;
        newNote.noteType = 2;
        break;
    case 3: //Bleu
        newNote.image = bleu.scaled(bleu.width() * scaleFactor, bleu.height() * scaleFactor, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        newNote.x = width() * 0.6;
        newNote.y = 0;
        newNote.noteType = 3;
        break;
    case 4: //Orange
        newNote.image = orange.scaled(orange.width() * scaleFactor, orange.height() * scaleFactor, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        newNote.x = width() * 0.8;
        newNote.y = 0;
        newNote.noteType = 4;
        break;
    }
    newNote.initialY = 0; // Ajoutez cette ligne
    newNote.initialHeight = height();
    newNote.creationTime = QDateTime::currentMSecsSinceEpoch(); 
    notes.append(newNote);
    update();
}

void WidgetJeuPiano::updateNotes()
{
    const int fallDurationMs = 4000; 
    const int fallDistance = height(); // Fall to the bottom of the window
    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();

    // Move notes down
    for (Note& note : notes)
    {
        qreal progress = qreal(currentTime - note.creationTime) / fallDurationMs;
        qreal newY = note.initialY + progress * (note.initialHeight - note.initialY);
        note.y = newY * (height() / note.initialHeight);
        
        if (note.noteType == 1) // Vert
        {
            note.image = vert.scaled(vert.width() * scaleFactor, vert.height() * scaleFactor, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            note.x = width() * 0.2;
        }
        else if (note.noteType == 2) // Rouge
        {
            note.image = rouge.scaled(rouge.width() * scaleFactor, rouge.height() * scaleFactor, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            note.x = width() * 0.4;
        }
        else if (note.noteType == 3) // Bleu
        {
            note.image = bleu.scaled(bleu.width() * scaleFactor, bleu.height() * scaleFactor, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            note.x = width() * 0.6;
        }
        else if (note.noteType == 4) // Orange
        {
            note.image = orange.scaled(orange.width() * scaleFactor, orange.height() * scaleFactor, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            note.x = width() * 0.8;
        }
    }

    // Remove notes that reached the bottom
    notes.erase(std::remove_if(notes.begin(), notes.end(),
        [this](const Note& note) { return note.y >= this->height(); }),
        notes.end());

    // Trigger a paint event to redraw the notes
    update();
}

