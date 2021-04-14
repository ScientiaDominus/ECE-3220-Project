#include "Item.h"

class Weapon : public Item
{
    public:
        Weapon(std::string name, std::string damage, double weight, int itemID, int price, std::string damageType, int range) : Item(name, damage, WEAPON, weight, itemID, price)
        {
            std::cout << "weapon Constructor called" << std::endl;
        }

    private:
        std::string damageType_; 
        int range_;
};