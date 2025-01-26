#pragma once

#include "Ghost.h"

class OrangeGhost: public Ghost{
    Q_OBJECT

    public:
        OrangeGhost(int x, int y, QColor color);
        int type() const override {return PINK_GHOST;}
        
        
    public slots:
        void setTarget();
        void start();
        void setInitialDirection();
};