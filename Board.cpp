#include "Board.hpp"

Board::Board() {}
Board::Board(int height, int width)
    {
        mapData;
        int xMax, yMax;
        this->height = height;
        this->width = width;
        getmaxyx(stdscr, yMax, xMax); // 좌표 중앙
        // 맵 배열을 22 42로 구현
        board_win = newwin(22, 42, (yMax/2)-(height/2), (xMax/2)-(width/2));
        // 윈도우 객체를 넘겨줘야함 snakegame.hpp에 
        score_win = newwin(11, 40, (yMax/2)-(height/2), (xMax/2)-(width/2)+42);
        mission_win = newwin(11, 40, (yMax/2)-(height/2) + 11, (xMax/2)-(width/2)+42);
        box(score_win, 0, 0);
        box(mission_win, 0, 0);
        

        int q, w;
        getmaxyx(score_win, q, w);
        std::string aa = "score : ";
        mvwprintw(score_win, q / 2, (w - aa.size()) / 2 - 10, "%s", aa.c_str());
        
        getmaxyx(mission_win, q, w);
        std::string bb = "mission : ";
        mvwprintw(mission_win, q / 2, (w - bb.size()) / 2 - 10, "%s", bb.c_str());
        
        wrefresh(score_win);
        wrefresh(mission_win);

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
    int (*map)[42] = mapData.getMap(1);
    for(int i = 0; i < 22; i++) 
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

            addMap(i, j, ch); // 보드에 문자 추가
        }
    }
}
void Board::add(Pointer pointer)
{
    mvwaddch(board_win, pointer.getY(), pointer.getX(), pointer.getIcon());
}
 void Board::clear()
    {
        wclear(board_win);
        //wclear(score_win);
        //wclear(mission_win);
        drawMap();
    }
void Board::refresh()
    {
        wrefresh(board_win);
        //wrefresh(score_win);
        //wrefresh(mission_win);
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
void Board::addMap(int y, int x, char ch)
{
    mvwaddch(board_win, y, x, ch);
}
void Board::updateScore(int score)
{
    mvwprintw(score_win, 5, 17, "%d", score);
    wrefresh(score_win);
}
void Board::updateMission(int y, int x, char ch)
{
    mvwaddch(mission_win, y, x, ch);
    //mvwprintw(score_win, 5, 17, "%d", score);
    wrefresh(mission_win);
}
WINDOW* Board::getBoardWin() {
    return board_win;
}
WINDOW* Board::getScoreWin() {
    return score_win;
}
WINDOW* Board::getMissionWin() {
    return mission_win;
}