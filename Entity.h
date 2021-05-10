#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>

class Entity{
    private:
        std::string name;
        int ID;
    public:
        virtual ~Entity(){}

        //Getters and Setters
        void setName(std::string name);
        void setID(int ID);
        std::string getName() const;
        int getID() const;

        //prints Name and ID of the entity
        void shortPrint();
        
        //pure virtuals for child classes to impliment
        virtual void longPrint() =0; //intended to print user-friendly representation of child Entity objects attributes
        virtual std::string toExportString() =0; //intended to return exportable string representation of child Entity objects attributes
};

#endif