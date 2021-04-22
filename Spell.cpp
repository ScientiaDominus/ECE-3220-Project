#include "Spell.h"

//default constructor
Spell::Spell(){

}
//parameterized constructor
Spell::Spell(std::string spellName, int spellID, std::string description, int castingTime, int range, int duration){
    spellName_=spellName;
    spellID_=spellID;
    description_=description;
    castingTime_=castingTime;
    range_=range;
    duration_=duration;
}
//copy constructor
Spell::Spell(const Spell &spell){
    spellName_=spell.get_spellName();
    spellID_=spell.get_spellID();
    description_=spell.get_description();
    castingTime_=spell.get_castingTime();
    range_=spell.get_range();
    duration_=spell.get_duration();
}
Spell::~Spell(){
}

//getters and setters
std::string Spell::get_spellName() const{
    return spellName_;
}
int Spell::get_spellID() const{
    return spellID_;
}
std::string Spell::get_description() const{
    return description_;
}
int Spell::get_castingTime() const{
    return castingTime_;
}
int Spell::get_range() const{
    return range_;
}
int Spell::get_duration() const{
    return duration_;
}

void Spell::set_spellName(std::string spellName){
    spellName_=spellName;
}
void Spell::set_spellID(int spellID){
    spellID_=spellID;
}
void Spell::set_description(std::string description){
    description_=description;
}
void Spell::set_castingTime(int castingTime){
    castingTime_=castingTime;
}
void Spell::set_range(int range){
    range_=range;
}
void Spell::set_duration(int duration){
    duration_=duration;
}

std::string Spell::to_string(){
    char buff[100];
    const char *name = spellName_.c_str();
    const char *description = description_.c_str();
    sprintf(buff, "%s\n     Casting Time: %d action\n      Range: %d feet\n     Duration: %d\n      Description: %s\n", name, castingTime_, range_, duration_, description);
    std::string returnString = buff;
    return returnString;
    
}

