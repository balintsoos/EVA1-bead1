#include "gridpushbutton.h"

GridPushButton::GridPushButton(Coordinate coordinate, QWidget *parent)
    : _coordinate(coordinate), QPushButton(parent)
{
    numberOfOverlaps = 0;
}

void GridPushButton::enable()
{
    if(--numberOfOverlaps < 1)
    {
        setEnabled(true);
        setStyleSheet("background-color: white");
    }
}

void GridPushButton::disable()
{
    if(++numberOfOverlaps > 0)
    {
        setEnabled(false);
        setStyleSheet("background-color: red");
    }
}
