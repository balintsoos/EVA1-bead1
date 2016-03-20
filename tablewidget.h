#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QTimer>

#include "coordinate.h"
#include "gridpushbutton.h"
#include "gridsizedialog.h"

class TableWidget : public QWidget
{
    Q_OBJECT

public:
    TableWidget(QWidget *parent = 0);
    ~TableWidget();

private slots: // eseménykezelők
    void startColorChange(); // időzítő indítása
    void resizeGrid(); // rács méretezése
    void changeColors(); // időzített átszínezés

private:
    QGridLayout* _gridLayout;
    QVBoxLayout* _vBoxLayout;

    GridSizeDialog* _gridSizeDialog; // méretbeállító ablak

    QPushButton* _sizeButton; // átméretező gomb
    QPushButton* _quitButton; // kilépés gomb

    QVector<GridPushButton*> _buttonGrid; // gombrács
    QMap<QTimer*, Coordinate> _timers; // időzítők (koordinátákhoz társítva)
};

#endif // TABLEWIDGET_H
