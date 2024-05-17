#include "Snake.h"
#include <ncurses.h>
#include <algorithm>
using namespace std;

Snake::Snake(){
    snakeBody.clear(); // snake 배열을 비워둠
    snakeBody.push_back({6,5});
    snakeBody.push_back({7,5});
    snakeHead.push_back({5,5});
}
Snake::~Snake(){
    snakeBody.clear();
}
void Snake::move()
{
    while(true)
    {   
        // 상 하 좌 우
        key = getch(); // 키보드 값을 읽음
        switch (key)
        {
        case KEY_LEFT:
            --posX;
            addAt(win, posY, posX, '#');
            break;

        case KEY_RIGHT:
            ++posX;
            addAt(win, posY, posX,'#');
            break;

        case KEY_UP:
            --posY;
            addAt(win, posY, posX,'#');
            break;

        case KEY_DOWN:
            ++posY;
            addAt(win, posY, posX, '#');
            break;
        
        case 'q': // 종료 조건
            endwin();
        }
    }
}
