#include "AbilityScores.h"
#include <iostream>

AbilityScores::AbilityScores(){}
AbilityScores::~AbilityScores(){}
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
void AbilityScores::setStrength(int strength){this->strength = strength;}
void AbilityScores::setDexterity(int dexterity){this->dexterity = dexterity;}
void AbilityScores::setConstitution(int constitution){this->constitution = constitution;}
void AbilityScores::setIntelligence(int intelligence){this->intelligence = intelligence;}
void AbilityScores::setWisdom(int wisdom){this->wisdom = wisdom;}
void AbilityScores::setCharisma(int charisma){this->charisma = charisma;}


std::string AbilityScores::toExportString() {
    std::stringstream exportString; 
    exportString << getStrength() << std::endl;
    exportString << getDexterity() << std::endl;
    exportString << getConstitution() << std::endl;
    exportString << getIntelligence() << std::endl;
    exportString << getWisdom() << std::endl;
    exportString << getCharisma() << std::endl;
    return exportString.str();
}
std::string AbilityScores::toString(){
   std::stringstream exportString; 
    exportString << "STRENGTH: " << getStrength() << std::endl;
    exportString << "DEXTERITY: " << getDexterity() << std::endl;
    exportString << "CONSTITUTION: " << getConstitution() << std::endl;
    exportString << "INTELLIGENCE: " << getIntelligence() << std::endl;
    exportString << "WISDOM: " << getWisdom() << std::endl;
    exportString << "CHARISMA: " << getCharisma() << std::endl;
    return exportString.str(); 
}