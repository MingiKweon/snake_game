#include <iostream>
#include <ncurses.h>

using namespace std;
int main(void){
    initscr();
    WINDOW * win = newwin(5, 30, 10, 20); // 윈도우 객체 생성 크기 크기 좌표 좌표

    printw("Hello by printw"); // 출력 담당
    wprintw(win, "Hello by wprintw : win"); // 윈도우 내 출력 담당
    refresh(); // 변경점 발생시 변경점 반영
    wrefresh(win); // wrefresh()는 대체로 refresh() 뒤에 오는 것이 좋음
    getch();
    endwin();
}