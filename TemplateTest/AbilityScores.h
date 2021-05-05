#ifndef ABILITY_SCORES_H
#define ABILITY_SCORES_H
#include <iostream>
#include <string>
#include <sstream>

#include <string>
class AbilityScores{
    public:
        AbilityScores();
        // constructor to initialize everything.
        AbilityScores(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma);
        // Getters for all elements
        int getStrength();
        int getDexterity();
        int getConstitution();
        int getIntelligence();
        int getWisdom();
        int getCharisma();
        // setters for all elements
        void setStrength(int strength);
        void setDexterity(int dexterity);
        void setConstitution(int constitution);
        void setIntelligence(int intelligence);
        void setWisdom(int wisdom);
        void setCharisma(int charisma);
        // to string functions
        std::string toExportString(); // creates an exportable string
        std::string toString(); // creates a printable string

        ~AbilityScores();
    private:
        int strength;
        int dexterity;
        int constitution;
        int intelligence;
        int wisdom;
        int charisma;
};

#endif