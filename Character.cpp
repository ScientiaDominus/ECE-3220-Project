#include "Character.h"

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
Race Character::get_race() const{return race;}
int Character::get_level() const{return level;}
AbilityScores Character::get_ability_scores() const{return ability_scores;}
std::vector<Item> Character::get_item_inventory() const{return item_inventory;}
std::vector<Spell> Character::get_spell_inventory() const{return spell_inventory;}
int Character::get_gold_count() const{return gold_count;}
std::string Character::to_string() const{return "";}
std::string Character::toExportString() const{return "";}