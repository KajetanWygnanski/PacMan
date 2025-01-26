#include "PacMan.h"
#include <iostream>

PacMan::PacMan() : Moving(){
    setPos(9 * TILE_SIZE + 1, 12 * TILE_SIZE + HUD_OFFSET + 1);
    setRect(0, 0, OBJECT_SIZE, OBJECT_SIZE);

    QBrush brush;
    brush.setColor(Qt::yellow);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);

}

void PacMan::keyPressEvent(QKeyEvent *event){
    switch (event->key())
    {
        case Qt::Key_Left:
            nextDirection = Direction::LEFT;
            break;
        case Qt::Key_Right:
            nextDirection = Direction::RIGHT;
            break;
        case Qt::Key_Up:
            nextDirection = Direction::UP;
            break;
        case Qt::Key_Down:
            nextDirection = Direction::DOWN;
            break;
    }
}


