#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity{
    private:
        std::string name;
        int ID;
    public:
        virtual void shortPrint() =0;
        void setName(std::string name){
            this->name = name;
        }
        void setID(int ID){
            this->ID = ID;
        }
        std::string getName(){return name;}
        int getID(){return ID;}
};

#endif