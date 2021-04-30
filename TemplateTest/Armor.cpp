#include "Armor.h"

Armor::Armor(std::string name, std::string damage, double weight, int itemID, int price, ArmorType type) : Item(name, damage, ARMOR, weight, itemID, price){
    this->armorType = type;
}

std::string Armor::to_string()
{
    std::stringstream myStream;

    myStream << "NAME: " << getName() << std::endl; 
    myStream << "DAMAGE: " << getDamage() << std::endl;
    myStream << "ITEMTYPE: " << itemTypeToString() << std::endl;
    myStream << "ARMORTYPE: " << typeToString() << std::endl; //Probably need a armor type switch function to properly display this
    myStream << "WEIGHT: " << getWeight() << std::endl;
    myStream << "ID: " << getID() << std::endl;
    myStream << "PRICE: " << getPrice() << std::endl; 

    return myStream.str();
}

std::string Armor::toExportString(){
    std::stringstream myStream;

    myStream << getItemType() << std::endl;
    myStream << getName() << std::endl;
    myStream << getDamage() << std::endl;
    myStream << getArmorType() << std::endl;
    myStream << getWeight() << std::endl;
    myStream << getID() << std::endl;
    myStream << getPrice() << std::endl;

    return myStream.str();
}
std::string Armor::typeToString(){
    switch(armorType)
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
ArmorType Armor::intToType(int type){
    switch(type){
        case 0:
            return LIGHT;
        case 1:
            return MEDIUM;
        case 2:
            return HEAVY;
        default:
            return MEDIUM;
    }
}

void Armor::longPrint(){
    std::cout << to_string();
}