#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>

#include "coordinate.h"
#include "gridpushbutton.h"
#include "gridsizedialog.h"
#include "endgamedialog.h"
#include "stepcounter.h"

class TableWidget : public QWidget
{
    Q_OBJECT

public:
    TableWidget(QWidget *parent = 0);
    ~TableWidget();

private slots: // eseménykezelők
    void clickOnField();
    void resizeGrid(); // rács méretezése
    void setGridSize();

    void addQueen(Coordinate coordinate);
    void removeQueen(Coordinate coordinate);
    void checkEndGame();

private:
    int _gridSize;

    QGridLayout* _gridLayout;
    QVBoxLayout* _vBoxLayout;

    GridSizeDialog* _gridSizeDialog; // méretbeállító ablak
    EndGameDialog* _endGameDialog;

    QPushButton* _newGameButton;
    QPushButton* _sizeButton; // átméretező gomb
    QPushButton* _quitButton; // kilépés gomb

    StepCounter* _stepCounter;

    QVector<GridPushButton*> _buttonGrid; // gombrács

    QVector<Coordinate> _queens;
};

#endif // TABLEWIDGET_H
