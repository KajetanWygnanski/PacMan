#pragma once

#include "Constants.h"
#include "Unmovable.h"


class Moving: public QObject, public QGraphicsEllipseItem{
    Q_OBJECT

    public:
        Moving();
        Direction currentDirection;
        Direction nextDirection;

        bool legalMove();
        bool checkDirrection(Direction direction);
        bool scatter;
        void checkTeleport();
        void handleDot(Dot* dot);
        void handleFruit(Fruit* fruit);
        bool checkIfAtTile();

    signals:
            void dotEaten();
            void fruitEaten();
            virtual void atTile(QPoint piont);
            void collision();
            void redEaten();
            void pinkEaten();
            void orangeEaten();
            void cyanEaten();
            void eaten();

    public slots:
        virtual void moveObject();
};