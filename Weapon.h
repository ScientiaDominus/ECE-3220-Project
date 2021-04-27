#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

enum dmgType {FIRE, COLD, LIGHTNING, ACID, SLASHING, POISON};

class Weapon : public Item
{
    public:
        Weapon(std::string name, std::string damage, double weight, int itemID, int price,  dmgType type, int range) : Item(name, damage, WEAPON, weight, itemID, price)
        {
            setDamageType_(type);
            setRange_(range);
            std::cout << "Weapon Constructor called" << std::endl;
        }

        dmgType DamageType_() const{return type_;}
        int Range_() const{return range_;}

        void setRange_(int range);
        void setDamageType_(dmgType type);
        std::string typeToString();
        std::string to_string() override;
        std::string toExportString() override;

    private:
        dmgType type_; 
        int range_;
};

#endif 