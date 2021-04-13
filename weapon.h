#include "item.h"

class weapon : public item
{
    public:
        weapon(std::string name, std::string damage, double weight, int itemID, int price, std::string damageType, int range) : item(name, damage, weight, itemID, price)
        {
            std::cout << "weapon Constructor called" << std::endl;
        }

    private:
        std::string damageType_; 
        int range_;
};