#ifndef ABILITY_SCORES_H
#define ABILITY_SCORES_H

#include <string>
class AbilityScores{
    public:
        AbilityScores();
        AbilityScores(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma);
        int getStrength() const{return strength;}
        int getDexterity() const{return dexterity;}
        int getConstitution() const{return constitution;}
        int getIntelligence() const{return intelligence;}
        int getWisdom() const{return wisdom;}
        int getCharisma() const{return charisma;}
        void increaseStrength(int points);
        void increaseDexterity(int points);
        void increaseConstitution(int points);
        void increaseIntelligence(int points);
        void increaseWisdom(int points);
        void increaseCharisma(int points);
        std::string toExportString();
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