#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Entity.h"
#include "EntityList.h"
#include "Item.h"
#include "CharacterClass.h"
#include "Race.h"
#include "AbilityScores.h"
#include "Spell.h"


class Character : public Entity{
	public: 
		Character();
		// A constructor that initializes all the elements within a character object
		Character(std::string player_name, std::string name, int id, CharacterClass character_class,
                    Race race, int level, AbilityScores* ability_scores, EntityList<Item*> *item_inventory,
                    EntityList<Spell*> *spell_inventory, int gold_count);
		
		//Getter functions for all elements
		std::string getPlayer() const;
		CharacterClass getClass() const;
		Race getRace() const;
		int getLevel() const;
		AbilityScores* getScores() const;
		EntityList<Item*>* getItems() const;
		EntityList<Spell*>*  getSpells() const;
		int getGold() const;
		
		//Setter functions for all elements
		void setPlayer(std::string player);
		void setClass(CharacterClass newClass);
		void setRace(Race race);
		void setLevel(int level);
		void setScores(AbilityScores* scores);
		void setItems(EntityList<Item*>* items);
		void setSpells(EntityList<Spell*>* spells);
		void setGold(int gold);

		std::string toExportString(); // This function creates an export string that converts a character class into a string that can be exported to a file.
		std::string itemsToExport(); // This function is called by toExportString to convert the character's item inventory to a format acceptable for storage in a file.
		std::string spellsToExport(); // this function is called by toExportString to convert the character's spell list to a format acceptable for storage in a file.

		std::string classToString(CharacterClass characterClass); // this function converts a class enum to a printable string
		std::string raceToString(Race race); // this converts a race enum to a printable string
		std::string to_string(); // this converts the character object into a printable string
		std::string itemsToString(); // this converts the item inventory into a printable string
		std::string spellsToString(); // this converts the spell inventory into a printable string 

		int classToInt(CharacterClass class_); // this converts an CharacterClass enum into an integer
		int raceToInt(Race race_); // this converts an Race enum into a integer 
		static CharacterClass intToClass(int class_); // this converts an integer into a CharacterClass enum
		static Race intToRace(int race_); // this converts an integer into a Race enum

		static void printClasses(); // this is simply a print function to display the Class options to the user
		static void printRaces(); // this prints the Race options to the user.
		virtual void longPrint() override; // this is an inherited function that prints out the object

		static void CreateMenu(EntityList<Character*>* List); // This function is a function utilized by the template to allow for proper menu organization and character creation
		void EditMenu(); // This function is another one used by the template class for menu functionality and editing the current character object
		
		~Character();


	private:
		std::string player_;
		CharacterClass class_;
		Race race_;
		int level_;
		AbilityScores* scores_;
		EntityList<Item*>* items_;
		EntityList<Spell*>* spells_;
		int gold_;




};
#endif 