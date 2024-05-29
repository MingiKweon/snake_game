#ifndef __BOARD__
#define __BOARD__
#include <ncurses.h>
#include "Pointer.hpp"
#include "Map.hpp"
#include <vector>
#include <cstdlib>
#include <string>

class Board
{
public:
    Board(); // 디폴트
    Board(int height, int width); // 생성자
    void initialize();
    void drawMap();
    void add(Pointer pointer);
    void clear();
    void refresh();
    int getInput();
    void addMap(int y, int x, char ch);
    void updateScore(int score);
    void updateMission(int y, int x, char ch);
    void getEmptyCoordinates(int& y, int& x);
    void getWallCoordinates(int& y, int& x);
    WINDOW* getBoardWin();
    WINDOW* getScoreWin();
    WINDOW* getMissionWin();
private:
    WINDOW* board_win;
    WINDOW* score_win;
    WINDOW* mission_win;
        
    Map mapData;
    int (*map)[42];
    int stage = 0; // 스테이지 불러오는 변수
    int height, width;
};

#endif