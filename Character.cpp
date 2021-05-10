#include "Character.h"
#include "System.h"

Character::Character() {}
Character::~Character() {
    delete scores_;
    delete items_;
    delete spells_;
}
Character::Character(
    std::string player_name, std::string name, int id, CharacterClass character_class,
    Race race, int level, AbilityScores* ability_scores, EntityList<Item *> *item_inventory,
    EntityList<Spell *> *spell_inventory, int gold_count)
{
    player_ = player_name;
    setName(name);
    setID(id);
    class_ = character_class;
    race_ = race;
    level_ = level;
    scores_ = ability_scores;
    items_ = item_inventory;
    spells_ = spell_inventory;
    gold_ = gold_count;
}
std::string Character::getPlayer() const { return player_; }
CharacterClass Character::getClass() const { return class_; }
Race Character::getRace() const { return race_; }
int Character::getLevel() const { return level_; }
AbilityScores* Character::getScores() const { return scores_; }
EntityList<Item *> *Character::getItems() const { return items_; }
EntityList<Spell *> *Character::getSpells() const { return spells_; }
int Character::getGold() const { return gold_; }

void Character::setPlayer(std::string player)
{
    player_ = player;
}
void Character::setClass(CharacterClass newClass)
{
    class_ = newClass;
}
void Character::setRace(Race race)
{
    race_ = race;
}
void Character::setLevel(int level)
{
    level_ = level;
}
void Character::setScores(AbilityScores *scores)
{
    scores_->setStrength(scores->getStrength());
    scores_->setDexterity(scores->getDexterity());
    scores_->setConstitution(scores->getConstitution());
    scores_->setIntelligence(scores->getIntelligence());
    scores_->setWisdom(scores->getWisdom());
    scores_->setCharisma(scores->getCharisma());
}
void Character::setItems(EntityList<Item *> *items)
{
    items_ = items;
}
void Character::setSpells(EntityList<Spell *> *spells)
{
    spells_ = spells;
}
void Character::setGold(int gold)
{
    gold_ = gold;
}

void Character::longPrint()
{
    std::cout << to_string();
}

std::string Character::toExportString()
{
    std::stringstream exportString;
    exportString << getID() << std::endl;
    exportString << getName() << std::endl;
    exportString << getPlayer() << std::endl;
    exportString << classToInt(getClass()) << std::endl;
    exportString << raceToInt(getRace()) << std::endl;
    exportString << getLevel() << std::endl;
    exportString << getScores()->toExportString();
    exportString << itemsToExport();
    exportString << spellsToExport();
    exportString << getGold();
    return exportString.str();
}

std::string Character::to_string()
{
    std::stringstream outStream;
    outStream << "NAME: " << getName() << std::endl;
    outStream << "PLAYER: " << getPlayer() << std::endl;
    outStream << "CLASS: " << classToString(getClass()) << std::endl;
    outStream << "RACE: " << raceToString(getRace()) << std::endl;
    outStream << "GOLD: " << getGold() << std::endl;
    outStream << "LEVEL: " << getLevel() << std::endl;
    outStream << "ABILITY SCORES: " << std::endl;
    outStream << scores_->toString();
    outStream << "ITEM INVENTORY:" << std::endl;
    outStream << getItems()->getStringListOfNames() << std::endl;
    outStream << "SPELL BOOK:" << std::endl;
    outStream << getSpells()->getStringListOfNames() << std::endl;
    return outStream.str();
}


std::string Character::itemsToExport(){
    std::stringstream exportString; 
    exportString << getItems()->getStringListOfIDs();
    exportString << "-1" << std::endl;

    return exportString.str();
}

std::string Character::itemsToString()
{
    std::stringstream exportString;
    exportString << getItems()->exportListToString();
    exportString << "END ITEM INVENTORY: " << std::endl;
    return exportString.str();
}

std::string Character::spellsToExport()
{
    std::stringstream exportString;
    exportString << getSpells()->getStringListOfIDs();
    exportString << "-1" << std::endl;
    return exportString.str();
}

std::string Character::spellsToString()
{
    std::stringstream exportString;
    exportString << "SPELL INVENTORY: " << std::endl;
    exportString << getSpells()->getStringListOfIDs();
    exportString << "END SPELL INVENTORY: ";
    return exportString.str();
}

std::string Character::raceToString(Race race)
{
    switch (race)
    {
    case ELF:
        return "Elf";
    case HUMAN:
        return "Human";
    case DWARF:
        return "Dwarf";
    case HALF_ORC:
        return "Half Orc";
    case GNOME:
        return "Gnome";
    default:
        return "";
        break;
    }
}

