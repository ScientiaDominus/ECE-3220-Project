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

void Item::setDamage(std::string damage){this->damage = damage;}
void Item::setItemType(Type itemType){this->itemType = itemType;}
void Item::setWeight(double weight){this->weight = weight;}
void Item::setPrice(int price){this->price = price;}
std::string Item::getDamage() const{return damage;}
Type Item::getItemType() const{return itemType;}
double Item::getWeight() const{return weight;}
int Item::getPrice() const{return price;}

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
    std::cout << "\t1) Object" << std::endl;
    std::cout << "\t2) Weapon" << std::endl;
    std::cout << "\t3) Armor" << std::endl;
    std::cout << "\t4) Return" << std::endl;
    std::cout << "Your Selection: ";
    int response;
    std::cin >> response;
    switch(response){
        case 1:
            Item::ObjectCreateMenu(list);
            break;
        case 2:
            Weapon::CreateMenu(list);
            break;
        case 3:
            Armor::CreateMenu(list);
            break;
        case 4:
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
    std::getline(std::cin, name); //clears buffer
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

void Item::ObjectCreateMenu(EntityList<Item*>* list){
    std::string name;
    int ID = 0;
    std::string damage;
    double weight = 0;
    int price = 0;
    
    std::cout << "Please enter the Object's name: ";
    std::getline(std::cin, name);
    std::getline(std::cin, name);
    std::cout << "Please enter the Object's ID: ";
    std::cin >> ID;
    std::cout << "Please enter the damage description of your Object: "<< std::endl;
    std::getline(std::cin, damage);
    std::getline(std::cin, damage);
    std::cout << "Please enter your Object's weight: " << std::endl;
    std::cin >> weight;
    std::cout << "Please enter your Object's price" << std::endl;
    std::cin >> price;

    Item* temp = new Item(name, damage, OBJECT, weight, ID, price);
    list->addEntity(temp);
}
