#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <vector>
#include "item.h"


class base_char{
	public: 
        int get_level() const{return level;}
        std::string get_class() const{return class_type;}
        std::string get_name() const{return char_name;}
        std::string get_player_name() const{return player_name;}
        std::string get_race() const{return race;}
        std::vector<int> get_skills() const{return skills;}
        std::vector<int> get_ability_scores() const{return ability_scores;}
        std::vector<item> get_inventory() const{return inventory;}

	private:
		std::string class_type;
		std::string char_name;
		std::string player_name;
		std::string race;
		int level;
		std::vector<int> skills;
		std::vector<int> ability_scores;
		std::vector<item> inventory;




};
#endif 