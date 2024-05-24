#include "Item.hpp"

Item::Item(int y, int x)
    {
        this->y = y;
        this->x = x;
        this->icon = '@';
    }
// item class 와 empty class를 한파일에 묶어 관리하는 것이 좋아 보인다.

ItemPoison::ItemPoison(int y, int x)
{
    this->y = y;
    this->x = x;
    this->icon = '$';
}

Gate::Gate(int y, int x) // 게이트는 O로 표기
{
    this->y = y;
    this->x = x;
    this->icon = 'O';
}