#include "gridpushbutton.h"

GridPushButton::GridPushButton(Coordinate coordinate, QWidget *parent)
    : _coordinate(coordinate), QPushButton(parent)
{
    _numberOfOverlaps = 0;
    setFixedSize(80, 80);
}

void GridPushButton::enable()
{
    if(--_numberOfOverlaps < 1)
    {
        setEnabled(true);
        setStyleSheet("background-color: white");
    }
}

void GridPushButton::disable()
{
    if(++_numberOfOverlaps > 0)
    {
        setEnabled(false);
        setStyleSheet("background-color: red");
    }
}
