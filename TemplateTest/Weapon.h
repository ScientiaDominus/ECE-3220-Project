#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

enum DMGType {FIRE, COLD, LIGHTNING, ACID, SLASHING, POISON};

class Weapon : public Item
{
    private:
        DMGType type; 
        int range;
    public:
        Weapon(){}
        Weapon(std::string name, std::string damage, double weight, int itemID, int price,  DMGType type, int range) : Item(name, damage, WEAPON, weight, itemID, price){
            this->type = type;
            this->range = range;
        }
        ~Weapon(){}

        DMGType getDamageType() const{return type;}
        int getRange() const{return range;}

        std::string typeToString();
        DMGType intToType(int type);

        std::string to_string() override;
        std::string toExportString() override;
        void longPrint() override;


    
};

#endif 