#ifndef SNAKE_H
#define SNAKE_H

#include "Board.hpp"
#include <vector>
using namespace std;

class Snake
{
public:
    Snake();
    ~Snake();
    void move();
    void addAt(Board board, int y, int x, char ch);
    
private:
    vector<vector<int, int>> snakeHead;
    vector<vector<int, int>> snakeBody;
    int key;
    int posX, posY;
};

#endif