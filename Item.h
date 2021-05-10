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

        //Helper Conversion Functions
        static std::string itemTypeToConstantStyleString(Type itemType); //returns CAPITALIZED string representation of Type enum 
        std::string itemTypeToString(); //takes in integer representation of itemType and returns string representation of the itemType
        Type intToType(int type); //takes in an integer representation of itemType and returns the Type enum of that type
        
        //Menu Functions
        static void ObjectCreateMenu(EntityList<Item*>* list); //prompts and gathers response from user to create and add an Object Item to the System's EntityList
        static void CreateMenu(EntityList<Item*>* list); //Menu that prompts and redirect users to the specific item type menu they are wishing to create an item for
        virtual void EditMenu();
        
        //Virtual Functions inherited from Entity: Printing and String functions
        virtual void longPrint(); //prints a user-friendly representation of an object items attributes
        virtual std::string toExportString(); //returns an exportable string representation of the Item object
        virtual std::string to_string(); //returns a user-friendly representation of an object items attributes

};


#endif