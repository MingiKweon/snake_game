#ifndef SNAKE_H
#define SNAKE_H


#include <vector>
using namespace std;

class Snake
{
public:
    Snake();
    ~Snake();
    void move();
    void addAt(WINDOW * win, int y, int x, char ch);
    
private:
    WINDOW * win;
    vector<vector<int, int>> snakeHead;
    vector<vector<int, int>> snakeBody;
    int key;
    int posX, posY;
};

#endif