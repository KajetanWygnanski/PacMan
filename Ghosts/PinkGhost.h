#pragma once

#include "Ghost.h"

class PinkGhost: public Ghost{
    Q_OBJECT

    public:
        PinkGhost(int x, int y, QColor color);
        int type() const override {return PINK_GHOST;}
        
        
    public slots:
        void setTarget();
        void start();
        void setInitialDirection();
};