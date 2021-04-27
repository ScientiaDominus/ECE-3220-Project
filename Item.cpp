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

std::string Item::to_string()
{
    std::stringstream mystream;

    mystream << "NAME: " << Name_() << std::endl; 
    mystream << "DAMAGE: " << Damage_() << std::endl;
    mystream << "ITEMTYPE: " << ItemType_() << std::endl;
    mystream << "WEIGHT: " << Weight_() << std::endl;
    mystream << "ID: " << ID_() << std::endl;
    mystream << "PRICE: " << Price_() << std::endl; 

    return mystream.str();
}
std::string Item::toExportString() const{return "";}