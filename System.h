#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include "Spell.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Character.h"

class System{
    private:
        static System *instance; 
        std::vector<Item*> itemVector;
        std::vector<Spell> spellVector;
        std::vector<Character> characterVector;

        System();
        ~System();

    public:
        void printItemList();
        void printCharacter();
        void printSpell();
        void itemVectorFromFile(std::string filepath);
        void printItemDetailedList();
        void printItemShortList();
        Item* searchItemByName(std::string name);
        Item* searchItemByID(int ID);
        void createItem();
        void editItem();
        void itemMenu();


        void addItem(const Item &item);
        void addSpell(const Spell &spell);
        void addCharacter(const Character &character);
        Character* getCharacter(std::string name);
        Spell* getSpell(std::string name);
        Item* getItem(std::string name);
        /*Character* getCharacterByPlayer(std::string player);*/
        Character* getCharacterByID(int charID);
        Spell* getSpellByID(int spellID);
        Item* getItemByID(int itemID);

        void deleteCharacter(std::string name);
        void deleteSpell(std::string name);
        void deleteItem(std::string name);

        static System* getInstance();
        void exportCharactersToFile(std::string spellFilePath);
        void exportItemsToFile(std::string spellFilePath);
        void exportSpellsToFile(std::string spellFilePath);
        void standardSystemExportToFiles();
        void MenuStart();
        void displayDefaultCaseMenuResponse();
        void displayMainMenu();
        void displayApplicationWelcomeMessage();
        void characterMenu();
        

        void spellMenu();
        void veSpellMenu();
        void createSpell();
        void certainSpellMenu();
        void editSpell(Spell*);
        void printSpellShortList();

};

#endif