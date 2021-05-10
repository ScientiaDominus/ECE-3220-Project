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
        //Parameterized Constructor
        Item(std::string name, std::string damage, Type itemType, double weight, int itemID, int price);
        //Destructor
        ~Item();
        //Getters and Setters
        void setDamage(std::string damage);
        void setItemType(Type itemType);
        void setWeight(double weight);
        void setPrice(int price);
        std::string getDamage() const;
        Type getItemType() const;
        double getWeight() const;
        int getPrice() const;

        static std::string itemTypeToConstantStyleString(Type itemType);
        std::string itemTypeToString();
        Type intToType(int type);
        std::string to_ShortString();
        
        
        static void ObjectCreateMenu(EntityList<Item*>* list);
        static void CreateMenu(EntityList<Item*>* list);
        virtual void EditMenu();
        virtual void longPrint();
        virtual std::string toExportString();
        virtual std::string to_string();

};


#endif