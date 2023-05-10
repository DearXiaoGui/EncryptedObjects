#include "Object.h"

Object::Object() : Spell_(new Spell()) {
    Spell_ = Xor::Encrypt(Spell_);
}