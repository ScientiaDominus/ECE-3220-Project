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
        Armor();
        Armor(std::string name, std::string damage, double weight, int itemID, int price,  ArmorType type);
        ~Armor();

        //helper functions
        static ArmorType intToType(int type);
        std::string typeToString();
        ArmorType getArmorType() const;
        
        //inheritted from Item: String and Printing functions
        void longPrint() override;
        std::string toExportString() override;
        std::string to_string() override;

        //menu related functions
        static void CreateMenu(EntityList<Item*>* list);
        void EditMenu();


};

#endif


