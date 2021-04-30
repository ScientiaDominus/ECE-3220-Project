#include "EntityList.h"
#include "Item.h"

enum MenuModeType {CHARACTER, ITEM, SPELL};

class System{
    private:
        EntityList<Item> itemList;

        MenuModeType menuMode;
    public:
        void StartMenu(){
            std::cout << "Main Menu. Pick and Option Below" << std::endl;
            std::cout << "\t1) Item\n\tEverything Else) Exit" << std::endl;
            int response;
            std::cin >> response;
            switch (response)
            {
            case 1:
                EntityMenu<Item>(itemList);
                break;
            
            default:
            return;
                break;
            }
        }

        template<typename E>
        void EntityMenu(EntityList<E> list){
            std::cout << "Welcome to the Entity Menu" << std::endl;
            int response;
            std::cin >> response;
            switch (response)
            {
            case 1:
                std::cout << "Youve selected option 1!" << std::endl;
                break;
            case 2:
                std::cout << "Youve selected option 2" << std::endl;
            default:
                return;
                break;
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
};