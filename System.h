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
        static System *instance; 
        std::vector<Item> itemVector;
        std::vector<Spell> spellVector;
        std::vector<Character> characterVector;

        System();

    public:
        void printItemList();
        void printCharacter();
        void printSpell();


        void addItem(const Item &item);
        void addSpell(const Spell &spell);
        void addCharacter(const Character &character);
        Character* getCharacter(std::string name);
        Spell* getSpell(std::string name);
        Item* getItem(std::string name);
        Character* getCharacterByID(int charID);
        Spell* getSpellByID(int spellID);
        Item* getItemByID(int itemID);
        static System *getInstance();
        void exportToFile(std::string characterFilePath, std::string spellFilePath, std::string itemFilePath);



};

#endif