#include "tablewidget.h"

#include <QTime>
#include <QTimerEvent>
#include <QApplication>

TableWidget::TableWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(trUtf8("Queens Game"));

    _gridSizeDialog = new GridSizeDialog();
    connect(_gridSizeDialog, SIGNAL(accepted()), this, SLOT(resizeGrid())); // átméretezés a dialógus elfogadására

    _sizeButton = new QPushButton(trUtf8("New Game"));
    connect(_sizeButton, SIGNAL(clicked()), _gridSizeDialog, SLOT(exec())); // méretező ablak megjelenítése gombnyomásra

    _quitButton = new QPushButton(trUtf8("Quit"));
    connect(_quitButton, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));

    _vBoxLayout = new QVBoxLayout();
    _vBoxLayout->addWidget(_sizeButton);
    _vBoxLayout->addWidget(_quitButton);

    _gridLayout = new QGridLayout();
    _vBoxLayout->addLayout(_gridLayout);

    setLayout(_vBoxLayout);

    qsrand(QTime::currentTime().msec());
       // véletlenszám generátor indítása
}

TableWidget::~TableWidget()
{
    delete _gridSizeDialog;
}

void TableWidget::changeColors()
{
    QString styleSheet = "QPushButton { background-color: red; }"; // stílus beállítása

    // megkeressük, melyik koordinátán kell módosítani a színeket
    Coordinate coordinate = _timers[qobject_cast<QTimer*>(sender())];

    // megkeressük az átszínezendő gombokat
    foreach(GridPushButton* buttonToChange, _buttonGrid)
    {
       if (buttonToChange->coordinate().x() == coordinate.x() ||
           buttonToChange->coordinate().y() == coordinate.y())
       {
           // az adott sorban és oszlopban
           buttonToChange->setStyleSheet((styleSheet));
           // lecseréljük az összes gomb megjelenését
       }
    }
}

void TableWidget::startColorChange()
{
    // szükségünk van a küldő gomb koordinátájára
    GridPushButton *button = qobject_cast<GridPushButton*>(sender());
    Coordinate coordinate = button->coordinate();

    // létrehozunk egy új időzítőt, amit azonnal el is indítunk
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeColors()));
    timer->start(1000);

    // és elmentünk a megadott koordinátával
    _timers.insert(timer, coordinate);
}

void TableWidget::resizeGrid()
{
    // előbb le kell állítanunk az összes időzítőt
    foreach(QTimer* timer, _timers.keys())
    {
        timer->stop();
        _timers.remove(timer); // töröljük a tömbből
        delete timer; // töröljük az objektumot
    }


    // majd törölnünk kell az összes gombot
    foreach(GridPushButton* button, _buttonGrid)
    {
        _gridLayout->removeWidget(button); // levétel az elrendezésről
        delete button; // vezérlő törlése
    }

    _buttonGrid.clear(); // mutatók törlése

    for (int i = 0; i < _gridSizeDialog->gridSize(); ++i) {
        for (int j = 0; j < _gridSizeDialog->gridSize(); ++j){
            GridPushButton* button = new GridPushButton(Coordinate(i, j)); // gomb létrehozása
            _gridLayout->addWidget(button, i, j); // gomb felvétele az elrendezésbe
            _buttonGrid.append(button); // elmentés a rácsba
            QObject::connect(button, SIGNAL(clicked()), this, SLOT(startColorChange())); // eseménykezelő kapcsolat létrehozása
        }
    }
}
