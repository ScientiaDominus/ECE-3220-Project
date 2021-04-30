#include "EntityList.h"
#include "Item.h"

enum MenuModeType {CHARACTER, ITEM, SPELL};

class System{
    private:
        EntityList<Item> itemList;
        //EntityList<Character> characterList;
        //EntityList<Spell> spellList;
        MenuModeType menuMode;
        std::string menuModeString;

    public:
        void StartMenu(){
            std::cout << "Main Menu. Pick and Option Below" << std::endl;
            std::cout << "\t1) Character\n\t2) Item\n\t3) Spell\n\t4) Exit" << std::endl;
            int response;
            std::cin >> response;
            switch (response){
                // case 1:
                //     changeMenuMode(CHARACTER);
                //     EntityMenu<Item>(characterList);
                //     break;
                case 2:
                    changeMenuMode(ITEM);
                    EntityMenu<Item>(itemList);
                    break;
                // case 3:
                //     changeMenuMode(SPELL);
                //     EntityMenu<Item>(spellList);
                //     break;
            
                default:
                    return;
            }
        }

        template<typename E>
        void EntityMenu(EntityList<E> list){
            std::cout << "Welcome to the " << menuModeString << " Entity Menu" << std::endl;
            int response;
            std::cin >> response;
            switch (response){
                case 1:
                    std::cout << "Youve selected option 1!" << std::endl;
                    break;
                case 2:
                    std::cout << "Youve selected option 2" << std::endl;
                default:
                    return;
            }
        }
        // template<typename E>
        // void EntityMenu(EntityList<E> list){
        //     std::cout << "Welcome to the Menu, Pick an Option" << std::cout;
        //     int response;
        //     std::cin >> response;
        //     switch (response)
        //     {
        //     case 1:
        //         list.printList();
        //         break;
        //     case 2:
        //         ViewEditMenu(EntityList<E> list);
        //     default:
        //         return;
        //         break;
        //     }
        // }

        // template<typename E>
        // void ViewEditMenu(EntityList<E> list){
        //     std::cout << "Welcome to the Menu, Pick an Option" << std::cout;
        //     int response;
        //     std::cin >> response;
        //     switch (response)
        //     {
        //     case 1:
        //         list.printList();
        //         break;
        //     case 2:
        //         SearchListMenu(EntityList<E> list);
        //     default:
        //         return;
        //         break;
        //     }
        // }

        // template<typename E>
        // void SearchListMenu(EntityList<E> list){
        //     E selectedEntity;
            
        //     std::cout << "Welcome to the Menu, Pick an Option" << std::cout;
        //     int response;
        //     std::cin >> response;
        //     switch (response)
        //     {
        //     case 1:
        //         int ID;
        //         std::cout << "Enter the ID: ";
        //         std::cin >> ID;
        //         E = list.searchForEntityByID(ID);
        //         break;
        //     case 2:
        //         std::string name
        //         std::cout << "Enter the ID: ";
        //         std::cin >> ID;
        //         E = list.searchForEntityByName(name);
        //         break;
        //     default:
        //         return;
        //         break;
        //     }

        //     std::cout << "View or Edit?" << std::endl;
        // }

        void changeMenuMode(MenuModeType menuMode){
            this->menuMode = menuMode;
            switch (this->menuMode)
            {
                case CHARACTER:
                    menuModeString = "Character";
                    break;
                case ITEM:
                    menuModeString = "Item";
                    break;
                case SPELL:
                    menuModeString = "Spell";
                default:
                    menuModeString = "";
                    break;
            }
        }
};