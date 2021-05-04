#include "Character.h"
Character::Character(){}
Character::~Character(){}
Character::Character(
                    std::string player_name, std::string name, int id, CharacterClass character_class,
                    Race race, int level, AbilityScores ability_scores, std::vector<Item> item_inventory,
                    std::vector<Spell> spell_inventory, int gold_count){
    player_name = player_name;
    setName(name);
    setID(id);
    character_class = character_class;
    race = race;
    level = level;
    ability_scores = ability_scores;
    item_inventory = item_inventory;
    spell_inventory = spell_inventory;
    gold_count = gold_count;
}
std::string Character::getPlayer() const{return player_;}
CharacterClass Character::getClass() const{return class_;}
Race Character::getRace() const{return race_;}
int Character::getLevel() const{return level_;}
AbilityScores Character::getScores() const{return scores_;}
std::vector<Item*> Character::getItems() const{return items_;}
std::vector<Spell> Character::getSpells() const{return spells_;}
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
        case PALADIN: return "Palagin";
        case FIGHTER: return "Fighter";
        case ROGUE: return "Rogue";
        case CLERIC: return "Cleric";
        case RANGER: return "Range";
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

