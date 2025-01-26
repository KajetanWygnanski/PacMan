#include "PinkGhost.h"

PinkGhost::PinkGhost(int x, int y, QColor color): Ghost(x, y, color){
    target = QPoint(13 * TILE_SIZE + 1, 4 * TILE_SIZE + HUD_OFFSET + 1);
    currentDirection = Direction::NONE;
    connect(this, SIGNAL(atTarget()), this, SLOT(setTarget()));
    connect(this, SIGNAL(notSurvived()), this, SLOT(start()));
    start();
}

void PinkGhost::setTarget(){
    this->target = pacManPosition;
}

void PinkGhost::start(){
    QTimer::singleShot(1000, this, SLOT(setInitialDirection()));
}

void PinkGhost::setInitialDirection(){
    currentDirection = Direction::UP;
}