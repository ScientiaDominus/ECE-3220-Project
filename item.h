#ifndef ITEM_H
#define ITEM_H
#include <stdlib.h>
#include <string>
#include <iostream>

class item{
    public:
        item(std::string name, std::string damage, double weight, int itemID, int price);

        std::string getName() const{return name_;}
        std::string getDamage() const{return damage_;}
        
        double getWeight_() const{return weight_;}
        int getID_() const{return itemID_;}
        int getPrice_() const{return price_;}

        void setName_(std::string name);
        void setDamage_(std::string damage);
        void setWeight_(double weight);
        void setID_(int ID);
        void setPrice_(int price);

        
        
    private:
        std::string name_;
        //std::string description_; might implement this later not needed but it would be nice to have in the program
        std::string damage_;
        double weight_;
        int itemID_;
        int price_;

        
        

};


#endif