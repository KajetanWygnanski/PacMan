#pragma once

#include "Constants.h"

class Gui: public QGraphicsTextItem{
    Q_OBJECT

    public:
        int score;
        Gui();
    public slots:
        void updateScoreDot();
        void updateScoreFruit();
        void updateScoreEnemy();
};