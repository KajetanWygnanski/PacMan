#pragma once

#include "Constants.h"

class Wall: public QGraphicsRectItem{
    public:
        Wall(int x, int y);
       int type() const override {return WALL;}
};

class Entrance: public QGraphicsRectItem{
    public:
        Entrance(int x, int y);
        int type() const override {return ENTRANCE;}
};

class Dot: public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
    public:
        Dot(int x, int y);
        int type() const override {return DOT;}

    public slots:
        void touched();
};

class Fruit: public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
    public:
        Fruit(int x, int y);
        int type() const override {return FRUIT;}

    public slots:
        void touched();
};