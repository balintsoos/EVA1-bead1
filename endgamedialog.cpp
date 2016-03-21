#include "endgamedialog.h"
#include <QVBoxLayout>

EndGameDialog::EndGameDialog(QString message, int steps, QWidget *parent) :
    _message(message), _steps(steps), QDialog(parent)
{
    setFixedSize(300,100);
    setWindowTitle(trUtf8("You Won!"));
    setModal(true);

    _label = new QLabel();
    updateLabel();

    _closeButton = new QPushButton(trUtf8("Close"));
    _closeButton->setFixedSize(75, 23);
    connect(_closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QVBoxLayout *dialogLayout = new QVBoxLayout();
    dialogLayout->addWidget(_label, 0, Qt::AlignHCenter);
    dialogLayout->addWidget(_closeButton, 0, Qt::AlignRight);

    setLayout(dialogLayout);
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
