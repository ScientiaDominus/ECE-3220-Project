#include "Weapon.h"

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
    std::stringstream weaponSS;
    weaponSS << "Behold, a " << Name_() << std::endl;
    weaponSS << std::setprecision(2) << std::fixed << "Its weight, " << Weight_() << " pounds." << std::endl;
    weaponSS << "Its value, a mere " << Price_ << " gold pieces." << std::endl;
    weaponSS << "This "
    
    
}
std::string typeToString(dmgType type)
{
    switch(type)
    {
        case POISON:
            std::cout << "Poison";
        case SLASHING:
            std::cout << "Slashing";
        case COLD:
            std::cout << "Cold";
        case FIRE:
            std::cout << "Fire";
        case ACID:
            std::cout << "Acid";
        case LIGHTNING:
            std::cout << "Lightning";
        default:
            std::cout << "ERROR::UNKNOWN DAMAGE TYPE";
    }
        

}