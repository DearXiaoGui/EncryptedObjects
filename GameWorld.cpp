#include "GameWorld.h"

GameWorld::GameWorld() : count(0) {
    auto list = new ObjectList();
    listPtr = Xor::Encrypt(list);

    for (size_t i = 0; i < 100; i++)
    {
        auto object = new Object();
        Xor::Decrypt(listPtr)->ObjectManager[i] = Xor::Encrypt(object);
        count++;
    }
}

void GameWorld::update() {

    auto list = Xor::Decrypt(listPtr);
    for (size_t i = 0; i < count; i++)
    {
        auto obj = Xor::Decrypt(list->ObjectManager[i]);
        auto objSpell = Xor::Decrypt(obj->Spell_);
        objSpell->cooldown = 100.0f;
        objSpell->damage = 120.0f;
        objSpell->time = 140.0f;
        printf("G_World:%p list:%p DecryptList:%p obj:%p DecryptObj:%p Spell:%p DecryptSpell:%p\n", this, listPtr, list, list->ObjectManager[i], obj, obj->Spell_, objSpell);
    }
}