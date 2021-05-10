#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "EntityList.h"
#include <vector>

Item::Item(){}
Item::~Item(){}
Item::Item(std::string name, std::string damage, Type itemType, double weight, int itemID, int price){   
    setName(name);
    setID(itemID);
    this->damage = damage;
    this->itemType = itemType;
    this->weight = weight;
    this->price =  price;
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

    myStream << getID() << std::endl;
    myStream << getName() << std::endl;
    myStream << getDamage() << std::endl;
    myStream << getWeight() << std::endl;
    myStream << getPrice() << std::endl;
    myStream << itemTypeToConstantStyleString(getItemType());
    return myStream.str();

}
std::string Item::itemTypeToString(){
    switch(getItemType()){
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
void Item::longPrint(){
    std::cout << to_string();
}
std::string Item::itemTypeToConstantStyleString(Type itemType){
    switch(itemType){
        case OBJECT:
            return "OBJECT";
        case ARMOR:
            return "ARMOR";
        case WEAPON:
            return "WEAPON";
        default:
            return "UNSPECIFIED";
    }
}
void Item::CreateMenu(EntityList<Item*>* list){
    std::cout << "Welcome to the Item Create Menu! Please select which item you'd like to create" << std::endl;
    std::cout << "\t1) Weapon" << std::endl;
    std::cout << "\t2) Armor" << std::endl;
    std::cout << "\t3) Return" << std::endl;
    int response;
    std::cin >> response;
    switch(response){
        case 1:
            Weapon::CreateMenu(list);
            break;
        case 2:
            Armor::CreateMenu(list);
            break;
        case 3:
            return;
    }
}

void Item::EditMenu(){
    std::string name;
    std::string damage;
    double weight;
    int itemID;
    int price;
    std::cout << "Here is the items current information:\n" << to_string() << std::endl;
    std::cout << "Please enter the Item's name";
    std::getline(std::cin, name);
    std::cout << "Please enter the Item's damage";
    std::getline(std::cin, damage);
    std::cout << "Please enter the Item's weight";
    std::cin >> weight;
    std::cout << "Please enter the Item's ID";
    std::cin >> itemID;
    std::cout << "Please enter the Item's price";
    std::cin >> price;
    
    this->setName(name);
    this->setID(itemID);
    this->itemType = OBJECT;
    this->weight = weight;
    this->damage = damage;
    this->price = price;
}
