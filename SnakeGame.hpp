#ifndef __SNAKEGAME__
#define __SNAKEGAME__

#include <ncurses.h>
#include <ctime>
#include <stdlib.h>
#include <utility>

#include "Board.hpp"
#include "Pointer.hpp"
#include "Item.hpp"
#include "Map.hpp"
#include "Snake.hpp"


class SnakeGame
{
private:
    Board board;
    Item *item;
    ItemPoison *itemPoison;
    Gate *gateA;
    Gate *gateB;
    Snake snake;
    bool gameOver;
    //int score = 0; // scoreBoard part
    int growNumber = 0;     // missionBoard part
    int poisonNumber = 0;
    int gateNumber = 0;
    int stage = 0;
    std::pair<int, int> p;
public:
    int score = 0; // scoreBoard part
    SnakeGame(int height, int width);
    ~SnakeGame();
    void initialize();
    void stageClear();
    void input();
    void updateState();
    void redraw();
    int getStage();
    bool isOver();
    void moveGateAtoB(SnakePiece& next);
    void moveGateBtoA(SnakePiece& next);
};

#endif