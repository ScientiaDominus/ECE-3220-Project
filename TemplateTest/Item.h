#ifndef ITEM_H
#define ITEM_H
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Entity.h"

enum Type {WEAPON, ARMOR, OBJECT};

class Item : public Entity{
    private:
        std::string damage;
        Type itemType;
        double weight;
        int price;
    public:
        Item();
        Item(std::string name, std::string damage, Type itemType, double weight, int itemID, int price);
        ~Item();
        std::string getDamage() const{return damage;}
        Type getItemType() const{return itemType;}
        double getWeight() const{return weight;}
        int getPrice() const{return price;}

        std::string itemTypeToString();
        Type intToType(int type);
        std::string to_ShortString();
        
        virtual void longPrint();
        virtual std::string toExportString();
        virtual std::string to_string();

};


#endif