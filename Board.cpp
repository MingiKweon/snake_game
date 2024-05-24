#include "Board.hpp"

Board::Board() {}
Board::Board(int height, int width)
    {
        int xMax, yMax;
        this->height = height;
        this->width = width;
        getmaxyx(stdscr, yMax, xMax);
        // 커스텀 해야함
        board_win = newwin(0, 0, (yMax/2)-(height/2), (xMax/2)-(width/2));
        //nodelay(board_win, true);
        keypad(board_win, true); // 키입력 사용
        wtimeout(board_win, 1000); // 딜레이

    }
void Board::initialize()
    {
        clear();
        refresh();
    }
void Board::addBorder()
    {
        box(board_win, 0, 0);
    }
void Board::add(Drawable drawable)
{
    addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
}
 void Board::clear()
    {
        wclear(board_win);
        addBorder();
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
