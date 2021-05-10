#include "System.h"
#include "Weapon.h"
#include "Armor.h"
#include <fstream>

System *System::instance = nullptr;

System::System(){
    this->itemList = new EntityList<Item*>();
    this->characterList = new EntityList<Character*>();
    this->spellList = new EntityList<Spell*>();
}
System::~System(){
    delete itemList;
    delete characterList;
    delete spellList;
}
void System::StartMenu(){
    bool continueOption = true;
    do{
        std::cout << "Main Menu. Pick and Option Below" << std::endl;
        std::cout << "\t1) Character\n\t2) Item\n\t3) Spell\n\t4) Exit" << std::endl;
        int response;
        std::cin >> response;
        switch (response){
             case 1:
                 changeMenuMode(CHARACTER);
                 EntityMenu<Character>(characterList);
                 break;
            case 2:
                changeMenuMode(ITEM);
                EntityMenu<Item>(itemList);
                break;
            case 3:
                changeMenuMode(SPELL);
                EntityMenu<Spell>(spellList);
                break;
        
            default:
                continueOption = false;
        }
    }while(continueOption == true);
}

void System::importEntityLists(){
    std::ifstream itemFile("ItemListExport.txt");
    int id;
    while(itemFile >> id){
        Item *item = readItemFromFile(itemFile, id);
        if(item != NULL){
            itemList->addEntity(item);
        }
    }
    itemList->printList();

    std::ifstream spellFile("SpellListExport.txt");
    while(spellFile >> id){
        Spell *spell = readSpellFromFile(spellFile, id);
        if(spell != NULL){
            spellList->addEntity(spell);
        }
    }
    spellList->printList();

    std::ifstream characterFile("CharacterListExport.txt");
    while(characterFile >> id){
        Character *character = readCharacterFromFile(characterFile, id);
        if(character != NULL){
            characterList->addEntity(character);
        }
    }
}

template<typename E>
void System::EntityMenu(EntityList<E*>* list){
    std::cout << "Welcome to the " << menuModeString << " Entity Menu\nPlease select an option below" << std::endl;
    std::cout << "\t1) View/Edit Existing " << menuModeString << std::endl;
    std::cout << "\t2) Create New " << menuModeString << std::endl;
    std::cout << "\t3) Exit" << std::endl;
    int response;
    std::cin >> response;
    switch (response){
        case 1:
            std::cout << "Option 1" << std::endl;
            ViewEditMenu<E*>(list);
            break;
        case 2:
        std::cout << "Option 2" << std::endl;
            E::CreateMenu(list);
        default:
            return;
    }
}
template<typename E>
void System::ViewEditMenu(EntityList<E>* list){
        std::cout << "Welcome to the View/Edit " << menuModeString << " Menu\nPlease select an option below" << std::endl;
        std::cout << "\t1) View List of Existing " << menuModeString << std::endl;
        std::cout << "\t2) Look up " << menuModeString << std::endl;
        std::cout << "\t3) Exit" << std::endl;
        int response;
        std::cin >> response;
        switch (response)
        {
        case 1:
            std::cout << "You've selected to view the list of all existing " << menuModeString << "!" << std::endl;
            std::cout << "Here are all the " << menuModeString << " stored in the database:" << std::endl;
            list->printList();
            break;
        case 2:
            SearchListMenu<E>(list);
        default:
            return;
            break;
        }
    }
template<typename E>
void System::SearchListMenu(EntityList<E>* list){
    std::cout << "You've selected to look up an existing " << menuModeString << "\nPlease Select an option below." << std::endl;
    std::cout << "\t1) Search " << menuModeString << " by ID\n\t2) Search " << menuModeString << "by Name\n\t3) Exit" << std::endl;
    E entity;
    int response;
    std::cin >> response;
    int ID;
    std::string name;
    switch (response){
        case 1:
            std::cout << "Enter the ID: ";
            std::cin >> ID;
            entity = list->searchForEntityByID(ID);
            break;
        case 2:
            std::cout << "Enter the name: ";
            std::cin >> name;
            entity = list->searchForEntityByName(name);
            break;
        default:
            return;
    }

    std::cout << "View or Edit?" << std::endl;
    std::cout << "\t1)View" << std::endl;
    std::cout << "\t2)Edit" << std::endl;
    std::cout << "\t3)Return" << std::endl;
    std::cin >> response;
    switch(response){
        case 1:
            entity->longPrint();
            break;
        case 2:
            entity->EditMenu();
            break;
        default:
            return;
    }

}

