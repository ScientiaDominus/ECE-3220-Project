#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"
#include "EntityList.h"
#include <string>

enum ArmorType {LIGHT, MEDIUM, HEAVY};

class Armor : public Item
{   
    private:
        ArmorType armorType;
    public:
        Armor(){}
        Armor(std::string name, std::string damage, double weight, int itemID, int price,  ArmorType type);
        ~Armor(){}

        static ArmorType intToType(int type);
        std::string typeToString();
        ArmorType getArmorType() const{return armorType;}
        
        void longPrint() override;
        std::string toExportString() override;
        std::string to_string() override;

        static void CreateMenu(EntityList<Item*> list);
        void EditMenu();


};

#endif


