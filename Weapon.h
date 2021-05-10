#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
#include "EntityList.h"

enum DMGType {FIRE, COLD, LIGHTNING, ACID, SLASHING, POISON};

class Weapon : public Item
{
    private:
        DMGType type; 
        int range;
    public:
        Weapon(){}
        //Parameterized Constructor
        Weapon(std::string name, std::string damage, double weight, int itemID, int price,  DMGType type, int range) : Item(name, damage, WEAPON, weight, itemID, price){
            this->type = type;
            this->range = range;
        }
        //Destructor
        ~Weapon(){}
        //Getters
        DMGType getDamageType() const{return type;}
        int getRange() const{return range;}
        
        //Helper Conversion Functions
        std::string typeToString(); //takes the objects DMGType and returns its string representation
        static DMGType intToType(int type); //takes an integer representing a DMGType and returns that DMGType
        static int dmgTypeToInt(DMGType dmgType); //takes in a dmgType and returns the int representation of said DMGType

        //print and string functions
        std::string to_string() override; //returns a user-friendly string representation of the Weapon's attributes
        std::string toExportString() override; //returns a exportable string representation of the Weapon's attributes
        void longPrint() override; //prints a user-friendly representation of the Weapon's attributes
        
        
        //Menu Functions
        static void CreateMenu(EntityList<Item*>* list); //prompts and gathers responses from user to create a new Weapon Entity and add it to the System's EntityLists
        void EditMenu() override; //prompts and gathers responses from user to edit existing Weapon object in the systems EntityList

    
};

#endif 