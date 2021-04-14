#ifndef SPELL_H
#define SPELL_H
#include <stdlib.h>
#include <string>
#include <iostream>

class Spell{
    public:
        //default constructor
        Spell();
        //parameterized constructor
        Spell(std::string, int, std::string, int, int, int);
        //copy constructor
        Spell(const Spell &spell);

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

        std::string to_string();

    private:
        std::string spellName_;
        int spellID_;
        std::string description_;
        int castingTime_;
        int range_;
        int duration_;

        
        

};


#endif
