#include <iostream>
#include <fstream>
#include "System.h"


System::System(){}
System::~System(){}
void System::itemVectorFromFile(std::string filepath)
{
    std::fstream readFile;
    std::vector<Item*>::iterator iter;
    std::vector<Item*> outVector;
    readFile.open(filepath);
    while(!readFile.eof())
    {
        std::string type;
        std::string name;
        std::string damage;
        std::string dmgtype;
        std::string armortype;
        std::string weight;
        std::string id;
        std::string range;
        std::string price;

        Weapon temp1 = Weapon();
        Armor temp2 = Armor();
        Item temp3 = Item();
        std::cout << "Here again\n";
        getline(readFile, type);
        switch(stoi(type))
        {
            case 0:
                getline(readFile,name);
                getline(readFile, damage);
                getline(readFile, dmgtype);
                getline(readFile, range);
                getline(readFile, weight);
                getline(readFile, id);
                getline(readFile, price);
                itemVector.emplace_back(new Weapon(name, damage, stod(weight), stoi(id), stoi(price), temp1.intToType(stoi(dmgtype)), stoi(range)));
                break;
            case 1:
                getline(readFile,name);
                getline(readFile, damage);
                getline(readFile, armortype);
                getline(readFile, weight);
                getline(readFile, id);
                getline(readFile, price);
                std::cout << "Made it this far\n";
                itemVector.emplace_back(new Armor(name, damage, stod(weight), stoi(id), stoi(price), temp2.intToType(stoi(armortype))));
                break;
            case 2:
                getline(readFile,name);
                getline(readFile, damage);
                getline(readFile, weight);
                getline(readFile, id);
                getline(readFile, price);
                itemVector.emplace_back(new Item(name, damage, temp3.intToType(stoi(type)), stod(weight), stoi(id), stoi(price)));
                break;
            default:
                break;
        }
    }
    readFile.close();
}
void System::printItemDetailedList()
{
    std::vector<Item*>::iterator iter;
    for(iter=itemVector.begin(); iter != itemVector.end(); iter++)
    {
        std::cout << (*iter)->to_string();
    }
}
void System::printItemShortList()
{
    std::vector<Item*>::iterator iter;
    for(iter=itemVector.begin(); iter != itemVector.end(); iter++)
    {
        std::cout << (*iter)->to_ShortString();
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
                std::cout << "Please enter its name (string): ";
                std::cin >> itemName;
                std::cout << std::endl;
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
                std::cout << "Please enter its unique ID (integer): ";
                std::cin >> itemID;
                std::cout << std::endl;
                std::cout << "Please enter its price (integer): ";
                std::cin >> itemPrice;
                std::cout << std::endl;
                if(getItem(itemName) != nullptr || getItemByID(itemID) != nullptr)
                {
                    std::cout << "An item of this name or ID already exists. Please try again.\n";
                    break;
                }
                itemVector.emplace_back(new Weapon(itemName, itemDmg, itemWght, itemID, itemPrice, weapon.intToType(itemDmgType), itemRng));
                //break;
            case 2:
                std::cout << "You have chosen to create a piece of armor! Excellent!" << std::endl;
                //do{
                    std::cout << "Please enter its name (string): ";
                    std::cin >> itemName;
                    std::cout << std::endl;
                //}while(getItem(itemName));
                std::cout << "Please enter its damage (string): ";
                std::cin >> itemDmg;
                std::cout << std::endl;
                std::cout << "Please enter its weight (double): ";
                std::cin >> itemWght;
                std::cout << std::endl;
                //do{
                    std::cout << "Please enter its unique ID (integer): ";
                    std::cin >> itemID;
                    std::cout << std::endl;
                //}while(getItemByID(itemID));
                std::cout << "Please enter its price (integer): ";
                std::cin >> itemPrice;
                if(getItem(itemName) != nullptr || getItemByID(itemID) != nullptr)
                {
                    std::cout << "An item of this name or ID already exists. Please try again.\n";
                    break;
                }
                itemVector.emplace_back(new Armor(itemName, itemDmg, itemWght, itemID, itemPrice, armor.intToType(itemArmorType)));
                //break;
            case 3:
                std::cout << "You have chosen to create a piece of armor! Excellent!" << std::endl;
                //do{
                    std::cout << "Please enter its name (string): ";
                    std::cin >> itemName;
                    std::cout << std::endl;
                //}while(getItem(itemName));
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
                //do{
                    std::cout << "Please enter its unique ID (integer): ";
                    std::cin >> itemID;
                    std::cout << std::endl;
                //}while(getItemByID(itemID));
                std::cout << "Please enter its price (integer): ";
                std::cin >> itemPrice;
                if(getItem(itemName) != nullptr || getItemByID(itemID) != nullptr)
                {
                    std::cout << "An item of this name or ID already exists. Please try again.\n";
                    break;
                }
                std::cout << "Thanks for creating an item!\n";
                itemVector.emplace_back(new Armor(itemName, itemDmg, itemWght, itemID, itemPrice, armor.intToType(itemArmorType)));
                //break;
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
                std::cout << (getItemByID(inputID))->to_string();
                break;
            case 2:
                printItemShortList();
                std::cout << "Please Enter the ID of the item you want to edit (integer): ";
                std::cin >> inputID;
                std::cout << std::endl;
                (getItemByID(inputID))->edit();
                break;
            case 3:
                break;
        }
    }while(input > 3 || input < 1);
}
/*Item* System::searchItemByName(std::string name)
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
        return (new Item());
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
        return (new Item());
    }
}*/


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
        return (new Character());
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
        return nullptr;
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
        return (new Spell());
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
        return (new Character());
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
        return (nullptr);
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
        return (new Spell());
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

