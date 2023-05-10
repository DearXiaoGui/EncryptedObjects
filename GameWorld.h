#pragma once
#include "ObjectList.h"
#include <stdio.h>

class GameWorld {
public:
    ObjectList* listPtr;
    int count;

    GameWorld();
    void update();
};