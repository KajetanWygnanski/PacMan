#include "Ghost.h"

#include <math.h>

Ghost::Ghost(int x, int y, QColor color) : Moving(){
    setPos(x * TILE_SIZE + 1, y * TILE_SIZE + HUD_OFFSET + 1);
    setRect(0, 0, OBJECT_SIZE, OBJECT_SIZE);

    QBrush brush;
    this->color = color;
    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);

    mode = Mode::CHASE;
    target = QPoint(9 * TILE_SIZE + 1, 12 * TILE_SIZE + HUD_OFFSET + 1);
    home = QPoint(x, y);
    entrance = QPoint(10 * TILE_SIZE + 1, 8 * TILE_SIZE + HUD_OFFSET + 1);

    connect(this, SIGNAL(atTile(QPoint)), this, SLOT(nextTile()));
    connect(this, SIGNAL(collision()), this, SLOT(reverseDirection()));
    nextDirection = Direction::NONE;
}

void Ghost::nextTile(){
    if(QPoint(x(), y()) == target){
        emit atTarget();
    }

    if(currentDirection == Direction::NONE){
        return;
    }

    vector<Direction> possibleDirections;

    if(currentDirection != Direction::DOWN){
        if(checkDirrection(Direction::UP)){
            possibleDirections.push_back(Direction::UP);
            setPos(x(), y() - MOVE);
        }
    }

    if(currentDirection != Direction::UP){
        if(checkDirrection(Direction::DOWN)){
            possibleDirections.push_back(Direction::DOWN);
            setPos(x(), y() + MOVE);
        }
    }

    if(currentDirection != Direction::LEFT){
        if(checkDirrection(Direction::RIGHT)){
            possibleDirections.push_back(Direction::RIGHT);
            setPos(x() - MOVE, y());
        }
    }

    if(currentDirection != Direction::RIGHT){
        if(checkDirrection(Direction::LEFT)){
            possibleDirections.push_back(Direction::LEFT);  
            setPos(x() + MOVE, y());
        }
    }

    currentDirection = chooseBestDirection(possibleDirections); 
} 

Direction Ghost::chooseBestDirection(vector<Direction> possibleDirections){
    if(possibleDirections.size() == 0){
        return currentDirection;
    }
    
    if(possibleDirections.size() == 1){
        return possibleDirections[0];
    }

    double distance = INT_MAX, new_distance;
    Direction bestDirection = currentDirection;

    for(auto direction: possibleDirections){
        new_distance = checkDistance(direction);
        if(new_distance < distance){
            distance = new_distance;
            bestDirection = direction;
        }
    }

    return bestDirection;
}

double Ghost::checkDistance(Direction direction){
    int xMove = 0;
    int yMove = 0;

    xMove = (direction == Direction::LEFT ? -MOVE : (direction == Direction::RIGHT ? MOVE : 0));
    yMove = (direction == Direction::UP ? -MOVE : (direction == Direction::DOWN ? MOVE : 0));
    setPos(x() + xMove, y() + yMove);
    double ret =  sqrt(pow((target.x() - x()), 2) + pow((target.y() - y()), 2));
    setPos(x() - xMove, y() - yMove);
    return ret;
}

void Ghost::setPacManPosition(QPoint position)
{
    pacManPosition = position;
}

void Ghost::reverseDirection(){
    switch(currentDirection){
        case Direction::UP:
            currentDirection =  Direction::DOWN;
            break;
        case Direction::DOWN:
            currentDirection =  Direction::UP;
            break;
        case Direction::LEFT:
            currentDirection =  Direction::RIGHT;
            break;
        case Direction::RIGHT:
            currentDirection =  Direction::LEFT;
            break;
        default:
            currentDirection = Direction::NONE;
    }
}

void Ghost::scatter(){
    reverseDirection();
    target = home;
    mode = Mode::SCATTER;

    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);

    survivor = true;
}

void Ghost::eaten(){
    setPos(home.x() * TILE_SIZE + 1, home.y() * TILE_SIZE + HUD_OFFSET + 1);
    currentDirection = Direction::NONE;
    mode = Mode::CHASE;

    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);

    survivor = false;
    emit notSurvived();
}

void Ghost::scatterFinished(){
    mode = Mode::CHASE;
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);
}
