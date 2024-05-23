#include <curses.h>

int main() {
    initscr();              // curses 모드 시작
    keypad(stdscr, TRUE);   // 기능 키 사용 가능하게 설정
    noecho();               // 키 입력 시 화면에 표시되지 않도록 설정

    int posX = 0, posY = 0;
    bool movingLeft = false, movingRight = false, movingUp = false, movingDown = false;
    int key;

    while(true) {
        key = getch(); // 키보드 값을 읽음

        switch (key) {
            case KEY_LEFT:
                movingLeft = true;
                break;

            case KEY_RIGHT:
                movingRight = true;
                break;

            case KEY_UP:
                movingUp = true;
                break;

            case KEY_DOWN:
                movingDown = true;
                break;

            case 'q': // 종료 조건
                endwin();
                return 0;
        }

        // 특정 키가 눌러진 동안에만 해당 방향으로 이동
    while (true)
    {
        mvprintw(0, 0, "Position: (%d, %d)   ", posX, posY);
        refresh();
        /* code */
        if (movingLeft)
            --posX;
        if (movingRight)
            ++posX;
        if (movingUp)
            --posY;
        if (movingDown)
            ++posY;
        napms(500);
        
    }
    movingLeft =false;
    movingRight = false;
    movingUp = false;
    movingDown = false;
        mvprintw(0, 0, "Position: (%d, %d)   ", posX, posY); // 현재 위치 출력
        refresh(); // 화면 갱신


    }

    return 0;
}
