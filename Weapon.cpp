#include "Weapon.h"

Weapon::Weapon(std::string name, std::string damage, double weight, int itemID, int price,  dmgType type, int range) : Item(name, damage, WEAPON, weight, itemID, price){
            setDamageType_(type);
            setRange_(range);
            std::cout << "Weapon Constructor called" << std::endl;
        }
Weapon::Weapon(){
    std::cout << "Weapon Default Constructor Called." << std::endl;
}
Weapon::~Weapon(){
    std::cout << "Weapon Default Destructor Called." << std::endl;
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

void Weapon::edit()
{
    std::string name = "";
    std::string damage = "";
    int dmgType = 0;
    double weight = 0;
    int id = 0;
    int price = 0;
    int range = 0;
    std::cout << this->to_string();
    std::cout << "Enter the item name: ";
    std::cin >> name;
    std::cout << std::endl << "Enter the item's damage string (ex. 2d4): ";
    std::cin >> damage;
    std::cout << std::endl << "0. FIRE" << std::endl;
    std::cout << "1. COLD" << std::endl;
    std::cout << "2. LIGHTNING" << std::endl;
    std::cout << "3. ACID" << std::endl;
    std::cout << "4. SLASHING" << std::endl;
    std::cout << "5. POISON" << std::endl;
    std::cout << "Enter the item's damage type (ex. 1,2,3,4,etc.): ";
    std::cin >> dmgType;
    std::cout << std::endl << "Enter the item's range in feet (ex. 20): ";
    std::cin >> range;
    std::cout << std::endl << "Enter the item's unique ID (ex. 423567): ";
    std::cin >> id;
    std::cout << std::endl << "Enter the item's weight (ex. 15.67): ";
    std::cin >> weight;
    std::cout << std::endl << "Enter the item's price in gold pieces(ex. 45): ";
    std::cin >> price;
    setName_(name);
    setDamage_(damage);
    setID_(id);
    setRange_(range);
    setDamageType_(this->intToType(dmgType));
    setWeight_(weight);
    setPrice_(price);
}