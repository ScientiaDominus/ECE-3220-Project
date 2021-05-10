#ifndef ENTITYLIST_H
#define ENTITYLIST_H
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

template<typename T>
class EntityList{
    private:
        std::vector<T>* entityVector;
    public:
        EntityList(){entityVector = new std::vector<T>();}
        ~EntityList(){
            delete entityVector;
        }
        void printList(){
            typename std::vector<T>::iterator i;
            for(i = entityVector->begin(); i < entityVector->end(); i++){
                (*i)->shortPrint();
            }
        }

        std::string exportListToString(){
            typename std::vector<T>::iterator i;
            std::stringstream outstring;
            for(i = entityVector->begin(); i < entityVector->end(); i++){
                outstring << (*i)->toExportString();
            }
            return outstring.str();
        }

        void addEntity(T entity){
            entityVector->push_back(entity);
        }
        
        T searchForEntityByID(int ID){
            typename std::vector<T>::iterator i;
            for(i = entityVector->begin(); i < entityVector->end(); i++){
                if(ID == (*i)->getID()){
                    return *i;
                }   
            }
            return nullptr;
        }


        T searchForEntityByName(std::string name){
            typename std::vector<T>::iterator i;
            for(i = entityVector->begin(); i < entityVector->end(); i++){
                if(name.compare((*i)->getName()) == 0){
                    return *i;
                }    
            }
            return nullptr;
        }

        std::string getStringListOfIDs(){
            std::stringstream outputStream;
            typename std::vector<T>::iterator i;
            for(i = entityVector->begin(); i < entityVector->end(); i++){
                outputStream << std::to_string((*i)->getID()) << std::endl;
            }
            return outputStream.str();
        }

        std::string getStringListOfNames(){
            std::stringstream outputStream;
            typename std::vector<T>::iterator i = entityVector->begin();
            if(i < entityVector->end()){
                outputStream << "\t-" << (*i)->getName();
            }
            for(i += 1; i < entityVector->end(); i++){
                outputStream << std::endl;
                outputStream << "\t-" << (*i)->getName();
            }
            return outputStream.str();
        }

        std::vector<T>* getVector(){
            return entityVector;
        }


};

#endif