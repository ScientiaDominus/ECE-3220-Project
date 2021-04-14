#ifndef ITEM_H
#define ITEM_H
#include <stdlib.h>
#include <string>
#include <iostream>

class Item{
    public:

    private:
        std::string name_;
        std::string type_;
        std::string description_;
        int base_dmg_;
        int weight_;
        int price_;

};


#endif