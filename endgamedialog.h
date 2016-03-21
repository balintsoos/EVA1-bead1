#ifndef ENDGAMEDIALOG_H
#define ENDGAMEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

class EndGameDialog : public QDialog
{
    Q_OBJECT
public:
    explicit EndGameDialog(int steps, QWidget *parent = 0);

private:
    QLabel *_label;
    QPushButton *_closeButton;
};

#endif // ENDGAMEDIALOG_H
