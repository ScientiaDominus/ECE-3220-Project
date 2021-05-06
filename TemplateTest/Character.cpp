#include "Character.h"
Character::Character(){}
Character::~Character(){}
Character::Character(
                    std::string player_name, std::string name, int id, CharacterClass character_class,
                    Race race, int level, AbilityScores ability_scores, EntityList<Item*> *item_inventory,
                    EntityList<Spell*> *spell_inventory, int gold_count){
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
std::string Character::getPlayer() const{return player_;}
CharacterClass Character::getClass() const{return class_;}
Race Character::getRace() const{return race_;}
int Character::getLevel() const{return level_;}
AbilityScores Character::getScores() const{return scores_;}
EntityList<Item*>* Character::getItems() const{return items_;}
EntityList<Spell*>* Character::getSpells() const{return spells_;}
int Character::getGold() const{return gold_;}

void Character::longPrint()
{
    std::cout << to_string();
}

std::string Character::toExportString(){
    std::stringstream exportString;
    exportString << getName() << std::endl;
    exportString << getPlayer() << std::endl;
    exportString << classToInt(getClass()) << std::endl;
    exportString << raceToInt(getRace()) << std::endl;
    exportString << getLevel() << std::endl;
    exportString << getScores().toExportString();
    exportString << itemsToExport();
    exportString << spellsToExport();
    exportString << getGold() << std::endl;
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
    outStream << scores_.toString();
    outStream << itemsToString();
    outStream << spellsToString();
    return outStream.str();
}

std::string Character::itemsToExport(){
    std::stringstream exportString; 
    exportString << "101010" << std::endl;
    std::vector<Item*>::iterator i;
    for(i = items_.begin(); i != items_.end(); i++){
        exportString << (*i)->getID() << std::endl;
    }
    exportString << "010101" << std::endl;
    return exportString.str();
}

std::string Character::itemsToString()
{
   std::stringstream exportString; 
    exportString << "ITEM INVENTORY: " << std::endl;
    std::vector<Item*>::iterator i;
    for(i = items_.begin(); i != items_.end(); i++){
        exportString << (*i)->to_string() << std::endl;
    }
    exportString << "END ITEM INVENTORY: " << std::endl;
    return exportString.str(); 
}

std::string Character::spellsToExport(){
    std::stringstream exportString;
    exportString << "111111" << std::endl;
    std::vector<Spell>::iterator i;
    for(i = spells_.begin(); i != spells_.end(); i++){
        exportString << i->get_spellID() << std::endl;
    }
    exportString << "000000";
    return exportString.str();
}

std::string Character::spellsToString(){
    std::stringstream exportString;
    exportString << "SPELL INVENTORY: " << std::endl;
    std::vector<Spell>::iterator i;
    for(i = spells_.begin(); i != spells_.end(); i++){
        exportString << i->to_string() << std::endl;
    }
    exportString << "END SPELL INVENTORY: ";
    return exportString.str();
}

std::string Character::raceToString(Race race){
    switch (race){   
        case ELF: return "Elf";
        case HUMAN: return "Human";
        case DWARF: return "Dwarf";
        case HALF_ORC: return "Half Orc";
        case GNOME: return "Gnome";
        default : return ""; break;
    }
}

std::string Character::classToString(CharacterClass characterClass){
    switch (characterClass){   
        case PALADIN: return "Paladin";
        case FIGHTER: return "Fighter";
        case ROGUE: return "Rogue";
        case CLERIC: return "Cleric";
        case RANGER: return "Ranger";
        case WIZARD: return "Wizard";
        default : return "UNKNOWN"; break;
    }
}

int classToInt(CharacterClass class_)
{
    switch(class_)
    {
        case PALADIN: return 0;
        case FIGHTER: return 1;
        case ROGUE: return 2;
        case CLERIC: return 3;
        case RANGER: return 4;
        case WIZARD: return 5;
        default : return -1; break;
    }
}
int raceToInt(Race race_)
{
    switch (race_){   
        case ELF: return 0;
        case HUMAN: return 1;
        case DWARF: return 2;
        case HALF_ORC: return 3;
        case GNOME: return 4;
        default : return -1; break;
    }
}
CharacterClass intToClass(int class_)
{
    switch(class_)
    {
        case 0: return PALADIN;
        case 1: return FIGHTER;
        case 2: return ROGUE;
        case 3: return CLERIC;
        case 4: return RANGER;
        case 5: return WIZARD;
        default : return PALADIN; break;
    }
}
Race intToRace(int race_)
{
    switch (race_){   
        case 0: return ELF;
        case 1: return HUMAN;
        case 2: return DWARF;
        case 3: return HALF_ORC;
        case 4: return GNOME;
        default : return HUMAN; break;
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

void Character::CreateMenu(EntityList<Character>* list)
{
    std::string player;
    std::string name;
    int id;
    int tempClass;
    int race;
    int level;
    AbilityScores tempScores;
    std::vector<Item*> newItems;
    std::vector<Spell> newSpells;
    int gold;
    std::cout << std::endl << "Please Enter the Character name: ";
    std::cin >> name;
    std::cout << std::endl << "Please Enter the Player name: ";  
    std::cin >> player;
    std::cout << std::endl << "Please Enter the Character ID: ";
    std::cin >> id;
    std::cout << std::endl;
    printClasses();
    std::cout << std::endl << "Please Enter the Character Class: ";
    std::cin >> tempClass;
    std::cout << std::endl;
    printRaces();
    std::cout << std::endl << "Please Enter the Character Race: ";
    std::cin >> race;
    std::cout << std::endl << "Please Enter the Character's Gold Count: ";
    std::cin >> gold;

}

