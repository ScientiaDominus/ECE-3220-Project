#ifndef ITEM_H
#define ITEM_H
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Entity.h"
#include "EntityList.h"

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
        void setDamage(std::string damage){this->damage = damage;}
        void setItemType(Type itemType){this->itemType = itemType;}
        void setWeight(double weight){this->weight = weight;}
        void setPrice(int price){this->price = price;}
        std::string getDamage() const{return damage;}
        Type getItemType() const{return itemType;}
        double getWeight() const{return weight;}
        int getPrice() const{return price;}

        std::string itemTypeToString();
        Type intToType(int type);
        std::string to_ShortString();
        
        
        //these are needed in each class
        static void CreateMenu(EntityList<Item*>* list);
        //virtual void EditMenu(EntityList<Item *>* list);
        virtual void longPrint();
        virtual std::string toExportString();
        virtual std::string to_string();

};


#endif