#include "EntityList.h"
#include "Character.h"
#include "Item.h"


enum MenuModeType {CHARACTER, ITEM, SPELL};

class System{
    private:
        EntityList<Item*>* itemList;
        EntityList<Character*> characterList;
        //EntityList<Spell*> spellList;
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

        //Entity EditMenu();
        //CreateMenu();
};

template<typename T>
void System::addEntity(MenuModeType entityType, T entity){
    switch(entityType){
        case CHARACTER:
            //characterList->addEntity(entity);
            break;
        case ITEM:
            itemList->addEntity(entity);
            break;
        case SPELL:
            //spellList->addEntity(entity);
            break;
        default:
            break;
    }
}