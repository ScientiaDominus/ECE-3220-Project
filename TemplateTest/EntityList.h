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
                (*i)->shortPrint();
            }
        }

        void addEntity(T entity){
            entityVector.push_back(entity);
        }
        void removeEntity(T entity){
            entityVector.erase(entity);
        }

        T searchForEntityByID(int ID){
            typename std::vector<T>::iterator i;
            for(i = entityVector.begin(); i < entityVector.end(); i++){
                if(ID == (*i)->getID()){
                    return *i;
                }   
            }
            return nullptr;
        }


        T searchForEntityByName(std::string name){
            typename std::vector<T>::iterator i;
            for(i = entityVector.begin(); i < entityVector.end(); i++){
                if(name.compare((*i)->getName())){
                    return *i;
                }    
            }
            return nullptr;
        }

        std::string getStringListOfIDs(){
            std::string stringListOfIDs = "List Start\n";
            typename std::vector<T>::iterator i;
            for(i = entityVector.begin(); i < entityVector.end(); i++){
                stringListOfIDs += std::to_string((*i)->getID()) + "\n";
              
            }
            stringListOfIDs = "List End\n";
            return stringListOfIDs;
        }

        std::vector<T> getVector(){
            return entityVector;
        }


};

#endif