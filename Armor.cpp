#include "Armor.h"

void Armor::setArmorType(armorType type)
{
    type_ = type;
}

std::string Armor::to_string()
{
    std::stringstream myStream;

    myStream << "NAME: " << Name_() << std::endl; 
    myStream << "DAMAGE: " << Damage_() << std::endl;
    myStream << "ITEMTYPE: " << ItemType_() << std::endl;
    myStream << "ARMORTYPE: " << ArmorType() << std::endl;
    myStream << "WEIGHT: " << Weight_() << std::endl;
    myStream << "ID: " << ID_() << std::endl;
    myStream << "PRICE: " << Price_() << std::endl; 

    return myStream.str();
}

std::string Armor::toExportString()
{
    std::stringstream myStream;

    myStream << Name_() << std::endl;
    myStream << Damage_() << std::endl;
    myStream << ItemType_() << std::endl;
    myStream << ArmorType() << std::endl;
    myStream << Weight_() << std::endl;
    myStream << ID_() << std::endl;
    myStream << Price_() << std::endl;

    return myStream.str();
}