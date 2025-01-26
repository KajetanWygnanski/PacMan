#pragma once

#include "Ghost.h"

class CyanGhost: public Ghost{
    Q_OBJECT

    public:
        CyanGhost(int x, int y, QColor color);
        int type() const override {return CYAN_GHOST;}
        
    public slots:
        void setTarget();
        void start();
};