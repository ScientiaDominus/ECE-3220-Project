#include "Weapon.h"

Weapon::Weapon(std::string name, std::string damage, double weight, int itemID, int price,  dmgType type, int range) : Item(name, damage, WEAPON, weight, itemID, price)
{
    setDamageType_(type);
    setRange_(range);
    std::cout << "Weapon Constructor called" << std::endl;
}
void Weapon::setRange_(int range)
{
    range_ = range;
}

void Weapon::setDamageType_(dmgType type)
{
    type_ = type;
}

std::string Weapon::to_string()
{
    std::stringstream myStream;

    myStream << "NAME: " << Name_() << std::endl; 
    myStream << "DAMAGE: " << Damage_() << std::endl;
    myStream << "DAMAGETYPE: " << typeToString() << std::endl;
    myStream << "RANGE: " << Range_() << std::endl;
    myStream << "ITEMTYPE: " << itemTypeToString() << std::endl;
    myStream << "WEIGHT: " << Weight_() << std::endl;
    myStream << "ID: " << ID_() << std::endl;
    myStream << "PRICE: " << Price_() << std::endl; 

    return myStream.str();
}
std::string Weapon::typeToString()
{
    switch(type_)
    {
        case POISON:
            //std::cout << "Poison";
            return std::string("Poison");
        case SLASHING:
            //std::cout << "Slashing";
            return std::string("Slashing");
        case COLD:
            //std::cout << "Cold";
            return std::string("Cold");
        case FIRE:
            //std::cout << "Fire";
            return std::string("Fire");
        case ACID:
            //std::cout << "Acid";
            return std::string("Acid");
        case LIGHTNING:
            //std::cout << "Lightning";
            return std::string("Lighting");
        default:
            //std::cout << "ERROR::UNKNOWN DAMAGE TYPE";
            return std::string("ERROR::UNKNOWN DAMAGE TYPE");
    }
        

}