#ifndef ABILITY_SCORES_H
#define ABILITY_SCORES_H
#include <iostream>
#include <string>

#include <string>
class AbilityScores{
    public:
        AbilityScores(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma);
        int getStrength();
        int getDexterity();
        int getConstitution();
        int getIntelligence();
        int getWisdom();
        int getCharisma();
        void increaseStrength(int points);
        void increaseDexterity(int points);
        void increaseConstitution(int points);
        void increaseIntelligence(int points);
        void increaseWisdom(int points);
        void increaseCharisma(int points);
        std::string toExportString();
    private:
        int strength;
        int dexterity;
        int constitution;
        int intelligence;
        int wisdom;
        int charisma;
};

#endif