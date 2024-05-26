#ifndef __SNAKEGAME__
#define __SNAKEGAME__

#include <ncurses.h>
#include <ctime>
#include <stdlib.h>

#include "Board.hpp"
#include "Drawable.hpp"
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
public:
    SnakeGame(int height, int width);
    ~SnakeGame();
    void initialize();
    void input();
    void updateState();
    void redraw();
    bool isOver();
};

#endif