#ifndef ABILITY_SCORES_H
#define ABILITY_SCORES_H
#include <iostream>
#include <string>
#include <sstream>

#include <string>
class AbilityScores{
    public:
        AbilityScores();
        AbilityScores(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma);
        int getStrength();
        int getDexterity();
        int getConstitution();
        int getIntelligence();
        int getWisdom();
        int getCharisma();
        void setStrength(int strength);
        void setDexterity(int dexterity);
        void setConstitution(int constitution);
        void setIntelligence(int intelligence);
        void setWisdom(int wisdom);
        void setCharisma(int charisma);
        std::string toExportString();
        std::string toString();
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