#pragma once

#include "Constants.h"
#include "Moving.h"

class PacMan: public Moving{
    Q_OBJECT

    protected:
        

    public:
        PacMan();
        void keyPressEvent(QKeyEvent *event) override;
        int type() const override {return PACMAN;}

    signals:
        void atTile(QPoint piont) override;
};