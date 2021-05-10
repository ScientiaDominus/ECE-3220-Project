#ifndef SYSTEM_H
#define SYSTEM_H
#include "EntityList.h"
#include "Character.h"
#include "Item.h"
#include "Spell.h"


enum MenuModeType {CHARACTER, ITEM, SPELL};

class System{
    private:
        System(); //private constructor that is called by getInstance when an instance does not already exist
        static System *instance; 
        EntityList<Item*>* itemList;
        EntityList<Character*>* characterList;
        EntityList<Spell*>* spellList;
        MenuModeType menuMode;
        std::string menuModeString;

    public:
        //Destructor
        ~System();

        //Getter Functions for the EntityLists
        EntityList<Item*>* getItemList(){return itemList;}
        EntityList<Spell*>* getSpellList(){return spellList;} 
        EntityList<Character*>* getCharacterList(){return characterList;}

        //Menu Functions
        void StartMenu();
        template<typename E>
        void EntityMenu(EntityList<E*>* list); //presents the user with View/Edit/Create options for the Templated Entity type
        template<typename E>
        void ViewEditMenu(EntityList<E>* list); //presents the user with options to look up or edit existing Templated Entities in the system
        template<typename E>
        void SearchListMenu(EntityList<E>* list); //presents the users the options of searching the Systems EnityList by ID or by Name
        void changeMenuMode(MenuModeType menuMode); //changes the menuMode and menuModeString attributes of the class, attributes are used throughout templated menu structure
        
        template<typename T>
        void addEntity(MenuModeType entityType, T entity); //Templated function for adding entities to the appropriate list outside regular menu opperations

        //import and export operations and their helper functions
        void importEntityLists(); //pulls data from export files in the directory and populates the systems EntityLists
        Item* readItemFromFile(std::ifstream& file, int id); //reads and returns one Item object from the file pointer passed in
        Spell* readSpellFromFile(std::ifstream& file, int id); //reads and returns one Spell object from the file pointer passed in
        Character* readCharacterFromFile(std::ifstream& file, int id); //reads and returns one Character object from the file pointer passed in
        template<typename T>
        void exportEntityList(EntityList<T*>* list, std::string filename); //Templated export call that tells what file and which typed export function to call
        void exportDataBase(); //calls the exportDataBase functions for Characters, Items, and Spells
        
        //Singleton Instance getter, creates an instance if not already present, implimentation here due to static variable use in function
        static System* getInstance(){
            if(!(instance)){
                instance = new System;
            }
            return instance;
        }
};

//implimentation here due to errors in compilation because of specific templating in this function
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