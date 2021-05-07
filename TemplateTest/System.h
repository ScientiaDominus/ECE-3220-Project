#ifndef SYSTEM_H
#define SYSTEM_H
#include "EntityList.h"
#include "Character.h"
#include "Item.h"
#include "Spell.h"


enum MenuModeType {CHARACTER, ITEM, SPELL};

class System{
    private:
        static System *instance; 
        EntityList<Item*>* itemList;
        EntityList<Character*>* characterList;
        EntityList<Spell*>* spellList;
        MenuModeType menuMode;
        std::string menuModeString;

    public:
        System();
        ~System();
        void StartMenu();
        template<typename E>
        void EntityMenu(EntityList<E*>* list);
        template<typename E>
        void ViewEditMenu(EntityList<E>* list);
        template<typename E>
        void SearchListMenu(EntityList<E>* list);
        void changeMenuMode(MenuModeType menuMode);
        template<typename T>
        void addEntity(MenuModeType entityType, T entity);

        EntityList<Item*>* getItemList(){return itemList;}
        EntityList<Spell*>* getSpellList(){return spellList;} 
        EntityList<Character*>* getCharacterList(){return characterList;}
        static System* getInstance(){
            if(!(instance)){
                instance = new System;
            }
            return instance;
        }
};



template<typename T>
void System::addEntity(MenuModeType entityType, T entity){
    switch(entityType){
        case CHARACTER:
            characterList->addEntity((Character*)entity);
            break;
        case ITEM:
            itemList->addEntity((Item*)entity);
            break;
        case SPELL:
            spellList->addEntity((Spell*)entity);
            break;
        default:
            break;
    }
}
#endif