#ifndef ENDGAMEDIALOG_H
#define ENDGAMEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QTimer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class EndGameDialog : public QDialog
{
    Q_OBJECT
public:
    explicit EndGameDialog(QString message = "You won the game in ", int steps = 0, QWidget *parent = 0);
    void setLabel(QString message);
    void setSteps(int steps);
    void start();

private:
    void updateLabel();

    int _steps;
    QString _message;
    QLabel *_label;
    QPushButton *_newGameButton;
    QPushButton *_quitButton;

    QTimer *_timer;
};

#endif // ENDGAMEDIALOG_H
