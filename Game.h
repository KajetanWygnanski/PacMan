#pragma once

#include "Moving.h"
#include "Unmovable.h"
#include "Constants.h"
#include "PacMan.h"
#include "Ghost.h"
#include "Board.h"
#include "Ghosts/RedGhost.h"
#include "Ghosts/CyanGhost.h"
#include "Ghosts/PinkGhost.h"
#include "Ghosts/OrangeGhost.h"
#include "gui.h"

class Game : public QGraphicsView{
    Q_OBJECT

    public:
        Game(QWidget *parent = 0);
        QGraphicsScene *scene;
        QTimer* gameTick;

        vector <Moving*> movingObjects;
       
        void loadScene();
        void loadWall(int x, int y);
        void loadDot(int x, int y);
        void loadFruit(int x, int y);
        void loadEntrance(int x, int y);

        void loadPacman();

        void loadRedGhost(int x, int y, QColor color);
        void loadCyanGhost(int x, int y, QColor color);
        void loadPinkGhost(int x, int y, QColor color);
        void loadOrangeGhost(int x, int y, QColor color);

        // void keyPressEvent(QKeyEvent *event) override;

    signals:
        void advance();
        void scatterFinished();
        

    public slots:
        void startScatter();
        void endScatter();
};