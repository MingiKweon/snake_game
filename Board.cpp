#include "Board.hpp"

Board::Board() {}
Board::Board(int height, int width)
    {
        mapData;
        int xMax, yMax;
        this->height = height;
        this->width = width;
        getmaxyx(stdscr, yMax, xMax);
        // 맵 배열을 21 42로 구현
        board_win = newwin(21, 42, (yMax/2)-(height/2), (xMax/2)-(width/2));
        //nodelay(board_win, true);
        keypad(board_win, true); // 키입력 사용
        wtimeout(board_win, 400); // 딜레이

    }
void Board::initialize()
    {
        clear();
        refresh();
    }
void Board::drawMap() // 맵 구현부
{
    int (*map)[42] = mapData.getMap(stage);
    for(int i = 0; i < 21; i++) 
    {
        for(int j = 0; j < 42; j++) {
            int a = map[i][j];
            char ch;
            switch(a) {
                case 0:
                    ch = ' '; 
                    break;
                case 1:
                    ch = 'X';
                    break;
                case 2:
                    ch = '$'; // 통과 불가 벽
                    break;
            }

            addAt(i, j, ch); // 보드에 문자 추가
        }
    }
}
void Board::add(Drawable drawable)
{
    addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
}
 void Board::clear()
    {
        wclear(board_win);
        drawMap();
    }
void Board::refresh()
    {
        wrefresh(board_win);
    }
int Board::getInput()
    {
        return wgetch(board_win);
    }
void Board::getEmptyCoordinates(int& y, int& x) // 빈곳을 찾음
{
    do{
    y = rand() % height;
    x = rand() % width;
} while (mvwinch(board_win, y, x) != ' ');    
}
void Board::getWallCoordinates(int& y, int& x) // 벽을 찾음 벽은 X로 구현
{
    do{
    y = rand() % height;
    x = rand() % width;
} while (mvwinch(board_win, y, x) != 'X');    
}

void Board::addAt(int y, int x, char ch)
    {
        mvwaddch(board_win, y, x, ch);
    }
WINDOW* Board::getBoardWin() {
    return board_win;
}