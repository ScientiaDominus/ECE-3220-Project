#ifndef ABILITY_SCORES_H
#define ABILITY_SCORES_H
#include <iostream>
#include <string>
#include <sstream>

#include <string>
class AbilityScores{
    private:
        int strength;
        int dexterity;
        int constitution;
        int intelligence;
        int wisdom;
        int charisma;
    public:
        AbilityScores();
        //Parameterized Constructor
        AbilityScores(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma);
        //Getters for all elements
        int getStrength();
        int getDexterity();
        int getConstitution();
        int getIntelligence();
        int getWisdom();
        int getCharisma();
        //Setters for all elements
        void setStrength(int strength);
        void setDexterity(int dexterity);
        void setConstitution(int constitution);
        void setIntelligence(int intelligence);
        void setWisdom(int wisdom);
        void setCharisma(int charisma);
        //To String functions
        std::string toExportString(); // creates an exportable string
        std::string toString(); // creates a user-friendly printable string
        //Destructor
        ~AbilityScores();
};

#endif