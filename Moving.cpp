#include "Moving.h"
#include "Ghost.h"

#include <iostream>

Moving::Moving(): QObject(), QGraphicsEllipseItem(){
    currentDirection = Direction::NONE;
    nextDirection = Direction::NONE;
    this->boundingRect() = QRectF(0, 0, OBJECT_SIZE, OBJECT_SIZE);
}

bool Moving::legalMove(){
    if(collidingItems(Qt::IntersectsItemBoundingRect).isEmpty()){
        return true;
    }

    bool wall = 0;
    for(auto item: collidingItems(Qt::IntersectsItemBoundingRect)){
        if(item->type() == RED_GHOST || item->type() == CYAN_GHOST){
            if(this->type() == PACMAN){
                if(!this->scatter){
                    exit(0);
                }
                emit eaten();
                switch(item->type()){
                    case RED_GHOST:
                        emit redEaten();
                        break;
                    case CYAN_GHOST:
                        emit cyanEaten();
                        break;
                    case PINK_GHOST:
                        emit pinkEaten();
                        break;
                    case ORANGE_GHOST:
                        emit orangeEaten();
                        break;
                }
            }
            else{
                emit collision();
            }
        }
        if(item->type() == WALL){
            wall = 1;
        }
        if(item->type() == ENTRANCE){
            if(this->y() <= 8 * TILE_SIZE + HUD_OFFSET + 2 && currentDirection != Direction::UP){
                wall = 1;
            }
        }
        if(item->type() == DOT ){
            if(this->type() == PACMAN) handleDot(dynamic_cast<Dot*>(item));
        }

        if(item->type() == FRUIT){
            if(this->type() == PACMAN){
                handleFruit(dynamic_cast<Fruit*>(item));
            }
        }
    }

    return !wall;
}

void Moving::moveObject(){
    if(!checkDirrection(nextDirection)){
        checkDirrection(currentDirection);
    }
    else{
        currentDirection = nextDirection;
    }
    checkTeleport();
    if(checkIfAtTile()){
        emit atTile(QPoint(x(), y()));
    }

    //cout<<this->type()<<": Moved in direction "<<currentDirection<<"\n";
    update();
}

bool Moving::checkDirrection(Direction direction){
    if(direction == Direction::NONE){
        return false;
    }
    int xMove = 0;
    int yMove = 0;

    xMove = (direction == Direction::LEFT ? -MOVE : (direction == Direction::RIGHT ? MOVE : 0));
    yMove = (direction == Direction::UP ? -MOVE : (direction == Direction::DOWN ? MOVE : 0));
    setPos(x() + xMove, y() + yMove);

    if(legalMove()){
        return true;
    }
    
    setPos(x() - xMove, y() - yMove);
    return false;
}

void Moving::checkTeleport(){
    if(x() <= - OBJECT_SIZE){
        setPos(BOARD_WIDTH - 1, y());
    }
    else if(x() >= BOARD_WIDTH){
        setPos(-OBJECT_SIZE + 1, y());
    }
}

void Moving::handleDot(Dot* dot){
    connect(this, SIGNAL(dotEaten()), dot, SLOT(touched()), Qt::UniqueConnection);
    emit dotEaten();
}

void Moving::handleFruit(Fruit* fruit){
    connect(this, SIGNAL(fruitEaten()), fruit, SLOT(touched()), Qt::UniqueConnection);
    emit fruitEaten();
}

bool Moving::checkIfAtTile(){
    return ((int)x() % TILE_SIZE == TILE_POSITION && (int)y() % TILE_SIZE == TILE_POSITION);
}