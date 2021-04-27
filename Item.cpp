#include "Item.h"

Item::Item(std::string name, std::string damage, Type itemType, double weight, int itemID, int price)
{
    name_ = name;
    damage_ = damage;
    itemType_ = itemType;
    weight_ = weight;
    itemID_ = itemID;
    price_ =  price;
}

void Item::setName_(std::string name)
{
    name_ = name;
}
void Item::setDamage_(std::string damage)
{
    damage_ = damage;
}
void Item::setItemType_(Type type)
{
    itemType_ = type;
}
void Item::setWeight_(double weight)
{
    weight_ = weight;
}
void Item::setID_(int ID)
{
    itemID_ = ID;
}
void Item::setPrice_(int price)
{
    price_ = price;
}
void Item::edit()
{
    std::string name;
    std::string damage;
    double weight;
    int id;
    int price;
    std::cout << this->to_string();
    std::cout << "Enter the item name: ";
    std::cin >> name;
    std::cout << std::endl << "Enter the item's damage string (ex. 2d4): ";
    std::cin >> damage;
    std::cout << std::endl << "Enter the item's ID: ";
    std::cin >> id;
    std::cout << std::endl << "Enter the item's weight: ";
    std::cin >> weight;
    std::cout << std::endl << "Enter the item's price: ";
    std::cin >> price;
    setName_(name);
    setDamage_(damage);
    setID_(id);
    setWeight_(weight);
    setPrice_(price);
}
/*void Item::create()
{
    std::string name;
    std::string damage;
    double weight;
    int id;
    int price;
}*/
std::string Item::to_string()
{
    std::stringstream myStream;

    myStream << "NAME: " << Name_() << std::endl; 
    myStream << "DAMAGE: " << Damage_() << std::endl;
    myStream << "ITEMTYPE: " << itemTypeToString() << std::endl; //need an itemtype switch for proper string display.
    myStream << "WEIGHT: " << Weight_() << std::endl;
    myStream << "ID: " << ID_() << std::endl;
    myStream << "PRICE: " << Price_() << std::endl; 

    return myStream.str();
}
std::string Item::toExportString()
{
    std::stringstream myStream;

    myStream << Name_() << std::endl;
    myStream << Damage_() << std::endl;
    myStream << ItemType_() << std::endl;
    myStream << Weight_() << std::endl;
    myStream << ID_() << std::endl;
    myStream << Price_() << std::endl;

    return myStream.str();

}

std::string Item::itemTypeToString()
{
    switch(itemType_)
    {
        case OBJECT:
            return std::string("Object");
        case ARMOR:
            return std::string("Armor");
        case WEAPON:
            return std::string("Weapon");
        default:
            return std::string("ERROR: ITEMTYPE IS UNDEFINED");
    }
}