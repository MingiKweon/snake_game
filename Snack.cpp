#include "Snake.h"
#include <ncurses.h>
#include <algorithm>
using namespace std;

Snake::Snake(){
    snakeBody.clear(); // snake 배열을 비워둠
    snakeBody.push_back({5,5});
    snakeBody.push_back({6,5});
    snakeBody.push_back({7,5});
    snakeHead.push_back({5,5});
}

Snake::~Snake(){
    snakeBody.clear();
}
