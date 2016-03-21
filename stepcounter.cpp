#include "stepcounter.h"

StepCounter::StepCounter(QString message, int steps, QWidget *parent) :
    _message(message), _steps(steps), QLabel(parent)
{

}

void StepCounter::reset()
{
    _steps = 0;
    display();
}

void StepCounter::step()
{
    _steps++;
    display();
}

void StepCounter::display()
{
    setText(_message + QString::number(_steps));
}

int StepCounter::getSteps()
{
    return _steps;
}
