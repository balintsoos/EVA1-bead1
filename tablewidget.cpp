#include "tablewidget.h"
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

    _stepCounter = new StepCounter();

    _vBoxLayout = new QVBoxLayout();
    _vBoxLayout->addWidget(_sizeButton);
    _vBoxLayout->addWidget(_quitButton);
    _vBoxLayout->addWidget(_stepCounter);

    _gridLayout = new QGridLayout();
    _vBoxLayout->addLayout(_gridLayout);

    setLayout(_vBoxLayout);
}

TableWidget::~TableWidget()
{
    delete _gridSizeDialog;
}

void TableWidget::clickOnField()
{
    _stepCounter->step();

    GridPushButton *button = qobject_cast<GridPushButton*>(sender());
    Coordinate coordinate = button->coordinate();
    bool isExist = false;

    QMutableVectorIterator<Coordinate> i(_queens);
    while(i.hasNext())
    {
        Coordinate current = i.next();
        if(current.x() == coordinate.x() && current.y() == coordinate.y())
        {
            removeQueen(coordinate);
            i.remove();
            isExist = true;
        }
    }

    if(!isExist)
    {
        addQueen(coordinate);
    }

    checkEndGame();
}

void TableWidget::addQueen(Coordinate coordinate)
{
    _queens.append(coordinate);

    foreach(GridPushButton* buttonToChange, _buttonGrid)
    {
       if(buttonToChange->coordinate().x() == coordinate.x() ||
          buttonToChange->coordinate().y() == coordinate.y() ||
          qAbs(coordinate.x() - buttonToChange->coordinate().x()) ==
          qAbs(coordinate.y() - buttonToChange->coordinate().y()))
       {
           buttonToChange->disable();
       }

       if(buttonToChange->coordinate().x() == coordinate.x() &&
          buttonToChange->coordinate().y() == coordinate.y())
       {
           buttonToChange->enable();
           buttonToChange->setStyleSheet("background-color: yellow");

       }
    }
}

void TableWidget::removeQueen(Coordinate coordinate)
{
    foreach(GridPushButton* buttonToChange, _buttonGrid)
    {
        if(buttonToChange->coordinate().x() == coordinate.x() ||
           buttonToChange->coordinate().y() == coordinate.y() ||
           qAbs(coordinate.x() - buttonToChange->coordinate().x()) ==
           qAbs(coordinate.y() - buttonToChange->coordinate().y()))
        {
            buttonToChange->enable();
        }
    }
}

void TableWidget::checkEndGame()
{
    if(_queens.size() == _gridSizeDialog->gridSize())
    {
        resizeGrid();
        //TODO
    }
}

void TableWidget::resizeGrid()
{
    _stepCounter->reset();

    // törölni kell az összes gombot
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
            QObject::connect(button, SIGNAL(clicked()), this, SLOT(clickOnField())); // eseménykezelő kapcsolat létrehozása
        }
    }
}
