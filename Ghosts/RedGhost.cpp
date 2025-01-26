#include "RedGhost.h"

RedGhost::RedGhost(int x, int y, QColor color): Ghost(x, y, color){
    target = QPoint(4 * TILE_SIZE + 1, 4 * TILE_SIZE + HUD_OFFSET + 1);
    currentDirection = Direction::NONE;
    connect(this, SIGNAL(atTarget()), this, SLOT(setTarget()));
    connect(this, SIGNAL(notSurvived()), this, SLOT(start()));
    start();
}

void RedGhost::setTarget(){
    this->target = pacManPosition;
}

void RedGhost::start(){
    QTimer::singleShot(2000, this, SLOT(setInitialDirection()));
}

void RedGhost::setInitialDirection(){
    currentDirection = Direction::RIGHT;
}