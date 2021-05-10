#include "Spell.h"
#include <sstream>

//default constructor
Spell::Spell(){

}
//parameterized constructor
Spell::Spell(std::string spellName, int spellID, std::string description, int castingTime, int range, int duration){
    this->setName(spellName);
    this->setID(spellID);
    description_ = description;
    castingTime_ = castingTime;
    range_ = range;
    duration_ = duration;
}
//copy constructor
Spell::Spell(const Spell &spell){
    this->setName(spell.getName());
    this->setID(spell.getID());
    description_ = spell.get_description();
    castingTime_ = spell.get_castingTime();
    range_ = spell.get_range();
    duration_ = spell.get_duration();
}
//destructor
Spell::~Spell(){
}

//getters and setters
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


std::string Spell::toExportString(){
    std::stringstream exportString;
    exportString << getID() << std::endl;
    exportString << getName() << std::endl;
    exportString << get_description() << std::endl;
    exportString << get_castingTime() << std::endl;
    exportString << get_range() << std::endl;
    exportString << get_duration();
    
    return exportString.str();
}

std::string Spell::to_string(){
    std::stringstream outStream;
    outStream << "NAME: " << getName() << std::endl;
    outStream << "ID: " << getID() << std::endl;
    outStream << "CASTING TIME: " << get_castingTime() << std::endl;
    outStream << "RANGE: " << get_range() << std::endl;
    outStream << "DURATION: " << get_duration() << std::endl;
    outStream << "DESCRIPTION: " << get_description() << std::endl;
    return outStream.str();
}

void Spell::CreateMenu(EntityList<Spell*>* list){
    std::cout << "Please type in the name of the spell you would like to add\n";
    std::string spellName;
    getline(std::cin, spellName); //clears buffer
    getline(std::cin, spellName);
    std::cout << "Please type an integer to represent the Spell ID\n";
    int spellID;
    std::cin >> spellID;
    std::cout << "Please type an integer for the casting time of the spell. This is in terms of actions.\n";
    int castingTime;
    std::cin >> castingTime;
    std::cout << "Please type an integer for the range of the spell. This is in terms of feet.\n";
    int range;
    std::cin >> range;
    std::cout << "Please type an integer for the duration of the spell. This is in terms of hours.\n";
    int duration;
    std::cin >> duration;
    std::cout << "Finally, please type a short description of the spell.\n";
    std::string description;
    getline(std::cin, description); //clears buffer
    getline(std::cin, description);


    Spell* temp = new Spell(spellName, spellID, description, castingTime, range, duration);
    //std::cout << "Your new spell is:\n" << temp->to_string() << std::endl;

    list->addEntity(temp);
}

void Spell::EditMenu(){
    std::cout << "Enter the new name of the spell\n";
    std::string spellName;
    getline(std::cin, spellName); //clears buffer
    getline(std::cin, spellName);
    std::cout << "Enter the new spell ID\n";
    int spellID;
    std::cin >> spellID;
    std::cout << "Enter the new casting time for the spell. This is in terms of actions.\n";
    int castingTime;
    std::cin >> castingTime;
    std::cout << "Enter the new range of the spell. This is in terms of feet.\n";
    int range;
    std::cin >> range;
    std::cout << "Enter the new duration of the spell. This is in terms of hours.\n";
    int duration;
    std::cin >> duration;
    std::cout << "Finally, please enter the new description of the spell\n";
    std::string description;
    getline(std::cin, description); //clears buffer
    getline(std::cin, description);

    setName(spellName);
    setID(spellID);
    set_description(description);
    set_castingTime(castingTime);
    set_range(range);
    set_duration(duration);
}

void Spell::longPrint(){
    std::cout << to_string() << std::endl;
}