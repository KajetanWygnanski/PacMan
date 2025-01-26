#pragma once

#include <QGraphicsEllipseItem>
#include <QCoreApplication>
#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QKeyEvent>
#include <QBrush>
#include <QTimer>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

#include <iostream>
#include <vector>

using std::vector, std::cout;

enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

enum Mode{
    CHASE,
    SCATTER,
    FRIGHTENED,
    EATEN
};

#define BOARD_SIZE_VERTICAL 22
#define BOARD_SIZE_HORIZONTAL 19
#define TILE_SIZE 30
#define OBJECT_SIZE 28
#define HUD_OFFSET 30
#define TILE_POSITION 1
#define MIDPIONT 271

#define BOARD_HIGHT BOARD_SIZE_VERTICAL * TILE_SIZE + HUD_OFFSET
#define BOARD_WIDTH BOARD_SIZE_HORIZONTAL * TILE_SIZE

#define MOVE 1
#define GAME_TICK 10

#define FRUIT 0
#define WALL 1
#define DOT 2
#define AIR 3
#define RED_GHOST 4
#define CYAN_GHOST 5
#define PINK_GHOST 6
#define ORANGE_GHOST 7
#define ENTRANCE 8
#define BORDER_WALL 9
#define PACMAN 10
#define GHOST 11

#define DOT_SIZE 10
#define DOT_OFFSET 10
#define FRUIT_SIZE 16
#define FRUIT_OFFSET 7

#define SCATTER_TIME 7000

#define DOT_POINTS 100
#define FRUIT_POINTS 300
#define ENEMY_POINTS 500