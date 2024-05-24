#include <iostream>
#include <ncurses.h>
#include "Board.hpp"
#include "SnakeGame.hpp"
#include "Drawable.hpp"


#define BOARD_DIM 17
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5


using namespace std;


int main(){
    initscr();
    refresh();

    noecho();
    curs_set(0); // 커서 미표시
    SnakeGame game(BOARD_ROWS, BOARD_COLS);

    while(!game.isOver())
    {
        game.input();

        game.updateState();
        
        game.redraw();
    }
    getch(); // key 가 입력되기 전까지 대기할 수 있도록 해줌
    endwin();
    
    return 0;
}
// 게임의 총 순환을 관리하는 부분으로 사용되어야 해 보임
// 게이트 item을 구현하되 그 객체들의 생성, 소멸에 딜레이가 있어야한다
