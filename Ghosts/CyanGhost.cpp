#include "CyanGhost.h"

CyanGhost::CyanGhost(int x, int y, QColor color): Ghost(x, y, color){
    target = QPoint(14 * TILE_SIZE + 1, 4 * TILE_SIZE + HUD_OFFSET + 1);
    connect(this, SIGNAL(atTarget()), this, SLOT(setTarget()));
    connect(this, SIGNAL(notSurvived()), this, SLOT(start()));
    start();
}

void CyanGhost::setTarget(){
    this->target = pacManPosition;
    this->target.setX(MIDPIONT + (MIDPIONT - this->target.x()));
}

void CyanGhost::start(){
    currentDirection = Direction::UP;
}