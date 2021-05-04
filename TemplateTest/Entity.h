#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>

class Entity{
    private:
        std::string name;
        int ID;
    public:
        virtual void longPrint() =0;
        void shortPrint(){
            std::cout << "Name: " << getName() << std::endl;
            std::cout << "ID: " << getID() << "\n" << std::endl;
        }
        void setName(std::string name){
            this->name = name;
        }
        void setID(int ID){
            this->ID = ID;
        }
        std::string getName(){return name;}
        int getID(){return ID;}
        virtual std::string toExportString() =0;
        

};

#endif