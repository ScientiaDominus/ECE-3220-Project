#ifndef ITEM_H
#define ITEM_H
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

enum Type {WEAPON, ARMOR, OBJECT};

class Item{
    public:
        Item(std::string name, std::string damage, Type itemType, double weight, int itemID, int price);

        std::string Name_() const{return name_;}
        std::string Damage_() const{return damage_;}
        Type ItemType_() const{return itemType_;}
        double Weight_() const{return weight_;}
        int ID_() const{return itemID_;}
        int Price_() const{return price_;}

        void setName_(std::string name);
        void setDamage_(std::string damage);
        void setItemType_(Type itemType);
        void setWeight_(double weight);
        void setID_(int ID);
        void setPrice_(int price);

        std::string itemTypeToString();

        virtual std::string to_string() = 0;
        virtual std::string toExportString() = 0;

        
        
    private:
        std::string name_;
        //std::string description_; might implement this later not needed but it would be nice to have in the program
        std::string damage_;
        Type itemType_;
        double weight_;
        int itemID_;
        int price_;

};


#endif