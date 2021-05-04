#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Item.h"
#include "CharacterClass.h"
#include "Race.h"
#include "AbilityScores.h"
#include "Spell.h"


class Character : public Entity{
	public: 
		Character();
		Character(std::string player_name, std::string name, int id, CharacterClass character_class,
                    Race race, int level, AbilityScores ability_scores, std::vector<Item> item_inventory,
                    std::vector<Spell> spell_inventory, int gold_count);
		std::string getPlayer() const;
		CharacterClass getClass() const;
		Race getRace() const;
		int getLevel() const;
		AbilityScores getScores() const;
		std::vector<Item*> getItems() const;
		std::vector<Spell> getSpells() const;
		int getGold() const;
		std::string toExportString();
		std::string itemsToExport();
		std::string spellsToExport();
		std::string classToString(CharacterClass characterClass);
		std::string raceToString(Race race);
		std::string to_string();
		std::string itemsToString();
		std::string spellsToString();
		int classToInt(CharacterClass class_);
		int raceToInt(Race race_);
		CharacterClass intToClass(int class_);
		Race intToRace(int race_);
		virtual void longPrint() override;
		static void CreateMenu(EntityList<Character>* List);
		
		~Character();


	private:
		std::string player_;
		CharacterClass class_;
		Race race_;
		int level_;
		AbilityScores scores_;
		std::vector<Item*> items_;
		std::vector<Spell> spells_;
		int gold_;




};
#endif 