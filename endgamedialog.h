#ifndef ENDGAMEDIALOG_H
#define ENDGAMEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

class EndGameDialog : public QDialog
{
    Q_OBJECT
public:
    explicit EndGameDialog(QString message = "You won the game in ", int steps = 0, QWidget *parent = 0);
    void setLabel(QString message);
    void setSteps(int steps);

private:
    void updateLabel();

    int _steps;
    QString _message;
    QLabel *_label;
    QPushButton *_newGameButton;
    QPushButton *_quitButton;
};

#endif // ENDGAMEDIALOG_H
