#pragma once

#include "Ghost.h"

class RedGhost: public Ghost{
    Q_OBJECT

    public:
        RedGhost(int x, int y, QColor color);
        int type() const override {return RED_GHOST;}
        
        
    public slots:
        void setTarget();
        void start();
        void setInitialDirection();
};