#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"
#include "EntityList.h"
#include "Entity.h"
#include <string>

enum ArmorType {LIGHT, MEDIUM, HEAVY};

class Armor : public Item
{   
    private:
        ArmorType armorType;
    public:
        Armor();
        //Parameterized Constructor
        Armor(std::string name, std::string damage, double weight, int itemID, int price,  ArmorType type);
        //Destructor
        ~Armor();

        //Getter
        ArmorType getArmorType() const;

        //Helper Conversion Functions
        static ArmorType intToType(int type); //Takes in integer and returns ArmorType corresponding to it.
        std::string typeToString(); //Takes in ArmorType and returns string representation.
        static int armorTypeToInt(ArmorType armorType); //Takes in ArmorType and returns corresponding integer.

        //inheritted from Item: String and Printing functions
        void longPrint() override; //prints user-friendly representation of Armor's attributes
        std::string toExportString() override; //returns exportable string representation of Armor object
        std::string to_string() override; //retuns user-friendly string representation of Armor's attributes

        //menu related functions
        static void CreateMenu(EntityList<Item*>* list); //prints prompts and gathers responses to create and add Armor object to the system EntityLists
        void EditMenu(); //prints prompts and gathers response to edit existing Armor in the system's EntityLists

};

#endif


