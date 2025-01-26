#include "Unmovable.h"

Wall::Wall(int x, int y){
    setRect(x * TILE_SIZE, (y * TILE_SIZE) + HUD_OFFSET, TILE_SIZE, TILE_SIZE);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    setBrush(brush);
}

Entrance::Entrance(int x, int y){
    setRect(x * TILE_SIZE, (y * TILE_SIZE) + HUD_OFFSET, TILE_SIZE, TILE_SIZE);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);
}

Dot::Dot(int x, int y){
    setRect(x * TILE_SIZE + DOT_OFFSET, (y * TILE_SIZE) + HUD_OFFSET + DOT_OFFSET, DOT_SIZE, DOT_SIZE);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}

void Dot::touched(){
    delete this;
}

Fruit::Fruit(int x, int y){
    setRect(x * TILE_SIZE + FRUIT_OFFSET, (y * TILE_SIZE) + HUD_OFFSET + FRUIT_OFFSET, FRUIT_SIZE, FRUIT_SIZE);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}

void Fruit::touched(){
    delete this;
}