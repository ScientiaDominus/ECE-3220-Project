#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>

class Entity{
    private:
        std::string name;
        int ID;
    public:
        //getters and setters
        void setName(std::string name);
        void setID(int ID);
        std::string getName();
        int getID();

        //prints Name and ID of the entity
        void shortPrint();
        
        //pure virtuals for child classes to impliment
        virtual void longPrint() =0;
        virtual std::string toExportString() =0;
};

#endif