std::string Character::classToString(CharacterClass characterClass)
{
    switch (characterClass)
    {
    case PALADIN:
        return "Paladin";
    case FIGHTER:
        return "Fighter";
    case ROGUE:
        return "Rogue";
    case CLERIC:
        return "Cleric";
    case RANGER:
        return "Ranger";
    case WIZARD:
        return "Wizard";
    default:
        return "UNKNOWN";
        break;
    }
}

int Character::classToInt(CharacterClass class_)
{
    switch (class_)
    {
    case PALADIN:
        return 0;
    case FIGHTER:
        return 1;
    case ROGUE:
        return 2;
    case CLERIC:
        return 3;
    case RANGER:
        return 4;
    case WIZARD:
        return 5;
    default:
        return -1;
        break;
    }
}
int Character::raceToInt(Race race_)
{
    switch (race_)
    {
    case ELF:
        return 0;
    case HUMAN:
        return 1;
    case DWARF:
        return 2;
    case HALF_ORC:
        return 3;
    case GNOME:
        return 4;
    default:
        return -1;
        break;
    }
}

CharacterClass Character::intToClass(int class_)
{
    switch (class_)
    {
    case 0:
        return PALADIN;
    case 1:
        return FIGHTER;
    case 2:
        return ROGUE;
    case 3:
        return CLERIC;
    case 4:
        return RANGER;
    case 5:
        return WIZARD;
    default:
        return PALADIN;
        break;
    }
}

Race Character::intToRace(int race_)
{
    switch (race_)
    {
    case 0:
        return ELF;
    case 1:
        return HUMAN;
    case 2:
        return DWARF;
    case 3:
        return HALF_ORC;
    case 4:
        return GNOME;
    default:
        return HUMAN;
        break;
    }
}

void Character::printClasses()
{
    std::cout << "0. Paladin" << std::endl;
    std::cout << "1. Fighter" << std::endl;
    std::cout << "2. Rogue" << std::endl;
    std::cout << "3. Cleric" << std::endl;
    std::cout << "4. Ranger" << std::endl;
    std::cout << "5. Wizard" << std::endl;
}

void Character::printRaces()
{
    std::cout << "0. Elf" << std::endl;
    std::cout << "1. Human" << std::endl;
    std::cout << "2. Dwarf" << std::endl;
    std::cout << "3. Half Orc" << std::endl;
    std::cout << "4. Gnome" << std::endl;
}

void Character::CreateMenu(EntityList<Character *> *list)
{
    std::string player = "";
    std::string name = "";
    int id = 0;
    int characterClassInt = 0;
    int raceInt = 0;
    int level = 0;
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    EntityList<Item *> *newItems = new EntityList<Item *>();
    EntityList<Spell *> *newSpells = new EntityList<Spell *>();
    int gold = 0;
    std::cout << "Please Enter the Character name: ";
    std::getline(std::cin, name);
    std::getline(std::cin, name);
    std::cout    << "Please Enter the Player name: ";
    std::getline(std::cin, player);
    std::cout << "Please Enter the Character ID: ";
    std::cin >> id;
    std::cout << "Please Enter the Character level: ";
    std::cin >> level;
    printClasses();
    std::cout << "Please Enter the Character Class: ";
    std::cin >> characterClassInt;
    std::cout << "Please enter your Strength: ";
    std::cin >> strength;
    std::cout << "Please enter your Dexterity: ";
    std::cin >> dexterity;
    std::cout << "Please enter  Constitution: ";
    std::cin >> constitution;
    std::cout << "Please enter your Intelligence: ";
    std::cin >> intelligence;
    std::cout << "Please enter your Wisdom: ";
    std::cin >> wisdom;
    std::cout << "Please enter your Charisma: ";
    std::cin >> charisma;
    printRaces();
    std::cout << "Please Enter the Character Race: ";
    std::cin >> raceInt;
    std::cout << "Please Enter the Character's Gold Count: ";
    std::cin >> gold;
    std::cout << "Here is a list of the items you can choose from: " << std::endl;
    System::getInstance()->getItemList()->printList();
    int input = 0;
    do
    {
        std::cout << "Enter the ID of the item you'd like to add to your inventory: " << std::endl;
        std::cout << "Enter -1 if you'd like to continue without changes: ";
        std::cin >> input;
        Item* item = System::getInstance()->getItemList()->searchForEntityByID(input);
        if(item != nullptr){
            newItems->addEntity(item);
        }
        else{
            std::cout << "I'm sorry, that spell was not found and cannot be added to your character" << std::endl;
        }
    }while(input >= 0 || input != -1);
    
    std::cout << "Here is a list of the spells you can choose from: " << std::endl;
    System::getInstance()->getSpellList()->printList();
    input = 0;
    do
    {
        std::cout << "Enter the ID of the spell you'd like to add to your inventory: " << std::endl;
        std::cout << "Enter -1 if you'd like to continue without changes: ";
        std::cin >> input;
        Spell* spell = System::getInstance()->getSpellList()->searchForEntityByID(input);
        if (spell != nullptr){
            newSpells->addEntity(System::getInstance()->getSpellList()->searchForEntityByID(input));
        }
        else{
            std::cout << "I'm sorry, that spell was not found and cannot be added to your character" << std::endl;
        }
    } while (input >= 0 || input != -1);
    AbilityScores* scores = new AbilityScores(strength, dexterity, constitution, intelligence, wisdom, charisma);
    CharacterClass characterClass = Character::intToClass(characterClassInt);
    Race race = Character::intToRace(raceInt);
    Character *temp = new Character(player, name, id, characterClass, race, level, scores, newItems, newSpells, gold);
    temp->setItems(newItems);
    temp->setSpells(newSpells);
    std::cout << temp->getName() << std::endl;
    std::cout << temp->getID() << std::endl;
    std::cout << raceToString(temp->getRace()) << std::endl;
    std::cout << classToString(temp->getClass()) << std::endl;
    std::cout << temp->getItems() << std::endl;
    std::cout << temp->getSpells() << std::endl;
    list->addEntity(temp);
}

