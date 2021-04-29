#include <iostream>
#include <fstream>
#include "System.h"


System::System(){
}
void System::itemVectorFromFile(std::string filepath)
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
                readFile >> name;
                readFile >> damage;
                readFile >> dmgtype;
                readFile >> range;
                readFile >> weight;
                readFile >> id;
                readFile >> price;
                itemVector.emplace_back(new Weapon(name, damage, weight, id, price, temp1.intToType(dmgtype), range));
            case 1:
                readFile >> name;
                readFile >> damage;
                readFile >> armortype;
                readFile >> weight;
                readFile >> id;
                readFile >> price;
                itemVector.emplace_back(new Armor(name, damage, weight, id, price, temp2.intToType(armortype)));
            case 2:
                readFile >> name;
                readFile >> damage;
                readFile >> weight;
                readFile >> id;
                readFile >> price;
                itemVector.emplace_back(new Item(name, damage, temp3.intToType(type), weight, id, price));
        }
    }
    readFile.close();
}
void System::printItemDetailedList()
{
    std::vector<Item*>::iterator iter;
    for(iter=itemVector.begin(); iter != itemVector.end(); iter++)
    {
        (*iter)->to_string();
    }
}
void System::printItemShortList()
{
    std::vector<Item*>::iterator iter;
    for(iter=itemVector.begin(); iter != itemVector.end(); iter++)
    {
        (*iter)->to_ShortString();
    }
}
void System::createItem()
{
    Weapon weapon;
    Item item;
    Armor armor;
    int select = 0;
    do{
        std::cout << "1. Create Weapon" << std::endl;
        std::cout << "2. Create Armor" << std::endl;
        std::cout << "3. Create Object" << std::endl;
        std::cout << "4. Go Back" << std::endl;
        std::cout << "Please enter what type of item you would like to create (1, 2, or 3): ";
        std::cin >> select;
        std::cout << std::endl;
        std::string itemName;
        std::string itemDmg;
        int itemDmgType;
        int itemArmorType;
        double itemWght;
        int itemID;
        int itemRng;
        int itemPrice;
        switch(select)
        {
            case 1:
                std::cout << "You have chosen to create a weapon! Excellent!" << std::endl;
                do{
                    std::cout << "Please enter its name (string): ";
                    std::cin >> itemName;
                    std::cout << std::endl;
                }while(searchItemByName(itemName));
                std::cout << "Please enter its damage (string): ";
                std::cin >> itemDmg;
                std::cout << std::endl;
                std::cout << "0. FIRE" << std::endl;
                std::cout << "1. COLD" << std::endl;
                std::cout << "2. LIGHTNING" << std::endl;
                std::cout << "3. ACID" << std::endl;
                std::cout << "4. SLASHING" << std::endl;
                std::cout << "5. POISON" << std::endl;
                std::cout << "Please enter its damage type (integer): ";
                std::cin >> itemDmgType;
                std::cout << std::endl;
                std::cout << "Please enter its range (integer): ";
                std::cin >> itemRng;
                std::cout << std::endl;
                std::cout << "Please enter its weight (double): ";
                std::cin >> itemWght;
                std::cout << std::endl;
                do{
                    std::cout << "Please enter its unique ID (integer): ";
                    std::cin >> itemID;
                    std::cout << std::endl;
                }while(searchItemByID(itemID));
                std::cout << "Please enter its price (integer): ";
                std::cin >> itemPrice;
                std::cout << std::endl;
                itemVector.emplace_back(new Weapon(itemName, itemDmg, itemWght, itemID, itemPrice, weapon.intToType(itemDmgType), itemRng));
                break;
            case 2:
                std::cout << "You have chosen to create a piece of armor! Excellent!" << std::endl;
                do{
                    std::cout << "Please enter its name (string): ";
                    std::cin >> itemName;
                    std::cout << std::endl;
                }while(searchItemByName(itemName));
                std::cout << "Please enter its damage (string): ";
                std::cin >> itemDmg;
                std::cout << std::endl;
                std::cout << "Please enter its weight (double): ";
                std::cin >> itemWght;
                std::cout << std::endl;
                do{
                    std::cout << "Please enter its unique ID (integer): ";
                    std::cin >> itemID;
                    std::cout << std::endl;
                }while(searchItemByID(itemID));
                std::cout << "Please enter its price (integer): ";
                std::cin >> itemPrice;
                itemVector.emplace_back(new Armor(itemName, itemDmg, itemWght, itemID, itemPrice, armor.intToType(itemArmorType)));
                break;
            case 3:
                std::cout << "You have chosen to create a piece of armor! Excellent!" << std::endl;
                do{
                    std::cout << "Please enter its name (string): ";
                    std::cin >> itemName;
                    std::cout << std::endl;
                }while(searchItemByName(itemName));
                std::cout << "Please enter its damage (string): ";
                std::cin >> itemDmg;
                std::cout << std::endl;
                std::cout << "0. LIGHT" << std::endl;
                std::cout << "1. MEDIUM" << std::endl;
                std::cout << "2. HEAVY" << std::endl;
                std::cout << "Please enter its armor type (integer): ";
                std::cin >> itemArmorType;
                std::cout << std::endl;
                std::cout << "Please enter its weight (double): ";
                std::cin >> itemWght;
                std::cout << std::endl;
                do{
                    std::cout << "Please enter its unique ID (integer): ";
                    std::cin >> itemID;
                    std::cout << std::endl;
                }while(searchItemByID(itemID));
                std::cout << "Please enter its price (integer): ";
                std::cin >> itemPrice;
                itemVector.emplace_back(new Armor(itemName, itemDmg, itemWght, itemID, itemPrice, armor.intToType(itemArmorType)));
                break;
            default:
                break;
        }
    }while(select > 4 || select < 1); 
}
void System::itemMenu()
{
    int input = 0;
    do{
        std::cout << "1. View/Edit an Item" << std::endl;
        std::cout << "2. Create an Item" << std::endl;
        std::cout << "3. Go back" << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "Enter your choice here (integer): ";
        std::cin >> input;
        std::cout << std::endl;
        switch(input)
        {
            case 1:
                editItem();
            case 2:
                createItem();
            case 3: 
                break;
            default:
                break;
        }
    }while(input > 3 || input < 1);
}
void System::editItem()
{
    int input = 0;
    do{
        std::cout << "1. View an Item" << std::endl;
        std::cout << "2. Edit an Item" << std::endl;
        std::cout << "3. Go back" << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "Enter your choice here (integer): ";
        std::cin >> input;
        std::cout << std::endl;
        int inputID = 0;
        switch(input)
        {
            case 1:
                printItemShortList();
                std::cout << "Please Enter the ID of the item you want to view (integer): ";
                std::cin >> inputID;
                std::cout << std::endl;
                (searchItemByID(inputID))->to_string();
            case 2:
                printItemShortList();
                std::cout << "Please Enter the ID of the item you want to edit (integer): ";
                std::cin >> inputID;
                std::cout << std::endl;
                (searchItemByID(inputID))->edit();
            case 3:
                break;
            default:
                break;
        }
    }while(input > 3 || input < 1);
}
Item* System::searchItemByName(std::string name)
{
    try
    {
        std::vector<Item*>::iterator iter;
        for(iter=itemVector.begin(); iter != itemVector.end(); iter++)
        {
            if((*iter)->Name_() == name)
            {
                return *iter;
            }
        }
        throw(std::string("ERROR: THIS ITEM DOES NOT EXIST!!!!!")); 
    }
    catch(const std::string& e)
    {
        std::cerr << e << std::endl;
    }
}

Item* System::searchItemByID(int ID)
{
    try
    {
        std::vector<Item*>::iterator iter;
        for(iter=itemVector.begin(); iter != itemVector.end(); iter++)
        {
            if((*iter)->ID_() == ID)
            {
                return *iter;
            }
        }
        throw(std::string("ERROR: THIS ITEM DOES NOT EXIST!!!!!")); 
    }
    catch(const std::string& e)
    {
        std::cerr << e << std::endl;
    }
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