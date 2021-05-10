#include "Weapon.h"
#include "EntityList.h"

std::string Weapon::to_string(){
    std::stringstream myStream;

    myStream << "NAME: " << getName() << std::endl; 
    myStream << "DAMAGE: " << getDamage() << std::endl;
    myStream << "DAMAGETYPE: " << typeToString() << std::endl;
    myStream << "RANGE: " << getRange() << std::endl;
    myStream << "ITEMTYPE: " << itemTypeToString() << std::endl;
    myStream << "WEIGHT: " << getWeight() << std::endl;
    myStream << "ID: " << getID() << std::endl;
    myStream << "PRICE: " << getPrice() << std::endl; 

    return myStream.str();
}

std::string Weapon::typeToString(){
    switch(type){
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

std::string Weapon::toExportString(){
    std::stringstream myStream;
    myStream << this->Item::toExportString();
    myStream << std::endl;
    myStream << dmgTypeToInt(getDamageType()) << std::endl;
    myStream << getRange();

    return myStream.str();
}
int Weapon::dmgTypeToInt(DMGType dmgType){
    switch(dmgType){
        case FIRE:
            return 0;
        case COLD:
            return 1;
        case LIGHTNING:
            return 2;
        case ACID:
            return 3;
        case SLASHING:
            return 4;
        case POISON:
            return 5;
        default:
            return 4;
    }
}
DMGType Weapon::intToType(int type){
    switch(type){
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

void Weapon::longPrint(){
    std::cout << to_string() << std::endl;
}

void Weapon::CreateMenu(EntityList<Item*>* list){
    std::string name;
    int ID = 0;
    std::string damage;
    //Type itemType = WEAPON;
    double weight = 0;
    int price = 0;
    int dmgTypeInt = 0;
    DMGType dmgType = SLASHING;
    int range = 0;
    
    std::cout << "Please enter the Weapon's name: ";
    std::getline(std::cin, name); //clears buffer
    std::getline(std::cin, name);
    std::cout << "Please enter the Weapon's ID: ";
    std::cin >> ID;
    std::cout << "Please enter the damage description of your Weapon: "<< std::endl;
    std::getline(std::cin, damage); //clears buffer
    std::getline(std::cin, damage);
    std::cout << "Please enter your Weapon's weight: " << std::endl;
    std::cin >> weight;
    std::cout << "Please enter your Weapon's price" << std::endl;
    std::cin >> price;
    std::cout << "Please enter the number corresponding to your desired Weapon's Damage Type:" << std::endl;
    std::cout << "\t1) Fire" << std::endl;
    std::cout << "\t2) Cold" << std::endl;
    std::cout << "\t3) Lightning" << std::endl;
    std::cout << "\t4) Acid" << std::endl;
    std::cout << "\t5) Slashing" << std::endl;
    std::cout << "\t6) Poison" << std::endl;
    std::cout << "\t7) Slashing" << std::endl;
    std::cin >> dmgTypeInt;
    dmgType = intToType(dmgTypeInt);
    std::cout << "Please enter your Weapon's range" << std::endl;
    std::cin >> range;

    Weapon* temp = new Weapon(name, damage, weight, ID, price, dmgType, range);
    list->addEntity(temp);
}

void Weapon::EditMenu(){
    std::string name;
    std::string damage;
    double weight;
    int itemID;
    int price;
    int dmgTypeInt;
    int range;
    std::cout << "Here is the Weapon's current information:\n" << to_string() << std::endl;
    std::cout << "Please enter the Weapon's name";
    std::getline(std::cin, name); //clears buffer
    std::getline(std::cin, name);
    std::cout << "Please enter the Weapon's damage";
    std::getline(std::cin, damage); //clears buffer
    std::cout << "Please enter the Weapon's weight";
    std::cin >> weight;
    std::cout << "Please enter the Weapon's ID";
    std::cin >> itemID;
    std::cout << "Please enter the Weapon's price";
    std::cin >> price;
    std::cout << "Please enter the number corresponding to your desired Weapon's Damage Type:" << std::endl;
    std::cout << "\t0) Fire" << std::endl;
    std::cout << "\t1) Cold" << std::endl;
    std::cout << "\t2) Lightning" << std::endl;
    std::cout << "\t3) Acid" << std::endl;
    std::cout << "\t4) Slashing" << std::endl;
    std::cout << "\t5) Poison" << std::endl;
    std::cout << "\t6) Slashing" << std::endl;
    std::cin >> dmgTypeInt;
    std::cout << "Please enter your Weapon's range" << std::endl;
    std::cin >> range;

    this->setName(name);
    this->setID(itemID);
    this->setItemType(WEAPON);
    this->setWeight(weight);
    this->setDamage(damage);
    this->setPrice(price);
    this->type = intToType(dmgTypeInt);
    this->range = range;
}