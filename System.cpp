#include <iostream>
#include <fstream>
#include "System.h"


System::System(){
}
std::vector<Item*> System::itemVectorFromFile(std::string filepath)
{
    std::fstream readFile;
    std::vector<Item*>::iterator iter;
    std::vector<Item*> outVector;
    readFile.open(filepath);
    while(!readFile.eof())
    {
        int type;
        std::string name;
        std::string damage;
        int dmgtype;
        int armortype;
        double weight;
        int id;
        int range;
        int price;

        Weapon temp1;
        Armor temp2;
        Item temp3;
        
        readFile >> type;
        switch(type)
        {
            case 0:
                //temp1.setItemType_(temp3.intToType(type));
                readFile >> name;
                //temp1.setName_(name);
                readFile >> damage;
                //temp1.setDamage_(damage);
                readFile >> dmgtype;
                //temp1.setDamageType_(temp1.intToType(type));
                readFile >> range;
                //temp1.setRange_(range);
                readFile >> weight;
                //temp1.setWeight_(weight);
                readFile >> id;
                //temp1.setID_(id);
                readFile >> price;
                //temp1.setPrice_(price);
                outVector.emplace_back(new Weapon(name, damage, weight, id, price, temp1.intToType(dmgtype), range));
            case 1:
                //temp2.setItemType_(temp3.intToType(type));
                readFile >> name;
                //temp2.setName_(name);
                readFile >> damage;
                //temp2.setDamage_(damage);
                readFile >> armortype;
                //temp2.setArmorType(temp2.intToType(armortype));
                readFile >> weight;
                //temp2.setWeight_(weight);
                readFile >> id;
                //temp2.setID_(id);
                readFile >> price;
                //temp2.setPrice_(price);
                outVector.emplace_back(new Armor(name, damage, weight, id, price, temp2.intToType(armortype)));
            case 2:
                //temp3.setItemType_(temp3.intToType(type));
                readFile >> name;
                //temp3.setName_(name);
                readFile >> damage;
                //temp3.setDamage_(damage);
                readFile >> weight;
                //temp3.setWeight_(weight);
                readFile >> id;
                //temp3.setID_(id);
                readFile >> price;
                //temp3.setPrice_(price);
                outVector.emplace_back(new Item(name, damage, temp3.intToType(type), weight, id, price));
        }
    }
    readFile.close();
    return outVector;
}


