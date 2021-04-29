#include <iostream>
#include <fstream>
#include "System.h"


System::System(){
}

void System::addItem(const Item &item)
{
    try
    {
        std::vector<Item>::iterator iter;
        for(iter=itemVector.begin(); iter != itemVector.end(); iter++)
        {
            if(iter->ID_() == item.ID_())
            {
                throw std::string("Exception: This item already exists in the vector");
            }
        }
        itemVector.emplace_back(item);
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
        itemVector.emplace_back(spell);
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
        itemVector.emplace_back(character);
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
        std::vector<Item>::iterator iter;

        for(iter = itemVector.begin(); iter != itemVector.end(); iter++)
        {
            if(iter->Name_() == name)
            {
                return &(*iter);
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
        std::vector<Item>::iterator iter;

        for(iter = itemVector.begin(); iter != itemVector.end(); iter++)
        {
            if(iter->ID_() == itemID)
            {
                return &(*iter);
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
        std::vector<Item>::iterator iter;

        for(iter = itemVector.begin(); iter != itemVector.end(); iter++, i++)
        {
            if(iter->Name_() == name)
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
System* System::getInstance(){
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
    std::vector<Item>::iterator itemIterator;
    itemFile << "item records start\n";
    for(itemIterator = itemVector.begin(); itemIterator != itemVector.end(); itemIterator++){
        itemFile << itemIterator->toExportString();
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
        mainMenu();
        break;
    
    default:
        break;
    }
}

void createSpell(){
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
        printSpell();
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
            std::string exportString = newSpell->to_exportString();
            FILE* sFile;
            sFile = fopen(exportfilepath.c_str(), "a");
            if(sFile == NULL){
                std::cout << "unable to open file" << std::endl;
            }
            fprintf(sFile, "%s", exportString);
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
            std::string exportString = newSpell->to_exportString();
            FILE* sFile;
            sFile = fopen(exportfilepath.c_str(), "a");
            if(sFile == NULL){
                std::cout << "unable to open file" << std::endl;
            }
            fprintf(sFile, "%s", exportString);
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
