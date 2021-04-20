#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"

enum armorType {LIGHT, MEDIUM, HEAVY};

class Armor : public Item
{
    public:
        Armor(std::string name, std::string damage, double weight, int itemID, int price,  armorType type) : Item(name, damage, ARMOR, weight, itemID, price)
        {
            std::cout << "Armor Constructor Called" << std::endl;
        }

        void setArmorType(armorType type);
        armorType getArmorType() const{return type_;}
        std::string to_string() override;
    private:
        armorType type_;



};

#endif

