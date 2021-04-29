#include "Character.h"
#include <string>
#include <sstream>
#include <iomanip>

Character::Character(
                    std::string player_name, std::string character_name, CharacterClass character_class,
                    Race race, int level, AbilityScores ability_scores, std::vector<Item> item_inventory,
                    std::vector<Spell> spell_inventory, int gold_count){
    this->player_name = player_name;
    this->character_name = character_name;
    this->character_class = character_class;
    this->race = race;
    this->level = level;
    this->ability_scores = ability_scores;
    this->item_inventory = item_inventory;
    this->spell_inventory = spell_inventory;
    this->gold_count = gold_count;
}
std::string Character::get_player_name() const{return player_name;}
std::string Character::get_character_name() const{return character_name;}
CharacterClass Character::get_character_class() const{return character_class;}
int Character::get_character_id() const{return id;}
Race Character::get_race() const{return race;}
int Character::get_level() const{return level;}
AbilityScores Character::get_ability_scores() const{return ability_scores;}
std::vector<Item> Character::get_item_inventory() const{return item_inventory;}
std::vector<Spell> Character::get_spell_inventory() const{return spell_inventory;}
int Character::get_gold_count() const{return gold_count;}
std::string Character::to_string() const{return "";}
std::string Character::toExportString(){
    std::string exportString = character_name +
                                "\n" + get_player_name() +
                                "\n" + get_character_name() +
                                "\n" + (get_character_class()).characterClassToString() +
                                "\n" + get_race().raceToString() +
                                "\n" + std::to_string(this->get_level()) +
                                "\n" + get_ability_scores().toExportString() +
                                itemInventoryToExportString() +
                                spellInventoryToExportString() +
                                "\n" + std::to_string(this->get_gold_count());

    return exportString;
}

std::string Character::itemInventoryToExportString(){
    std::string exportString = "item inventory start\n";
    std::vector<Item>::iterator i;
    for(i = item_inventory.begin(); i != item_inventory.end(); i++){
        exportString += i->ID_() +"\n";
    }
    exportString += "item inventory end\n";
    return exportString;
}

std::string Character::spellInventoryToExportString(){
    std::string exportString = "spell inventory start\n";
    std::vector<Spell>::iterator i;
    for(i = spell_inventory.begin(); i != spell_inventory.end(); i++){
        exportString += i->get_spellID() +"\n";
    }
    exportString += "spell inventory end\n";
    return exportString;
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

std::string Character::characterClassToString(CharacterClass characterClass){
    switch (characterClass){   
        case PALADIN: return "Palagin";
        case FIGHTER: return "Fighter";
        case ROUGE: return "Rouge";
        case CLERIC: return "Cleric";
        case RANGER: return "Range";
        case WIZARD: return "Wizard";
        default : return ""; break;
    }
}