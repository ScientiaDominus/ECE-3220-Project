#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

enum dmgType {FIRE, COLD, LIGHTNING, ACID, SLASHING, POISON};

class Weapon : public Item
{
    public:
        Weapon(std::string name, std::string damage, double weight, int itemID, int price,  dmgType type, int range) : Item(name, damage, WEAPON, weight, itemID, price)
        {
            std::cout << "Weapon Constructor called" << std::endl;
        }

        dmgType getDamageType_() const{return type_;}
        int getRange_() const{return range_;}

        void setRange_(int range);
        void setDamageType_(dmgType type);

    private:
        dmgType type_; 
        int range_;
};

#endif 