void System::addItem(const Item &item)
{
    try
    {
        std::vector<Item*>::iterator iter;
        for(iter=itemVector.begin(); iter != itemVector.end(); iter++)
        {
            if((*iter)->ID_() == item.ID_())
            {
                throw std::string("Exception: This item already exists in the vector");
            }
        }
        itemVector.emplace_back(new Item(item));
    }
    catch(const std::string& e)
    {
        std::cerr << e << std::endl;
    }
}
void System::addSpell(const Spell &spell)
{
    try
    {
        std::vector<Spell>::iterator iter;
        for(iter=spellVector.begin(); iter != spellVector.end(); iter++)
        {
            if(iter->get_spellID() == spell.get_spellID())
            {
                throw std::string("Exception: This spell already exists in the vector");
            }
        }
        spellVector.emplace_back(spell);
    }
    catch(const std::string& e)
    {
        std::cerr << e << std::endl;
    }
}
void System::addCharacter(const Character &character)
{
    try
    {
        std::vector<Character>::iterator iter;
        for(iter=characterVector.begin(); iter != characterVector.end(); iter++)
        {
            if(iter->get_character_id() == character.get_character_id())
            {
                throw std::string("Exception: This character already exists in the vector");
            }
        }
        characterVector.emplace_back(character);
    }
    catch(const std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

Character* System::getCharacter(std::string name)
{
    try
    {
        std::vector<Character>::iterator iter;

        for(iter = characterVector.begin(); iter != characterVector.end(); iter++)
        {
            if(iter->get_character_name() == name)
            {
                return &(*iter);
            }
        }
        throw std::string("Exception: Character not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

Item* System::getItem(std::string name)
{
    try
    {
        std::vector<Item*>::iterator iter;

        for(iter = itemVector.begin(); iter != itemVector.end(); iter++)
        {
            if((*iter)->Name_() == name)
            {
                return *iter;
            }
        }
        throw std::string("Exception: Item not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

Spell* System::getSpell(std::string name)
{
    try
    {
        std::vector<Spell>::iterator iter;

        for(iter = spellVector.begin(); iter != spellVector.end(); iter++)
        {
            if(iter->get_spellName() == name)
            {
                return &(*iter);
            }
        }
        throw std::string("Exception: Spell not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}
Character* System::getCharacterByID(int charID)
{
    try
    {
        std::vector<Character>::iterator iter;

        for(iter = characterVector.begin(); iter != characterVector.end(); iter++)
        {
            if(iter->get_character_id() == charID)
            {
                return &(*iter);
            }
        }
        throw std::string("Exception: Character not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}
/*Character* System::getCharacterByPlayer(std::string player)
{
    try
    {
        std::vector<Character>::iterator iter;

        for(iter = characterVector.begin(); iter != characterVector.end(); iter++)
        {
            if(iter->get_player_name() == player)
            {
                return &(*iter);
            }
        }
        throw std::string("Exception: Player not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}*/
Item* System::getItemByID(int itemID)
{
    try
    {
        std::vector<Item*>::iterator iter;

        for(iter = itemVector.begin(); iter != itemVector.end(); iter++)
        {
            if((*iter)->ID_() == itemID)
            {
                return *iter;
            }
        }
        throw std::string("Exception: Item not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

Spell* System::getSpellByID(int spellID)
{
    try
    {
        std::vector<Spell>::iterator iter;

        for(iter = spellVector.begin(); iter != spellVector.end(); iter++)
        {
            if(iter->get_spellID() == spellID)
            {
                return &(*iter);
            }
        }
        throw std::string("Exception: Spell not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

void System::deleteCharacter(std::string name)
{
    int i =0;
    try
    {
        std::vector<Character>::iterator iter;

        for(iter = characterVector.begin(); iter != characterVector.end(); iter++, i++)
        {
            if(iter->get_character_name() == name)
            {
                characterVector.erase(characterVector.begin()+i);
                return;
            }
        }
        throw std::string("Exception: Character not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

void System::deleteItem(std::string name)
{
    int i =0;
    try
    {
        std::vector<Item*>::iterator iter;

        for(iter = itemVector.begin(); iter != itemVector.end(); iter++, i++)
        {
            if((*iter)->Name_() == name)
            {
                itemVector.erase(itemVector.begin()+i);
                return;
            }
        }
        throw std::string("Exception: Item not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

void System::deleteSpell(std::string name)
{
    int i =0;
    try
    {
        std::vector<Spell>::iterator iter;

        for(iter = spellVector.begin(); iter != spellVector.end(); iter++, i++)
        {
            if(iter->get_spellName() == name)
            {
                spellVector.erase(spellVector.begin()+i);
                
                return;
            }
        }
        throw std::string("Exception: Spell not found in vector.");
    }
    catch(std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

System* System::getInstance()
{
    if(!(instance)){
        instance = new System;
    }
    return instance;
}

void System::exportCharactersToFile(std::string characterFilePath){
    std::ofstream characterFile;
    characterFile.open(characterFilePath, std::ios::out);
    std::vector<Character>::iterator characterIterator;
    characterFile << "character records start\n";
    for(characterIterator = characterVector.begin(); characterIterator != characterVector.end(); characterIterator++){
        characterFile << characterIterator->toExportString();
    }
    characterFile << "character records end\n";
}

void System::exportItemsToFile(std::string itemFilePath){
    std::ofstream itemFile;
    itemFile.open(itemFilePath, std::ios::out);
    std::vector<Item*>::iterator itemIterator;
    itemFile << "item records start\n";
    for(itemIterator = itemVector.begin(); itemIterator != itemVector.end(); itemIterator++){
        itemFile << (*itemIterator)->toExportString();
    }
    itemFile << "item records end\n";
}

void System::exportSpellsToFile(std::string spellFilePath){
    std::ofstream spellFile;
    spellFile.open(spellFilePath, std::ios::out);
    std::vector<Spell>::iterator spellIterator;
    spellFile << "spell records start\n";
    for(spellIterator = spellVector.begin(); spellIterator != spellVector.end(); spellIterator++){
        spellFile << spellIterator->toExportString();
    }
    spellFile << "spell records end\n";
}

void System::standardSystemExportToFiles(){
    exportCharactersToFile("charactersExport.txt");
    exportItemsToFile("itemsExport.txt");
    exportSpellsToFile("spellsExport.txt");
}