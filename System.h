#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include "Spell.h"
#include "Item.h"
#include "Character.h"

class System{
    private:
        std::vector<Item> itemVector;
        std::vector<Spell> spellVector;
        std::vector<Character> characterVector;
    public:
        void printItemList();
        void printCharacter();
        void printSpell();
}

#endif