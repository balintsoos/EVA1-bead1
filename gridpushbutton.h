#ifndef GRIDPUSHBUTTON_H
#define GRIDPUSHBUTTON_H

#include <QPushButton>
#include "coordinate.h"

class GridPushButton : public QPushButton
   // a rácsba helyezendő nyomógomb típusa, amely rendelkezik koordinátával
{
    Q_OBJECT
public:
    explicit GridPushButton(Coordinate coordinate, QWidget *parent = 0);
    Coordinate coordinate() const { return _coordinate; }
    void enable();
    void disable();

protected:
    Coordinate _coordinate;
    int _numberOfOverlaps;
};

#endif // GRIDPUSHBUTTON_H
