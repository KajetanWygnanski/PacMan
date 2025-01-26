#pragma once

#include "Constants.h"
#include "Moving.h"

class Ghost: public Moving{
    Q_OBJECT

    public:
        Ghost(int x, int y, QColor color);
        Mode mode;
        QPoint target;
        QPoint home;
        QPoint entrance;
        QPoint pacManPosition;
        QColor color;
        Direction chooseBestDirection(vector<Direction> possibleDirections);
        double checkDistance(Direction direction);
        bool survivor;
        int type() const override {return GHOST;}

    signals:
        void atTarget();  
        void atTile(QPoint piont) override;
        void notSurvived();
        

    public slots:
        void setPacManPosition(QPoint position);
        void scatter();
        void nextTile();
        void reverseDirection();
        void eaten();
        void scatterFinished(); 
};