#include <iostream>
#include <ncurses.h>
#include "Board.hpp"
#include "map.h"

#define BOARD_DIM 17
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5


using namespace std;

int main(){
    initscr();
    refresh();
    
    Board board(BOARD_ROWS, BOARD_COLS);
    drawMap(board);
    int key;
    int posX = 5;
    int posY = 5;
    
    board.refresh();
    keypad(stdscr, TRUE);
    while(true)
    {   
        // 상 하 좌 우
        key = getch(); // 키보드 값을 읽음
        switch (key)
        {
        case KEY_LEFT:
            --posX;
            board.addAt(posY, posX,'0');
            board.refresh();
            break;

        case KEY_RIGHT:
            ++posX;
            board.addAt(posY, posX,'0');
            board.refresh();
            break; 

        case KEY_UP:
            --posY;
            board.addAt(posY, posX,'0');
            board.refresh();
            break;

        case KEY_DOWN:
            ++posY;
            board.addAt(posY, posX, '0');
            board.refresh();
            break;
        }

    }


    getch(); // key 가 입력되기 전까지 대기할 수 있도록 해줌
    endwin();
    return 0;
}