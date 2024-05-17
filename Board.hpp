#ifndef BOARD_H
#define BOARD_H
#include <ncurses.h>



class Board
{
public:
    Board(int height = 10, int width = 10); // 생성자
    ~Board();
    void initialize();
    void addBorder();
    void clear();
    void refresh();
    char getInput();
    void addAt(int y, int x, char ch);
    WINDOW* getWindow();

private:
    WINDOW* board;
};

#endif