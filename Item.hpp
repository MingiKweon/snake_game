#include <ncurses.h>
#include "Drawable.hpp"
#ifndef __ITEM__
#define __ITEM__

class Item : public Drawable
{
public:
    Item(int y, int x);

};

#endif