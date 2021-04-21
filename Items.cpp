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