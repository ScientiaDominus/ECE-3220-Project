#ifndef SPELL_H
#define SPELL_H

#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include "Entity.h"
#include "EntityList.h"

class Spell: public Entity{
    public:
        //default constructor
        Spell();
        //parameterized constructor
        Spell(std::string, int, std::string, int, int, int);
        //copy constructor
        Spell(const Spell &spell);
        //default destructor
        ~Spell();

        //getters and setters
        std::string get_spellName() const;
        int get_spellID() const;
        std::string get_description() const;
        int get_castingTime() const;
        int get_range() const;
        int get_duration() const;

        void set_spellName(std::string);
        void set_spellID(int);
        void set_description(std::string);
        void set_castingTime(int);
        void set_range(int);
        void set_duration(int);

        //returns a readable string for a Spell object
        std::string to_string();
        //returns a string to be printed to a file
        virtual std::string toExportString();
        //returns a string with the name and ID of the Spell
        virtual std::string to_simpleString();

        //prints a menu to create a new Spell
        static void CreateMenu(EntityList<Spell*>* list);
        //prints a menu to edit an existing spell
        virtual void EditMenu();
        //prints the spell to_string()
        virtual void longPrint();

    private:
        std::string spellName_;
        int spellID_;
        std::string description_;
        int castingTime_;
        int range_;
        int duration_;

        
        

};


#endif