void System::changeMenuMode(MenuModeType menuMode){
    this->menuMode = menuMode;
    switch (this->menuMode){
        case CHARACTER:
            menuModeString = "Character";
            break;
        case ITEM:
            menuModeString = "Item";
            break;
        case SPELL:
            menuModeString = "Spell";
            break;
        default:
            menuModeString = "";
            break;
    }
}

Item* System::readItemFromFile(std::ifstream& file, int id){
    std::string itemName;
    std::string damage;
    double weight;
    int price;
    std::string itemTypeString;
    std::getline(file, itemName); //clear buffer
    std::getline(file, itemName);
    std::getline(file, damage);
    file >> weight;
    file >> price;
    std::getline(file, itemTypeString); //clear buffer
    std::getline(file, itemTypeString);
    if(itemTypeString.compare("OBJECT") == 0){
        Item* item = new Item(itemName, damage, OBJECT, weight, id, price);
        std::cout << item->to_string();
        return item;
    } else if(itemTypeString.compare("WEAPON") == 0){
        int damageTypeInt;
        int range;
        file >> damageTypeInt;
        DMGType dmgType = Weapon::intToType(damageTypeInt);
        file >> range;
        Weapon* weapon = new Weapon(itemName, damage, weight, id, price, dmgType, range);
        return weapon;
    } else if(itemTypeString.compare("ARMOR") == 0){
        int armorTypeInt;
        file >> armorTypeInt;
        ArmorType ArmorType = Armor::intToType(armorTypeInt);
        Armor* armor = new Armor(itemName, damage, weight, id, price, ArmorType);
        return armor;
    } else{
        std::cout << "Error Reading Item" << std::endl;
        return NULL;
    }
}
Spell* System::readSpellFromFile(std::ifstream& file, int id){
    std::string spellName;
    std::string description;
    int castingTime;
    int range;
    int duration;
    std::getline(file, spellName); //clears buffer
    std::getline(file, spellName);
    std::getline(file, description);
    file >> castingTime;
    file >> range;
    file >> duration;
    Spell *spell = new Spell(spellName, id, description, castingTime, range, duration);
    return spell;
}

Character* System::readCharacterFromFile(std::ifstream& file, int id){
    std::string characterName;
    std::string playerName;
    int classInt;
    int raceInt;
    int level;
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    EntityList<Item*>* itemInventory = new EntityList<Item*>();
    EntityList<Spell*>* spellInventory = new EntityList<Spell*>();
    int goldCount;
    std::getline(file, characterName); //clears buffer
    std::getline(file, characterName);
    std::getline(file, playerName);
    file >> classInt;
    file >> raceInt;
    file >> level;
    file >> strength;
    file >> dexterity;
    file >> constitution;
    file >> intelligence;
    file >> wisdom;
    file >> charisma;
    int itemID;
    file >> itemID;
    while(itemID != -1){
        Item *item = itemList->searchForEntityByID(itemID);
        if(item){
            itemInventory->addEntity(item);
        } else{
            std::cout << "Item with ID " << itemID << " could not be found in your system, was not added to Character" << std::endl;
        }
        file >> itemID;
    }
    int spellID;
    file >> spellID;
    while(spellID != -1){
        Spell *spell = spellList->searchForEntityByID(spellID);
        if(spell){
            spellInventory->addEntity(spell);
        } else{
            std::cout << "Spell with ID " << spellID << " could not be found in your system, was not added to Character" << std::endl;
        }
        file >> spellID;
    }
    file >> goldCount;
    CharacterClass characterClass = Character::intToClass(classInt);
    Race race = Character::intToRace(raceInt);
    AbilityScores* abilityScores = new AbilityScores(strength, dexterity, constitution, intelligence, wisdom, charisma);
    Character* character = new Character(playerName, characterName, id, characterClass, race, level, abilityScores, itemInventory, spellInventory, goldCount);
    character->setItems(itemInventory);
    character->setSpells(spellInventory);
    return character;
}