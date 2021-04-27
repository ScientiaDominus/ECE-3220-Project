#include "Armor.h"
//Armor::Armor(std::string name, std::string damage, double weight, int itemID, int price,  armorType type) : Item(name, damage, ARMOR, weight, itemID, price){}
void Armor::setArmorType(armorType type)
{
    type_ = type;
}

std::string Armor::to_string()
{
    std::stringstream myStream;

    myStream << "NAME: " << Name_() << std::endl; 
    myStream << "DAMAGE: " << Damage_() << std::endl;
    myStream << "ITEMTYPE: " << itemTypeToString() << std::endl;
    myStream << "ARMORTYPE: " << typeToString() << std::endl; //Probably need a armor type switch function to properly display this
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
std::string Armor::typeToString()
{
    switch(type_)
    {
        case LIGHT:
            return std::string("Light");
        case MEDIUM:
            return std::string("Medium");
        case HEAVY:
            return std::string("Heavy");
        default:
            return std::string("ERROR: ARMORTYPE UNDEFINED");

    }
}