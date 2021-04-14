#ifndef ABILITY_SCORES_H
#define ABILITY_SCORES_H


class AbilityScores{
    public:
        AbilityScores(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma);
        void getStrength();
        void getDexterity();
        void getConstitution();
        void getIntelligence();
        void getWisdom();
        void getCharisma();
        void increaseStrength(int points);
        void increaseDexterity(int points);
        void increaseConstitution(int points);
        void increaseIntelligence(int points);
        void increaseWisdom(int points);
        void increaseCharisma(int points);
    private:
        int strength;
        int dexterity;
        int constitution;
        int intelligence;
        int wisdom;
        int charisma;
};

#endif