System& System::getInstance()
{
    static System instance;
    /*if(!(&instance)){
        instance = new System;
    }*/
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

void System::MenuStart(){
    displayApplicationWelcomeMessage();
    bool menuContinue = true;
    itemVectorFromFile("items.txt");

    do{
        displayMainMenu();
        int response;
        std::cin >> response;

        switch(response){
            case 1:
                characterMenu();
            case 2:
                itemMenu();
            case 3:
                spellMenu();
            case 4:
                menuContinue = false;
            default:
                displayDefaultCaseMenuResponse();
                break;
        }
    } while(menuContinue == true);
}

void System::displayDefaultCaseMenuResponse(){
    std::cout << "I'm Sorry, the response we recorded does not match one of the possible, options, please try again" << std::endl;
}

void System::displayMainMenu(){
    std::cout << "Please type the number corresponding to the game element you wish to interact with below..." << std::endl;

    std::cout << "\t1) Characters\n\t2) Items\n\t3) Spells\n\t4) Exit Application" << std::endl;
}

void System::displayApplicationWelcomeMessage(){
    std::cout << "Welcome to the D&D Data Management System! Here you can create, view, and edit various elements of your D&D game!" << std::endl;
}

void System::characterMenu(){
    std::cout << "----------Character Menu----------" << std::endl;
    std::cout << "Please enter your menu choice according to the list below:\n" << std::endl;
    std::cout << "\t1) View/Edit Character\n\t2) Create Character\n" << std::endl;
    std::cout << "Your choice: ";
    int response;
    std::cin >> response;

    switch (response){
        case 1:
            //viewEditCharacterMenu();
        case 2:
            //createCharacterMenu();
        case 3:
            displayDefaultCaseMenuResponse();
    }
}
void viewEditCharacterMenu(){
    std::cout << "Here are the options available to the lookup menu:" << std::endl;
    std::cout << "\t1) View Entire Character Roster\n\t2) Search Character\n\t3) Return\n" << std::endl;
    int response;
    std::cin >> response;
    switch (response){
        case 1:
            //printCharacterList();
        case 2:
            //searchCharacterMenu();
        case 3:
            return;
    }
}

// void System::printCharacterList(){
//     std::cout << "Print the list here"
// }
// void System::searchCharacterMenu(){
//     std::cout << "Search Characters By:" << std::endl;
//     std::cout << "\t1) By ID\n\t2) By Name\n\t3)Return"
// }

void System::spellMenu(){
    std::cout << "1. View/Edit a spell \n2. Create a new spell\n3. Back to main menu" << std::endl;
    int input = 0;
    do{
        std::cout << "Type the number of the option you would like to do" << std::endl;
        std::cin >> input;
    }while(input > 3 || input < 1);
    
    switch (input)
    {
    case 1:
        veSpellMenu();
        break;
    case 2:
        createSpell();
        break;
    case 3:
        displayMainMenu();
        break;
    
    default:
        break;
    }
}

void System::createSpell(){
    std::cout << "Please type in the name of the spell you would like to add\n";
    std::string spellName;
    getline(std::cin, spellName);
    std::cout << "Please type an integer to represent the Spell ID\n";
    int spellID;
    std::cin >> spellID;
    std::cout << "Please type an integer for the casting time of the spell. This is in terms of actions.\n";
    int castingTime;
    std::cin >> castingTime;
    std::cout << "Please type an integer for the range of the spell. This is in terms of feet.\n";
    int range;
    std::cin >> range;
    std::cout << "Please type an integer for the duration of the spell. This is in terms of hours.\n";
    int duration;
    std::cin >> duration;
    std::cout << "Finally, please type a short description of the spell";
    std::string description;
    getline(std::cin, description);

    Spell newSpell(spellName, spellID, description, castingTime, range, duration);
    std::cout << "Your new spell is:\n" << newSpell.to_string() << std::endl;
    addSpell(newSpell);
}

void System::printSpellShortList()
{
    //std::vector<Spell*>::iterator iter;
    for(auto iter=spellVector.begin(); iter != spellVector.end(); iter++)
    {
        iter->to_simpleString();
    }
}

void System::veSpellMenu(){
    std::cout << "1. View whole list \n2. Find a certain spell\n3. Back to spell menu" << std::endl;
    int input = 0;
    do{
        std::cout << "Type the number of the option you would like to do" << std::endl;
        std::cin >> input;
    }while(input > 3 || input < 1);
    switch (input)
    {
    case 1: 
        printSpellShortList();
        break;
    case 2:
        certainSpellMenu();
        break;
    case 3:
        spellMenu();
        break;
    
    default:
        break;
    }
}

void System::certainSpellMenu(){
    std::cout << "1. Search spell by name \n2. Search spell by ID\n3. Back to view/edit menu" << std::endl;
    int input = 0;
    do{
        std::cout << "Type the number of the option you would like to do" << std::endl;
        std::cin >> input;
    }while(input > 3 || input < 1);
    switch (input)
    {
    case 1:
    {
        std::cout << "Please type the name of the spell you would like to find\n";
        std::string spellName;
        getline(std::cin, spellName);
        Spell* newSpell = getSpell(spellName);
        std::cout << newSpell->to_string() << std::endl;
        std::cout << "Would you like to edit this spell. Type 1 for yes or 0 for no." << std::endl;
        int input=-1;
        std::cin >> input;
        if(input == 1){
            editSpell(newSpell);
        }
        std::cout << "Would you like to export this spell to a file. Type 1 for yes or 0 for no." <<std::endl;
        int input2=-1;
        std::cin >> input2;
        if(input2 == 1){
            std::cout << "Please enter the name of the file where you would like the spell to be stored. (ex. exportfilepath.txt)" <<std::endl;
            std::string exportfilepath;
            getline(std::cin, exportfilepath);
            std::string exportString = newSpell->toExportString();
            FILE* sFile;
            sFile = fopen(exportfilepath.c_str(), "a");
            if(sFile == NULL){
                std::cout << "unable to open file" << std::endl;
            }
            fprintf(sFile, "%s", exportString.c_str());
            fclose(sFile);
        }
        break;
    }
    case 2:
    {
        std::cout << "Please type the ID of the spell you would like to find\n";
        int spellID;
        std::cin >> spellID;
        Spell* newSpell = getSpellByID(spellID);
        std::cout << newSpell->to_string() << std::endl;
        std::cout << "Would you like to edit this spell. Type 1 for yes or 0 for no." << std::endl;
        int input;
        std::cin >> input;
        if(input == 1){
            editSpell(newSpell);
        }
        break;
        std::cout << "Would you like to export this spell to a file. Type 1 for yes or 0 for no." <<std::endl;
        int input2=-1;
        std::cin >> input2;
        if(input2 == 1){
            std::cout << "Please enter the name of the file where you would like the spell to be stored. (ex. exportfilepath.txt)" <<std::endl;
            std::string exportfilepath;
            getline(std::cin, exportfilepath);
            std::string exportString = newSpell->toExportString();
            FILE* sFile;
            sFile = fopen(exportfilepath.c_str(), "a");
            if(sFile == NULL){
                std::cout << "unable to open file" << std::endl;
            }
            fprintf(sFile, "%s", exportString.c_str());
            fclose(sFile);
        }
    }
    case 3:
    {
        veSpellMenu();
        break;
    }
    
    default:
    {
        break;
    }
    }
}

void System::editSpell(Spell* editSpell){
    std::cout << "Enter the new name of the spell\n";
    std::string spellName;
    getline(std::cin, spellName);
    std::cout << "Enter the new spell ID\n";
    int spellID;
    std::cin >> spellID;
    std::cout << "Enter the new casting time for the spell. This is in terms of actions.\n";
    int castingTime;
    std::cin >> castingTime;
    std::cout << "Enter the new range of the spell. This is in terms of feet.\n";
    int range;
    std::cin >> range;
    std::cout << "Enter the new duration of the spell. This is in terms of hours.\n";
    int duration;
    std::cin >> duration;
    std::cout << "Finally, please enter the new description of the spell";
    std::string description;
    getline(std::cin, description);

    editSpell->set_spellName(spellName);
    editSpell->set_spellID(spellID);
    editSpell->set_description(description);
    editSpell->set_castingTime(castingTime);
    editSpell->set_range(range);
    editSpell->set_duration(duration);
}
