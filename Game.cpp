#include "Game.h"

Game::Game(QWidget *parent) : QGraphicsView(parent){
    scene = new QGraphicsScene(this);
    setSceneRect(0, 0, BOARD_WIDTH, BOARD_HIGHT);
    setScene(scene);
    setFixedSize(BOARD_WIDTH, BOARD_HIGHT);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle("PacMan");

    loadPacman();
    loadScene();

    Gui *gui = new Gui();
    scene->addItem(gui);

    connect(movingObjects[0], SIGNAL(dotEaten()), gui, SLOT(updateScoreDot()));
    connect(movingObjects[0], SIGNAL(fruitEaten()), gui, SLOT(updateScoreFruit()));
    connect(movingObjects[0], SIGNAL(eaten()), gui, SLOT(updateScoreEnemy()));

    gameTick = new QTimer(this);
    for(auto object : movingObjects){
        scene->addItem(object);
        connect(gameTick, SIGNAL(timeout()), object, SLOT(moveObject()));
        if(object->type() != PACMAN){
            connect(movingObjects.at(0), SIGNAL(atTile(QPoint)), object, SLOT(setPacManPosition(QPoint)));
            connect(movingObjects.at(0), SIGNAL(fruitEaten()), object, SLOT(scatter()));
            connect(this, SIGNAL(scatterFinished()), object, SLOT(scatterFinished()));
        }
    }
    gameTick->start(GAME_TICK);
}

void Game::loadPacman(){
    PacMan* pacman;
    pacman = new PacMan();
    pacman->setFlag(QGraphicsItem::ItemIsFocusable);
    pacman->setFocus();
    connect(pacman, SIGNAL(fruitEaten()), this, SLOT(startScatter()));
    movingObjects.push_back(pacman);
}

void Game::loadScene(){
    for(int i = 0 ; i < BOARD_SIZE_VERTICAL ; i++){
        for(int j = 0 ; j < BOARD_SIZE_HORIZONTAL ; j++){
            switch (BOARD[i][j])
            {
            case WALL:
                loadWall(i, j);
                break;

            case DOT:
                loadDot(i, j);
                break;

            case FRUIT:
                loadFruit(i, j);
                break;

            case ENTRANCE:
                loadEntrance(i, j);
                break;
            
            case BORDER_WALL:
                loadWall(i, j);
                if(i == 0){
                    loadWall(i, j - 1);
                    loadWall(i, j - 2);
                }
                else{
                    loadWall(i, j + 1);
                    loadWall(i, j + 2);
                }
                break;
            
            case RED_GHOST:
                loadRedGhost(j, i, Qt::red);
                break;

            case CYAN_GHOST:
                loadCyanGhost(j, i, Qt::cyan);
                break;

            case PINK_GHOST:
                loadPinkGhost(j, i, Qt::magenta);
                break;
            
            case ORANGE_GHOST:
                loadOrangeGhost(j, i, Qt::yellow);
                break;
            default:
                break;
            }
        }
    }
}

void Game::loadWall(int y, int x){
    Wall* rect = new Wall(x, y);
    scene->addItem(rect);
}

void Game::loadDot(int y, int x){
    Dot* dot = new Dot(x, y);
    scene->addItem(dot);
}

void Game::loadFruit(int y, int x){
    Fruit* fruit = new Fruit(x, y);
    scene->addItem(fruit);
}

void Game::loadEntrance(int y, int x){
    Entrance* entrance = new Entrance(x, y);
    scene->addItem(entrance);
}

void Game::loadRedGhost(int x, int y, QColor color){
    Ghost* ghost = new RedGhost(x, y, color);
    movingObjects.push_back(ghost);
    connect(movingObjects.at(0), SIGNAL(redEaten()), ghost, SLOT(eaten()));
}

void Game::loadPinkGhost(int x, int y, QColor color){
    Ghost* ghost = new PinkGhost(x, y, color);
    movingObjects.push_back(ghost);
    connect(movingObjects.at(0), SIGNAL(pinkEaten()), ghost, SLOT(eaten()));
}

void Game::loadCyanGhost(int x, int y, QColor color){
    Ghost* ghost = new CyanGhost(x, y, color);
    movingObjects.push_back(ghost);
    connect(movingObjects.at(0), SIGNAL(cyanEaten()), ghost, SLOT(eaten()));
}

void Game::loadOrangeGhost(int x, int y, QColor color){
    Ghost* ghost = new OrangeGhost(x, y, color);
    movingObjects.push_back(ghost);
    connect(movingObjects.at(0), SIGNAL(orangeEaten()), ghost, SLOT(eaten()));
}

void Game::startScatter(){
    for(auto object : movingObjects){
            object->scatter = true;
    }
    QTimer::singleShot(SCATTER_TIME, this, SLOT(endScatter()));
}

void Game::endScatter(){
    for(auto object : movingObjects){
            object->scatter = false;
    }
    emit scatterFinished();
}
