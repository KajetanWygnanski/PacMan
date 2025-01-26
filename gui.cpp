#include "gui.h"

Gui::Gui(){
    score = 0;
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
    setPos(0, 0);
}

void Gui::updateScoreDot(){
    this->score += DOT_POINTS;
    setPlainText("Score: " + QString::number(this->score));
}

void Gui::updateScoreFruit(){
    this->score += FRUIT_POINTS;
    setPlainText("Score: " + QString::number(this->score));
}

void Gui::updateScoreEnemy(){
    this->score += ENEMY_POINTS;
    setPlainText("Score: " + QString::number(this->score));
}