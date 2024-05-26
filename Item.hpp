#include <ncurses.h>
#include "Drawable.hpp"
#include <ctime>
#ifndef __ITEM__
#define __ITEM__


// 맵에 생성 소멸 되는 특수한 객체 관리 
// 증가 아이템
class Item : public Drawable
{
    
public:
    Item(int y, int x);
    time_t saveTime; // 시간을 저장할 변수
};
// 감소 아이템
class ItemPoison : public Drawable
{
public:
    ItemPoison(int y, int x);
    time_t saveTime;
};
// 빈 공간 관리
class Empty : public Drawable
{

public:
    Empty(int y, int x);
};

class EmptyWall : public Drawable
{

public:
    EmptyWall(int y, int x);
};
// 게이트 관리
class Gate : public Drawable
{
public:
    Gate(int y, int x);
};
#endif