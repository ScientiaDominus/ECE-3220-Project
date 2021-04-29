#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"

enum armorType {LIGHT, MEDIUM, HEAVY};

class Armor : public Item
{
    public:
        Armor();
        Armor(std::string name, std::string damage, double weight, int itemID, int price,  armorType type) : Item(name, damage, ARMOR, weight, itemID, price)
        {
            setArmorType(type);
            std::cout << "Armor Constructor Called" << std::endl;
        }
        ~Armor();

        void setArmorType(armorType type);
        void edit() override;
        armorType intToType(int type);
        std::string typeToString();
        armorType ArmorType() const{return type_;}
        std::string to_string() override;
        std::string toExportString() override;
    private:
        armorType type_;



};

#endif


