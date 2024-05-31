#include <iostream>
#include <ncurses.h>
#include "Board.hpp"
#include "SnakeGame.hpp"
#include "Pointer.hpp"


#define BOARD_ROWS 17
#define BOARD_COLS 17 * 2.5


using namespace std;


int main(){
    initscr();
    refresh();

    noecho();
    curs_set(0); // 커서 미표시
    // 2중 while로 clear 함수가 호출되면 내부 while문 종료 후 새 객체 생성?
    SnakeGame game(BOARD_ROWS, BOARD_COLS);

    while(!(game.isOver()) && game.getStage() < 4)
    {
        game.input(); // 값 입력

        game.updateState(); // 게임 진행부
        game.redraw(); // 갱신
    }
    getch(); // key 가 입력되기 전까지 대기할 수 있도록 해줌
    endwin();
    
    return 0;
}
// 게임의 총 순환을 관리하는 부분으로 사용되어야 해 보임
// 게이트 item을 구현하되 그 객체들의 생성, 소멸에 딜레이가 있어야한다
// 새로운 아이템 종류로는 먹으면 게임의 업데이팅이 더 빨라지도록 세팅