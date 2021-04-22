#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <vector>
#include "Item.h"
#include "CharacterClass.h"
#include "Race.h"
#include "AbilityScores.h"
#include "Spell.h"


class Character{
	public: 
		Character(std::string player_name, std::string character_name, CharacterClass character_class,
                    Race race, int level, AbilityScores ability_scores, std::vector<Item> item_inventory,
                    std::vector<Spell> spell_inventory, int gold_count);
		std::string get_player_name() const;
		std::string get_character_name() const;
		CharacterClass get_character_class() const;
		Race get_race() const;
		int get_level() const;
		AbilityScores get_ability_scores() const;
		std::vector<Item> get_item_inventory() const;
		std::vector<Spell> get_spell_inventory() const;
		int get_gold_count() const;
		std::string to_string() const;
		std::string toExportString();
		std::string itemInventoryToExportString();
		std::string spellInventoryToExportString();
		std::string characterClassToString(CharacterClass characterClass);
		std::string raceToString(Race race);

	private:
		std::string player_name;
		std::string character_name;
		CharacterClass character_class;
		Race race;
		int level;
		AbilityScores ability_scores;
		std::vector<Item> item_inventory;
		std::vector<Spell> spell_inventory;
		int gold_count;




};
#endif 