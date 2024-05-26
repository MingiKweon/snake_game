#include "Item.hpp"

Item::Item(int y, int x)
    {
        this->y = y;
        this->x = x;
        this->icon = '@';
        saveTime = time(nullptr);
    }

ItemPoison::ItemPoison(int y, int x)
{
    this->y = y;
    this->x = x;
    this->icon = '$';
    saveTime = time(nullptr);
}

Gate::Gate(int y, int x) // 게이트는 O로 표기
{
    this->y = y;
    this->x = x;
    this->icon = 'O';
}

Empty::Empty(int y, int x)
    {
        this->y = y;
        this->x = x;
        this->icon = ' ';
    }
    
EmptyWall::EmptyWall(int y, int x)
{
        this->y = y;
        this->x = x;
        this->icon = 'X';
}