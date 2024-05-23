#include "Board.hpp"

Board::Board() {}
Board::Board(int height, int width)
    {
        int xMax, yMax;
        this->height = height;
        this->width = width;
        getmaxyx(stdscr, yMax, xMax);
        // 커스텀 해야함
        board_win = newwin(height, width, (yMax/2)-(height/2), (xMax/2)-(width/2));
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
void Board::getEmptyCoordinates(int& y, int& x)
{
    do{
    y = rand() % height;
    x = rand() % width;
} while (mvwinch(board_win, y, x) != ' ');    
}
void Board::addAt(int y, int x, char ch)
    {
        mvwaddch(board_win, y, x, ch);
    }
