#pragma once
#include "XorPtr.h"

class Spell {
public:
    float damage = 100.0f;
    float cooldown = 120.0f;
    float time = 140.0f;
    Spell() = default;
};

class Object {
public:
    float x = 100.0f;
    float y = 100.0f;
    float health = 50.0f;
    float damage = 30.0f;
    Spell* Spell_ = nullptr;
    Object();
};