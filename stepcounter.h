#ifndef STEPCOUNTER_H
#define STEPCOUNTER_H

#include <QLabel>

class StepCounter : public QLabel
{
    Q_OBJECT
public:
    explicit StepCounter(QString message = "Number of steps: ", int steps = 0, QWidget *parent = 0);
    void reset();
    void step();
    void display();

private:
    QString _message;
    int _steps;
};

#endif // STEPCOUNTER_H
