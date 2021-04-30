#include "Armor.h"
Armor::Armor(std::string name, std::string damage, double weight, int itemID, int price,  armorType type) : Item(name, damage, ARMOR, weight, itemID, price){
    setArmorType(type);
    std::cout << "Armor Constructor Called" << std::endl;
}
Armor::Armor(){
    std::cout << "Armor Default Constructor Called." << std::endl;
}
Armor::~Armor(){
    std::cout << "Armor Default Destructor Called." << std::endl;
}
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

    myStream << ItemType_() << std::endl;
    myStream << Name_() << std::endl;
    myStream << Damage_() << std::endl;
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
armorType Armor::intToType(int type)
{
    switch(type)
    {
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

void Armor::edit()
{
    std::string name = "";
    std::string damage = "";
    int armorType = 0;
    double weight = 0;
    int id = 0;
    int price = 0;
    std::cout << this->to_string();
    std::cout << "Enter the item name: ";
    std::cin >> name;
    std::cout << std::endl << "Enter the item's damage string (ex. 2d4): ";
    std::cin >> damage;
    std::cout << std::endl;
    std::cout << "0. LIGHT" << std::endl;
    std::cout << "1. MEDIUM" << std::endl;
    std::cout << "2. HEAVY" << std::endl;
    std::cout << "Enter the item's armor type (ex. for heavy enter: 2): ";
    std::cin >> weight;
    std::cout << std::endl << "Enter the item's unique ID (ex. 423567): ";
    std::cin >> id;
    std::cout << std::endl << "Enter the item's weight (ex. 15.67): ";
    std::cin >> weight;
    std::cout << std::endl << "Enter the item's price in gold pieces(ex. 45): ";
    std::cin >> price;
    setName_(name);
    setDamage_(damage);
    setID_(id);
    setArmorType(this->intToType(armorType));
    setWeight_(weight);
    setPrice_(price);
}