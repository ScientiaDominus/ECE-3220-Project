#include "Item.h"

class weapon : public Item
{
    public:
        weapon(std::string name, std::string damage, double weight, int itemID, int price, std::string damageType, int range) : Item(name, damage, weight, itemID, price)
        {
            std::cout << "weapon Constructor called" << std::endl;
        }

    private:
        std::string damageType_; 
        int range_;
};