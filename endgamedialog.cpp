#include "endgamedialog.h"

EndGameDialog::EndGameDialog(QString message, int steps, QWidget *parent) :
    _message(message), _steps(steps), QDialog(parent)
{
    setFixedSize(300,120);
    setWindowTitle(trUtf8("You Won!"));
    setModal(true);

    _label = new QLabel();
    updateLabel();

    _newGameButton = new QPushButton(trUtf8("New Game"));
    _newGameButton->setFixedSize(100, 25); // a gombok mérete rögzített
    _quitButton = new QPushButton(trUtf8("Quit"));
    _quitButton->setFixedSize(75, 25);

    connect(_newGameButton, SIGNAL(clicked()), this, SLOT(accept())); // elfogadás állapota
    connect(_quitButton, SIGNAL(clicked()), this, SLOT(reject())); // elvetés állapota

    // timer
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(accept()));
    QLabel *tip = new QLabel("(New game starts after 10 seconds)");

    QVBoxLayout *upperLayout = new QVBoxLayout();
    upperLayout->addWidget(_label, 0, Qt::AlignHCenter);
    upperLayout->addWidget(tip, 0, Qt::AlignHCenter);

    QHBoxLayout *lowerLayout = new QHBoxLayout();
    lowerLayout->addWidget(_newGameButton);
    lowerLayout->addWidget(_quitButton);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(upperLayout);
    mainLayout->addLayout(lowerLayout);

    setLayout(mainLayout);
}

void EndGameDialog::setLabel(QString message)
{
    _message = message;
    updateLabel();
}

void EndGameDialog::setSteps(int steps)
{
    _steps = steps;
    updateLabel();
}

void EndGameDialog::updateLabel()
{
    _label->setText(_message + QString::number(_steps) + " steps");
}

void EndGameDialog::start()
{
    _timer->start(10000);
    exec();
}
