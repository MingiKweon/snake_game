#include <ncurses.h>
#include "Drawable.hpp"
#ifndef __EMPTY__
#define __EMPTY__
class Empty : public Drawable
{

public:
    Empty(int y, int x);
};

#endif