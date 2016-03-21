#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>

#include "coordinate.h"
#include "gridpushbutton.h"
#include "gridsizedialog.h"
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

    void addQueen(Coordinate coordinate);
    void removeQueen(Coordinate coordinate);
    void checkEndGame();

private:
    QGridLayout* _gridLayout;
    QVBoxLayout* _vBoxLayout;

    GridSizeDialog* _gridSizeDialog; // méretbeállító ablak

    QPushButton* _sizeButton; // átméretező gomb
    QPushButton* _quitButton; // kilépés gomb
    StepCounter* _stepCounter;

    QVector<GridPushButton*> _buttonGrid; // gombrács

    QVector<Coordinate> _queens;
};

#endif // TABLEWIDGET_H
