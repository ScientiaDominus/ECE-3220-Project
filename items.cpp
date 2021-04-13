#include "item.h"

item::item(std::string name, std::string damage, double weight, int itemID, int price)
{
    name_ = name;
    damage_ = damage;
    weight_ = weight;
    itemID_ = itemID;
    price_ =  price;
}

void item::setName_(std::string name)
{
    name_ = name;
}
void item::setDamage_(std::string damage)
{
    damage_ = damage;
}
void item::setWeight_(double weight)
{
    weight_ = weight;
}
void item::setID_(int ID)
{
    itemID_ = ID;
}
void item::setPrice_(int price)
{
    price_ = price;
}