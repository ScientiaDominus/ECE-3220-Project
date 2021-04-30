#include "Entity.h"
#include <iostream>

class DifferentItem : public Entity{
    public:
        DifferentItem(){}
        DifferentItem(std::string name, int ID){
            setName(name);
            setID(ID);
        }
        void shortPrint() override{
            std::cout << getName() << "\n\t" << getID() << std::endl;
        }
    private:
};