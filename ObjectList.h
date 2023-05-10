#pragma once
#include "Object.h"

class ObjectList {
public:
    Object* ObjectManager[100000];
    ObjectList() = default;
};