void Character::EditMenu()
{
    std::string player = "";
    std::string name = "";
    int id = 0;
    int tempClass = 0;
    int race = 0;
    int level = 0;
    int tempScore = 0;
    EntityList<Item *> newItems;
    EntityList<Spell *> newSpells;
    int gold = 0;
    std::cout << "Please Enter the Character name: ";
    getline(std::cin, name);
    getline(std::cin, name);
    this->setName(name);
    std::cout << std::endl << "Please Enter the Player name: ";
    getline(std::cin, player);
    this->setPlayer(player);
    std::cout << std::endl << "Please Enter the Character ID: ";
    std::cin >> id;
    this->setID(id);
    std::cout << std::endl;
    std::cout << std::endl
              << "Please Enter the Character level: ";
    std::cin >> level;
    this->setLevel(level);
    std::cout << std::endl;
    printClasses();
    std::cout << std::endl << "Please Enter the Character Class: ";
    std::cin >> tempClass;
    this->setClass(intToClass(tempClass));
    std::cout << scores_->toString();
    std::cout << "Please enter your strength: ";
    std::cin >> tempScore;
    this->scores_->setStrength(tempScore);
    std::cout << "Please enter your dexterity: ";
    std::cin >> tempScore;
    this->scores_->setDexterity(tempScore);
    std::cout << "Please enter your constitution: ";
    std::cin >> tempScore;
    this->scores_->setConstitution(tempScore);
    std::cout << "Please enter your intelligence: ";
    std::cin >> tempScore;
    this->scores_->setIntelligence(tempScore);
    std::cout << "Please enter your wisdom: ";
    std::cin >> tempScore;
    this->scores_->setWisdom(tempScore);
    std::cout << std::endl;
    std::cout << "Please enter your charisma: ";
    std::cin >> tempScore;
    this->scores_->setCharisma(tempScore);
    printRaces();
    std::cout << "Please Enter the Character Race: ";
    std::cin >> race;
    this->setRace(intToRace(race));
    std::cout << "Please Enter the Character's Gold Count: ";
    std::cin >> gold;
    this->setGold(gold);
    std::cout << "Here is a list of the items you have: " << std::endl;
    getItems()->printList();
    int input = 1;
    std::cout << "These are the items you can add: " << std::endl;
    System::getInstance()->getItemList()->printList();
    input = 1;
    do
    {
        std::cout << "Enter the ID of the item you'd like to add to your inventory: " << std::endl;
        std::cout << "Enter -1 if you'd like to continue without changes: ";
        std::cin >> input;
        std::cout << std::endl;
        if (input != -1)
        {
            if (System::getInstance()->getItemList()->searchForEntityByID(input) != nullptr)
            {
                getItems()->addEntity(System::getInstance()->getItemList()->searchForEntityByID(input));
            }
        }
    } while (input >= 0 || input != -1);
    std::cout << "Here is a list of your spells: " << std::endl;
    getSpells()->printList();
    input = 1;
    std::cout << "Here are the spells you can add to your inventory: " << std::endl;
    System::getInstance()->getSpellList()->printList();
    input = 1;
    do
    {
        std::cout << "Enter the ID of the spell you'd like to add to your inventory: " << std::endl;
        std::cout << "Enter -1 if you'd like to continue without changes: ";
        std::cin >> input;
        std::cout << std::endl;
        if (input != -1)
        {
            if (System::getInstance()->getSpellList()->searchForEntityByID(input) != nullptr)
            {
                getSpells()->addEntity(System::getInstance()->getSpellList()->searchForEntityByID(input));
            }
        }
    } while (input >= 0 || input != -1);
}