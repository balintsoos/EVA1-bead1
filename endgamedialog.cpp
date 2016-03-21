#include "endgamedialog.h"
#include <QVBoxLayout>

EndGameDialog::EndGameDialog(int steps, QWidget *parent) :
    QDialog(parent)
{
    setFixedSize(300,100);
    setWindowTitle(trUtf8("You Won!"));
    setModal(true);

    _label = new QLabel("You won the game in " + QString::number(steps));

    _closeButton = new QPushButton(trUtf8("Close"));
    _closeButton->setFixedSize(75, 23);

    connect(_closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QVBoxLayout *dialogLayout = new QVBoxLayout();
    dialogLayout->addWidget(_label);
    dialogLayout->addWidget(_closeButton);

    setLayout(dialogLayout);
}
