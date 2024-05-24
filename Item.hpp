#include <ncurses.h>
#include "Drawable.hpp"
#include <ctime>
#ifndef __ITEM__
#define __ITEM__


// 맵에 생성 소멸 되는 특수한 객체 관리 

class Item : public Drawable
{
    
public:
    Item(int y, int x);
    time_t saveTime; // 시간을 저장할 변수
};

class ItemPoison : public Drawable
{
public:
    ItemPoison(int y, int x);
    time_t saveTime;
};

class Gate : public Drawable
{
public:
    Gate(int y, int x);
};
#endif