#include "Weapon.h"

//Weapon::Weapon(std::string name, std::string damage, double weight, int itemID, int price,  dmgType type, int range) : Item(name, damage, WEAPON, weight, itemID, price){}
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

std::string Weapon::toExportString()
{
    std::stringstream myStream;
    myStream << ItemType_() << std::endl;
    myStream << Name_() << std::endl;
    myStream << Damage_() << std::endl;
    myStream << DamageType_() << std::endl;
    myStream << Range_() << std::endl;
    myStream << Weight_() << std::endl;
    myStream << ID_() << std::endl;
    myStream << Price_() << std::endl;

    return myStream.str();
}

dmgType Weapon::intToType(int type)
{
    switch(type)
    {
        case 0:
            return FIRE;
        case 1:
            return COLD;
        case 2:
            return LIGHTNING;
        case 3:
            return ACID;
        case 4:
            return SLASHING;
        case 5:
            return POISON;
        default:
            return SLASHING;
    }
}