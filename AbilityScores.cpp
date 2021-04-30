#include "AbilityScores.h"
#include <iostream>

AbilityScores::AbilityScores(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma){
    this->strength = strength;
    this->dexterity = dexterity;
    this->constitution = constitution;
    this->intelligence = intelligence;
    this->wisdom = wisdom;
    this->charisma = charisma;
}

int AbilityScores::getStrength(){return strength;}
int AbilityScores::getDexterity(){return dexterity;}
int AbilityScores::getConstitution(){return constitution;}
int AbilityScores::getIntelligence(){return intelligence;}
int AbilityScores::getWisdom(){return wisdom;}
int AbilityScores::getCharisma(){return charisma;}

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

std::string AbilityScores::toExportString() {
    std::string exportString = std::to_string(getStrength()) +
                                "\n" + std::to_string(getDexterity()) +
                                "\n" + std::to_string(getConstitution()) +
                                "\n" + std::to_string(getIntelligence()) +
                                "\n" + std::to_string(getWisdom()) + 
                                "\n" + std::to_string(getCharisma());

    return exportString;
}