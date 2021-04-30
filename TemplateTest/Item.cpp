#include "Item.h"

Item::Item(){}
Item::~Item(){}
Item::Item(std::string name, std::string damage, Type itemType, double weight, int itemID, int price){   
    setName(name);
    setID(itemID);
    damage = damage;
    itemType = itemType;
    weight = weight;
    price =  price;
}
std::string Item::to_string(){
    std::stringstream myStream;

    myStream << "NAME: " << getName() << std::endl; 
    myStream << "DAMAGE: " << getDamage() << std::endl;
    myStream << "ITEMTYPE: " << itemTypeToString() << std::endl; //need an itemtype switch for proper string display.
    myStream << "WEIGHT: " << getWeight() << std::endl;
    myStream << "ID: " << getID() << std::endl;
    myStream << "PRICE: " << getPrice() << std::endl; 

    return myStream.str();
}
std::string Item::toExportString(){
    std::stringstream myStream;

    myStream << getItemType() << std::endl;
    myStream << getName() << std::endl;
    myStream << getDamage() << std::endl;
    myStream << getWeight() << std::endl;
    myStream << getID() << std::endl;
    myStream << getPrice() << std::endl;

    return myStream.str();

}
std::string Item::itemTypeToString(){
    switch(itemType){
        case OBJECT:
            return "Object";
        case ARMOR:
            return "Armor";
        case WEAPON:
            return "Weapon";
        default:
            return "ERROR: ITEMTYPE IS UNDEFINED";
    }
}
Type Item::intToType(int type){
    switch(type){
        case 0:
            return WEAPON;
        case 1:
            return ARMOR;
        case 2:
            return OBJECT;
        default:
            return OBJECT;
    }
}
