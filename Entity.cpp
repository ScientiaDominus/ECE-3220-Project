#include "Entity.h"

void Entity::setName(std::string name){
    this->name = name;
}
void Entity::setID(int ID){
    this->ID = ID;
}
std::string Entity::getName() const {return name;}
int Entity::getID() const {return this->ID;}
void Entity::shortPrint(){
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "ID: " << getID() << "\n" << std::endl;
}
        