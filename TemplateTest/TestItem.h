#include "Entity.h"
#include <iostream>

class TestItem : public Entity{
    public:
        TestItem(){}
        TestItem(std::string name, int ID){
            setName(name);
            setID(ID);
        }
        void shortPrint() override{
            std::cout << getName() << std::endl;
        }
    private:
};