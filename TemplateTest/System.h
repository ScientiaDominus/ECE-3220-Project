#include "EntityList.h"
#include "Item.h"

enum MenuModeType {CHARACTER, ITEM, SPELL};

class System{
    private:
        EntityList<Item*> itemList;
        //EntityList<Character*> characterList;
        //EntityList<Spell*> spellList;
        MenuModeType menuMode;
        std::string menuModeString;

    public:
        void StartMenu();
        template<typename E>
        void EntityMenu(EntityList<E*> list);
        template<typename E>
        void ViewEditMenu(EntityList<E> list);
        template<typename E>
        void SearchListMenu(EntityList<E> list);
        void changeMenuMode(MenuModeType menuMode);
        template<typename T>
        void addEntity(MenuModeType entityType, T entity);

        //Entity EditMenu();
        //CreateMenu();
};