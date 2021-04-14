#include "AbilityScores.h"

AbilityScores::AbilityScores(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma){
    this->strength = strength;
    this->dexterity = dexterity;
    this->constitution = constitution;
    this->intelligence = intelligence;
    this->wisdom = wisdom;
    this->charisma = charisma;
}

void AbilityScores::increaseStrength(int points){
    strength += points;
}
void AbilityScores::increaseDexterity(int points){
    dexterity += points;
}
void AbilityScores::increaseConstitution(int points){
    constitution += points;
}
void AbilityScores::increaseIntelligence(int points){
    intelligence += points;
}
void AbilityScores::increaseWisdom(int points){
    wisdom += points;
}
void AbilityScores::increaseCharisma(int points){
    charisma += points;
}