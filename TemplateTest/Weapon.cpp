#include "Weapon.h"

std::string Weapon::to_string(){
    std::stringstream myStream;

    myStream << "NAME: " << getName() << std::endl; 
    myStream << "DAMAGE: " << getDamage() << std::endl;
    myStream << "DAMAGETYPE: " << typeToString() << std::endl;
    myStream << "RANGE: " << getRange() << std::endl;
    myStream << "ITEMTYPE: " << itemTypeToString() << std::endl;
    myStream << "WEIGHT: " << getWeight() << std::endl;
    myStream << "ID: " << getID() << std::endl;
    myStream << "PRICE: " << getPrice() << std::endl; 

    return myStream.str();
}

std::string Weapon::typeToString(){
    switch(type){
        case POISON:

            return std::string("Poison");
        case SLASHING:
            return std::string("Slashing");
        case COLD:
            return std::string("Cold");
        case FIRE:
            return std::string("Fire");
        case ACID:
            return std::string("Acid");
        case LIGHTNING:
            return std::string("Lighting");
        default:
            return std::string("ERROR::UNKNOWN DAMAGE TYPE");
    }
}

std::string Weapon::toExportString(){
    std::stringstream myStream;
    myStream << getItemType() << std::endl;
    myStream << getName() << std::endl;
    myStream << getDamage() << std::endl;
    myStream << getDamageType() << std::endl;
    myStream << getRange() << std::endl;
    myStream << getWeight() << std::endl;
    myStream << getID() << std::endl;
    myStream << getPrice() << std::endl;

    return myStream.str();
}

DMGType Weapon::intToType(int type){
    switch(type){
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

void Weapon::longPrint(){
    std::cout << to_string() << std::endl;
}