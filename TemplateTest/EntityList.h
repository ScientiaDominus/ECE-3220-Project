#ifndef ENTITYLIST_H
#define ENTITYLIST_H
#include <vector>
#include <string>

template<typename T>
class EntityList{
    private:
        std::vector<T> entityVector;
    public:
        EntityList(){}
        
        void printList(){
            typename std::vector<T>::iterator i;
            for(i = entityVector.begin(); i < entityVector.end(); i++){
                i->longPrint();  
            }
        }

        void addEntity(T entity){
            entityVector.push_back(entity);
        }

        T searchForEntityByID(int ID){
            typename std::vector<T>::iterator i;
            for(i = entityVector.begin(); i < entityVector.end(); i++){
                if(ID == i->getID()){
                    return *i;
                }   
            }
            return nullptr;
        }

        T searchForEntityByName(std::string name){
            typename std::vector<T>::iterator i;
            for(i = entityVector.begin(); i < entityVector.end(); i++){
                if(name.compare(i->getName())){
                    return *i;
                }    
            }
            return nullptr;
        }


};

#endif