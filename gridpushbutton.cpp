#include "gridpushbutton.h"

GridPushButton::GridPushButton(Coordinate coordinate, QWidget *parent)
    : _coordinate(coordinate), QPushButton(parent)
{
    _numberOfOverlaps = 0;
    setFixedSize(80, 80);
    setStyleSheet("background-color: white");
}

void GridPushButton::enable()
{   
    if(_numberOfOverlaps > 0)
    {
        _numberOfOverlaps--;
        if(_numberOfOverlaps < 1)
        {
            setEnabled(true);
            setStyleSheet("background-color: white");
        }
    }
}

void GridPushButton::disable()
{   
    _numberOfOverlaps++;
    if(_numberOfOverlaps > 0)
    {
        setEnabled(false);
        setStyleSheet("background-color: red");
    }
}
